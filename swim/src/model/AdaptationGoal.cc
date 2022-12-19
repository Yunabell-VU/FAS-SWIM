#include "AdaptationGoal.h"

using namespace std;

Define_Module(AdaptationGoal);

AdaptationGoal::AdaptationGoal(){
}
AdaptationGoal::~AdaptationGoal(){

}

void AdaptationGoal::initialize(int stage){
    if(stage == 0){
        allowedResponseTime = par("allowedResponseTime");
        serverCost = par("serverCost");
        optRevenue = par("optRevenue");
        utility = par("utility");

        addAdaptationGoal("allowedResponseTime",allowedResponseTime);
        addAdaptationGoal("serverCost",serverCost);
        addAdaptationGoal("optRevenue",optRevenue);
        addAdaptationGoal("utility",utility);

    }
}

void AdaptationGoal::addAdaptationGoal(string key,double value){
    adaptationGoals.push_back(tuple<string,double>(key,value));
};


std::vector< std::tuple<std::string, double> > AdaptationGoal::getAdaptationGoals(){
    return adaptationGoals;
};