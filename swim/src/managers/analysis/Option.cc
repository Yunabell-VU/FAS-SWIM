#include "Option.h"


Option::Option(){

}

void Option::configureQualityAttribute(QualityModel * pQualityModel){
    std::vector< std::tuple<std::string, double> > qualityAttributes = pQualityModel->getQualityAttributes();
    for (std::vector< std::tuple<std::string, double> >::iterator it = qualityAttributes.begin() ; it != qualityAttributes.end(); ++it){
        pQualityAttributes.push_back(*it);
    }
}

std::vector< std::tuple<std::string, double> > Option::getQualityAttributes(){
    return pQualityAttributes;
}


void Option::setServerNum(int serverNum){
    pServerNum = serverNum;
}

void Option::setDimmer(double Dimmer){
    pDimmer = Dimmer;
}

int Option::getServerNum(){
    return pServerNum;
}

double Option::getDimmer(){
    return pDimmer;
}

Option::~Option(){
    
}