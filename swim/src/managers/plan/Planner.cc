#include "Planner.h"
#include "managers/analysis/UtilityScorer.h"
#include "managers/execution/AllTactics.h"


using namespace std;
using namespace omnetpp;

Define_Module(Planner);

Tactic* Planner::Plan() {
    
    MacroTactic* pMacroTactic = new MacroTactic;
    Model* pModel = getModel(); 

    pMacroOption = check_and_cast<MacroOption*>(
                getParentModule()->getSubmodule("macroOption")); 
    pOptions = pMacroOption->getOptions();
    Option * bestOption;
    double bestUtility =0;
    for (OptionList::iterator option = pOptions.begin(); option != pOptions.end(); ++option) {
        std::vector< std::tuple<std::string, double> > qualityAttributes = (*option)->getQualityAttributes();
        for (std::vector< std::tuple<std::string, double> >::iterator attribute = qualityAttributes.begin() ; attribute != qualityAttributes.end(); ++attribute){
            if(get<0>(*attribute) == "utility"){
                if(get<1>(*attribute)>=bestUtility)bestOption = (*option);
            }
        }
    }
    
    std::cout <<bestOption->getDimmer() <<std::endl;

    int currentServer = pModel->getActiveServers();
    double currentDimmer = pModel->getDimmerFactor();
    bool isServerBooting = pModel->getServers() > pModel->getActiveServers();

    if(!isServerBooting
                && currentServer > bestOption->getServerNum()){
        for(int i = 0; i < currentServer - bestOption->getServerNum() ; i++){
                pMacroTactic->addTactic(new RemoveServerTactic);
        }
    }else if(!isServerBooting
                && currentServer < bestOption->getServerNum()){
        for(int i = 0; i < bestOption->getServerNum() - currentServer; i++){
                pMacroTactic->addTactic(new AddServerTactic);
        }
    }

    if(currentDimmer != bestOption->getDimmer())pMacroTactic->addTactic(new SetDimmerTactic(bestOption->getDimmer()));

    return pMacroTactic;
}
