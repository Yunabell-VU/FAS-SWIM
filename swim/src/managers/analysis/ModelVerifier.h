#ifndef __MODELVERIFIER_H_
#define __MODELVERIFIER_H_

#include <omnetpp.h>
#include <fdeep/fdeep.hpp>
#include <iostream>
#include <tuple>
#include <vector>
#include "MacroOption.h"
#include "Option.h"
#include "UtilityScorer.h"


#define RT_CO omnetpp::getSimulation()->getSystemModule()->par("responseTimeCoefficient").doubleValue()
#define SERVER_COST_CO omnetpp::getSimulation()->getSystemModule()->par("serverCostCoefficient").doubleValue()
#define REVENUE_CO omnetpp::getSimulation()->getSystemModule()->par("revenueCoefficient").doubleValue()
#define NOR_REVENUE_CO omnetpp::getSimulation()->getSystemModule()->par("normalRevenueCoefficient").doubleValue()
#define OPT_REVENUE_CO omnetpp::getSimulation()->getSystemModule()->par("optRevenueCoefficient").doubleValue()
#define RT_THRESHOLD omnetpp::getSimulation()->getSystemModule()->par("responseTimeThreshold").doubleValue()

/*
 * MAX_SERVICE_RATE is the max number of requests/sec a single server can
 * process with normal service.
 */
#define MAX_SERVICE_RATE omnetpp::getSimulation()->getSystemModule()->par("maxServiceRate").doubleValue()

/**
 * Adapatation Option Quality Model Verifier
 */
class ModelVerifier: public omnetpp::cSimpleModule{

    protected:
        typedef std::list<Option*> OptionList;

        Model* pModel;
    public:

        void verifyAdaptationOptions(MacroOption * macroOption);
        void writeOptionQuality(int serverNum,double responseTime, double dimmer, double arrivalRate,Option* option);
        double predictResponseTime(int serverNum, double dimmer, double arrivalRate);

        void initialize(int stage);

        ModelVerifier();
        virtual ~ModelVerifier();

        double getAccruedUtility(int serverNum, double responseTime, double dimmer,double arrivalRate, Model * model);
        
};

#endif
