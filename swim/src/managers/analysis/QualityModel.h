#ifndef __QUALITYMODEL_H_
#define __QUALITYMODEL_H_


#include <omnetpp.h>
#include <iostream>
#include <tuple>
#include <vector>
#include "model/AdaptationGoal.h"

/**
 * Adapatation Option Quality Model
 */
class QualityModel: public omnetpp::cSimpleModule{

    protected:
        std::vector< std::tuple<std::string, double> > qualityAttributes;

    public:

        void addQualityModel(std::tuple<std::string, double> pQualityAttribute);

        std::vector< std::tuple<std::string, double> > getQualityAttributes();

        void configureQualityModel(AdaptationGoal *pAdaptationGoal);


        QualityModel();
        virtual ~QualityModel();
        
};

#endif
