#include "Analyser.h"


Define_Module(Analyser);

using namespace std;
using namespace omnetpp;


Analyser::Analyser(){
}


const char* BaseAnalyser::SIG_ANALYSIS_DONE = "analysisDone";

void Analyser::initialize(int stage){
    if(stage == 1){
    
    pModelVerifier = check_and_cast<ModelVerifier*>(
                getParentModule()->getSubmodule("modelVerifier"));

    // Reigster emit signal 
    analysisDoneSignal = registerSignal(SIG_ANALYSIS_DONE);
    
    // Register subscribe signal
    analysisEvaluationSignal = registerSignal(SimpleMonitor::SIG_ANALYSIS_EVALUATION);
    getSimulation()->getSystemModule()->subscribe(analysisEvaluationSignal, this);


    pServerLowerLimit = getSimulation()->getSystemModule()->par("serverLowerLimit"); 
    pServerUpperLimit = getSimulation()->getSystemModule()->par("serverUpperLimit"); 
    pDimmerLowerLimit = getSimulation()->getSystemModule()->par("dimmerLowerLimit");
    pDimmerUpperLimit = getSimulation()->getSystemModule()->par("dimmerUpperLimit");
    pServerStep = getSimulation()->getSystemModule()->par("serverStep");
    pDimmerStep = getSimulation()->getSystemModule()->par("dimmerStep");
        
    configureQualityModel();
    configureAdaptationOption();
    }
}


bool Analyser::evaluate(){
    pModelVerifier->verifyAdaptationOptions(pMacroOption);
    analysisComplete();
}


void Analyser::readGoals(){
    pAdaptationGoal = check_and_cast<AdaptationGoal*>(
                getParentModule()->getSubmodule("adaptationGoal"));
}

void Analyser::configureQualityModel(){
    pQualityModel = check_and_cast<QualityModel*>(
                getParentModule()->getSubmodule("qualityModel"));
    pMacroOption = check_and_cast<MacroOption*>(
                getParentModule()->getSubmodule("macroOption")); 
    readGoals();
    pQualityModel->configureQualityModel(pAdaptationGoal);
}

void Analyser::configureAdaptationOption(){
    for(int server = pServerLowerLimit; server <= pServerUpperLimit ;server+=pServerStep){
        for(double dimmer = pDimmerLowerLimit; dimmer <= pDimmerUpperLimit; dimmer+=pDimmerStep){
            Option * op = new Option();
            op->configureQualityAttribute(pQualityModel);
            op->setDimmer(dimmer);
            op->setServerNum(server);
            pMacroOption->addOption(op);
        }
    }
}

void Analyser::analysisComplete() {
    emit(analysisDoneSignal,true);
}


void Analyser::receiveSignal(cComponent *source, simsignal_t signalID,
        bool value, cObject *details) {
    evaluate();
}


Analyser::~Analyser(){
    
}
