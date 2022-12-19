#include <managers/analysis/BaseAnalyser.h>
#include "managers/ModulePriorities.h"
#include "boost/date_time/posix_time/posix_time.hpp"
#include <iostream>
#include "managers/monitor/SimpleMonitor.h"

using namespace boost::posix_time;
using namespace std;
using namespace omnetpp;


const char* BaseAnalyser::SIG_ANALYSIS_TIME = "analysisTime";

BaseAnalyser::BaseAnalyser() :
        periodEvent(nullptr), analysisCompleteEvent(nullptr){}

void BaseAnalyser::initialize(int stage)
{
    if (stage == 0) {
        pModel = check_and_cast<Model*> (getParentModule()->getSubmodule("model"));

        analysisTimeSignal = registerSignal(SIG_ANALYSIS_TIME);

    } else {
        /*
        // Create the event object we'll use for timing -- just any ordinary message.
        periodEvent = new cMessage("analyserPeriod");
        periodEvent->setSchedulingPriority(ANLYSER_PRIO);

        analysisCompleteEvent = new cMessage("analysisDecisionComplete");
        analysisCompleteEvent->setSchedulingPriority(ANLYSER_PRIO);

        // start adaptation half way through the warmup period
        double adaptationWarmup = ceil(
                    0.5 * getSimulation()->getWarmupPeriod().dbl()
                            / pModel->getEvaluationPeriod())
                * pModel->getEvaluationPeriod();

        scheduleAt(adaptationWarmup + pModel->getEvaluationPeriod(), periodEvent);
        */
    }
}

void BaseAnalyser::analysisComplete() {
}


BaseAnalyser::~BaseAnalyser() {
    cancelAndDelete(periodEvent);
    cancelAndDelete(analysisCompleteEvent);
}
