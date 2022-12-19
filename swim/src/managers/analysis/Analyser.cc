#include "Analyser.h"


Define_Module(Analyser);

using namespace std;
using namespace omnetpp;


Analyser::Analyser(){
}


const char* BaseAnalyser::SIG_ANALYSIS_DONE = "analysisDone";

void Analyser::initialize(int stage){
    if(stage == 1){
    

    // Reigster emit signal 
    analysisDoneSignal = registerSignal(SIG_ANALYSIS_DONE);
    
    // Register subscribe signal
    analysisEvaluationSignal = registerSignal(SimpleMonitor::SIG_ANALYSIS_EVALUATION);
    getSimulation()->getSystemModule()->subscribe(analysisEvaluationSignal, this);


    pServerLowerLimit = par("serverLowerLimit"); 
    pServerUpperLimit = par("serverUpperLimit"); 
    pDimmerLowerLimit = par("dimmerLowerLimit");
    pDimmerUpperLimit = par("dimmerUpperLimit");
    pServerStep = par("serverStep");
    pDimmerStep = par("dimmerStep");
        
    configureQualityModel();
    }
}


bool Analyser::evaluate(){
    configureAdaptationOption();
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
    Option * op = new Option();
    for(int server = pServerLowerLimit; server <= pServerUpperLimit ;server+=pServerStep){
        for(double dimmer = pDimmerLowerLimit; dimmer <= pDimmerUpperLimit; dimmer+=pDimmerStep){
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
