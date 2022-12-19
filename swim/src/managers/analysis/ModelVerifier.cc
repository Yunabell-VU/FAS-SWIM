#include "ModelVerifier.h"

Define_Module(ModelVerifier);

using namespace std;
using namespace omnetpp;

ModelVerifier::ModelVerifier(){

}

void ModelVerifier::initialize(int stage){
    if(stage == 1){
        pModel = check_and_cast<Model*>(
                getParentModule()->getSubmodule("model"));
    }
}

void ModelVerifier::verifyAdaptationOptions(MacroOption * macroOption){

    double reponseTime;
    double serverCost;
    double optRevenue;
    double utility; 
    OptionList options = macroOption->getOptions();
    for (OptionList::iterator option = options.begin(); option != options.end(); ++option) {
        reponseTime = predictResponseTime((*option)->getServerNum(),(*option)->getDimmer(),pModel->getEnvironmentModel().getArrivalMean());
        writeOptionQuality((*option)->getServerNum(),reponseTime,(*option)->getDimmer(),pModel->getEnvironmentModel().getArrivalMean(),*option);
    }




}

// ML Function
double ModelVerifier::predictResponseTime(int serverNum, double dimmer, double arrivalRate){
    return 0;
}


void ModelVerifier::writeOptionQuality(int serverNum,double responseTime, double dimmer, double arrivalRate,Option* option){
    // normalThroughPut = content without opt content , optThroughPut = content with opt content.
    double normalThroughPut,optThroughPut;
    double RT_PRE = 0;
    double SERVER_PRE = 0;
    double REVENUE_PRE = 0;


    double RT_DIFFERENCR = (RT_THRESHOLD - responseTime);
    if(RT_DIFFERENCR <= 0){
        RT_PRE = 1;
    }else if(0<RT_DIFFERENCR<=1){
        RT_PRE = 0.5;
    }else if(1<RT_DIFFERENCR<=4){
        RT_PRE = 0.2;
    }else{
        RT_PRE = 0;
    }

    SERVER_PRE = 1 - (serverNum/pModel->getMaxServers());

    normalThroughPut = arrivalRate * (1-dimmer);
    optThroughPut = arrivalRate * dimmer;

    double maxThroughput = pModel->getMaxServers() * MAX_SERVICE_RATE;
    REVENUE_PRE = (normalThroughPut * NOR_REVENUE_CO + optThroughPut * OPT_REVENUE_CO) / maxThroughput * NOR_REVENUE_CO;

    double utility = RT_PRE * RT_CO + SERVER_PRE * SERVER_COST_CO + REVENUE_PRE * REVENUE_CO;
    
    option->setQualityAttribute("allowedResponseTime",responseTime);
    option->setQualityAttribute("serverCost",SERVER_PRE * SERVER_COST_CO);
    option->setQualityAttribute("optRevenue",REVENUE_PRE * REVENUE_CO);
    option->setQualityAttribute("utility",utility);
    
}


ModelVerifier::~ModelVerifier(){
    
}
