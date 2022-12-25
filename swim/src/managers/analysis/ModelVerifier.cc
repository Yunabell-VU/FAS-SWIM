#include "ModelVerifier.h"

Define_Module(ModelVerifier);

using namespace std;
using namespace omnetpp;

ModelVerifier::ModelVerifier()
{
}

void ModelVerifier::initialize(int stage)
{
    std::cout << " max server before: " << pModel->getMaxServers() << std::endl;
    if (stage == 0)
    {
        pModel = check_and_cast<Model *>(
            getParentModule()->getSubmodule("model"));
    }
    std::cout << " max server after: " << pModel->getMaxServers() << std::endl;
}

void ModelVerifier::verifyAdaptationOptions(MacroOption *macroOption)
{

    double reponseTime;
    double serverCost;
    double optRevenue;
    double utility;
    OptionList options = macroOption->getOptions();
    for (OptionList::iterator option = options.begin(); option != options.end(); ++option)
    {
        reponseTime = predictResponseTime((*option)->getServerNum(), (*option)->getDimmer(), pModel->getEnvironmentModel().getArrivalMean());
        writeOptionQuality((*option)->getServerNum(), reponseTime, (*option)->getDimmer(), pModel->getEnvironmentModel().getArrivalMean(), *option);
    }
}

// ML Function
double ModelVerifier::predictResponseTime(int serverNum, double dimmer, double arrivalRate)
{
    // Example path
    // Need to change to the local absolute path of fdeep_model.json
    // const auto model = fdeep::load_model("/Users/yunabell/Desktop/FAS-SWIM/swim/src/managers/analysis/fdeep_model.json");
    // const auto result = model.predict(
    //     {fdeep::tensor(fdeep::tensor_shape(static_cast<std::size_t>(4)),
    //                    std::vector<float>{1, 2, 3, 4})});
    // std::cout << fdeep::show_tensors(result) << std::endl;
    float r = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 2));
    return r;
}

void ModelVerifier::writeOptionQuality(int serverNum, double responseTime, double dimmer, double arrivalRate, Option *option)
{
    // normalThroughPut = content without opt content , optThroughPut = content with opt content.
    double normalThroughPut, optThroughPut;
    double RT_PRE = 0;
    double SERVER_PRE = 0;
    double REVENUE_PRE = 0;

    double RT_DIFFERENCR = (responseTime - RT_THRESHOLD);
    if (RT_DIFFERENCR <= 0)
    {
        RT_PRE = 1;
    }
    else if (0 < RT_DIFFERENCR && RT_DIFFERENCR <= 1)
    {
        RT_PRE = 0.5;
    }
    else if (1 < RT_DIFFERENCR && RT_DIFFERENCR <= 4)
    {
        RT_PRE = 0.2;
    }
    else
    {
        RT_PRE = 0;
    }

    SERVER_PRE = 1 - (serverNum / pModel->getMaxServers());

    normalThroughPut = arrivalRate * (1 - dimmer);
    optThroughPut = arrivalRate * dimmer;

    double maxThroughput = pModel->getMaxServers() * MAX_SERVICE_RATE;
    REVENUE_PRE = (normalThroughPut * NOR_REVENUE_CO + optThroughPut * OPT_REVENUE_CO) / maxThroughput * NOR_REVENUE_CO;

    double utility = RT_PRE * RT_CO + SERVER_PRE * SERVER_COST_CO + REVENUE_PRE * REVENUE_CO;

    // std::cout << "Server Number: " << serverNum << " max server: " << pModel->getMaxServers() << std::endl;
    // // std::cout << "response time: " << RT_PRE << std::endl;

    // std::cout << "utility Verified: " << utility << std::endl;

    option->setQualityAttribute("allowedResponseTime", responseTime);
    option->setQualityAttribute("serverCost", SERVER_PRE * SERVER_COST_CO);
    option->setQualityAttribute("optRevenue", REVENUE_PRE * REVENUE_CO);
    option->setQualityAttribute("utility", utility);
}

ModelVerifier::~ModelVerifier()
{
}
