#ifndef __OPTION_H_
#define __OPTION_H_

#include <iostream>
#include <tuple>
#include <vector>
#include "QualityModel.h"

/**
 * Adapatation Option 
 */
class Option{

    protected:
        std::vector< std::tuple<std::string, double> > pQualityAttributes;
        int pServerNum;
        double pDimmer;

    public:

        void addQualityModel(std::tuple<std::string, double> pQualityAttribute);

        std::vector< std::tuple<std::string, double> > getQualityAttributes();

        void configureQualityAttribute(QualityModel * pQualityModel);

        void setServerNum(int serverNum);
        void setDimmer(double dimmer);

        int getServerNum();
        double getDimmer();

        Option();
        virtual ~Option();
        
};

#endif
