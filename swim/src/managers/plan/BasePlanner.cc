#include "BasePlanner.h"
#include "managers/ModulePriorities.h"
#include "boost/date_time/posix_time/posix_time.hpp"
#include <iostream>

using namespace boost::posix_time;
using namespace omnetpp;

BasePlanner::BasePlanner() :decisionCompleteEvent(nullptr),
        pTactic(nullptr) {}

void BasePlanner::initialize(int stage)
{
    if (stage == 0) {
        pModel = check_and_cast<Model*> (getParentModule()->getSubmodule("model"));
        decisionTimeSignal = registerSignal("decisionTime");
        
        // Subscribe 
        analysisDoneSignal = registerSignal(BaseAnalyser::SIG_ANALYSIS_DONE);
        getSimulation()->getSystemModule()->subscribe(analysisDoneSignal, this);
    } else {

        // Create the event object we'll use for timing -- when decision completes.
        decisionCompleteEvent = new cMessage("adaptDecisionComplete");
        decisionCompleteEvent->setSchedulingPriority(PLANNER_PRIO);

    }
    
}

void BasePlanner::decisionComplete() {
    if (pTactic) {
        if (!pTactic->isEmpty()) {
            std::cout << "Planner simtime=" << simTime() << " tactic=" << *pTactic << std::endl;
            ExecutionManager* pExecMgr = check_and_cast<ExecutionManager*> (getParentModule()->getSubmodule("executionManager"));
            pTactic->execute(pExecMgr);
        }
        delete pTactic;
        pTactic = nullptr;
    }
}

void BasePlanner::handleMessage(cMessage *msg)
{
    if (msg == decisionCompleteEvent) {
        decisionComplete();
    }
    /*
    if (msg == periodEvent) {
        if (decisionCompleteEvent->isScheduled()) {
            std::cout << "Planner simtime=" << simTime() << " skipping decision" << std::endl;
        } else {
            if (par("simulatePlanDelay")) {
                scheduleAt(simTime() + decisionTime / 1000, decisionCompleteEvent);
            } else {
                decisionComplete();
            }
        }
        scheduleAt(simTime() + pModel->getEvaluationPeriod(), periodEvent);
    } else if (msg == decisionCompleteEvent) {
        decisionComplete();
    }*/
}

BasePlanner::~BasePlanner() {
    cancelAndDelete(decisionCompleteEvent);
    if (pTactic) delete(pTactic);
}

void BasePlanner::receiveSignal(cComponent *source, simsignal_t signalID,
        bool value, cObject *details) {
        if (decisionCompleteEvent->isScheduled()) {
            std::cout << "Planner simtime=" << simTime() << " skipping decision" << std::endl;
        } else {
            assert(pTactic == nullptr);
            ptime startTime = microsec_clock::local_time();
            pTactic = Plan();
            double decisionTime = (double) (microsec_clock::local_time() - startTime).total_milliseconds();
            if (par("simulatePlanDelay")) {
                scheduleAt(simTime() + decisionTime / 1000, decisionCompleteEvent);
            } else {
                decisionComplete();
            }
        }
       
}
