#ifndef __PLASASIM_ANALYSER_H_
#define __PLASASIM_ANALYSER_H_


#include <omnetpp.h>
#include <iostream>
#include "BaseAnalyser.h"
#include <vector>
#include "model/AdaptationGoal.h"
#include "QualityModel.h"
#include "managers/monitor/SimpleMonitor.h"
#include "MacroOption.h"
#include "Option.h"

/**
 * Adaptation Analyser
 */
class Analyser : public BaseAnalyser,omnetpp::cListener{
    
    omnetpp::simsignal_t analysisEvaluationSignal;

    // Emit signal
    omnetpp::simsignal_t analysisDoneSignal;


    protected:
        virtual bool evaluate();
        AdaptationGoal * pAdaptationGoal;
        QualityModel * pQualityModel;
        MacroOption * pMacroOption;
        void readGoals();
        void readModels();

        int pServerLowerLimit; 
        int pServerUpperLimit; 
        double pDimmerLowerLimit;
        double pDimmerUpperLimit;
        int pServerStep;
        double pDimmerStep;

        void initialize(int stage);
        void analysisComplete();
    public:
        Analyser();
        virtual ~Analyser();

        void configureQualityModel();
        void configureAdaptationOption();

        void receiveSignal(omnetpp::cComponent *source, omnetpp::simsignal_t signalID, bool value, cObject *details) override;

};

#endif
