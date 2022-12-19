#include "Option.h"

using namespace std;

Option::Option(){

}

void Option::configureQualityAttribute(QualityModel * pQualityModel){
    std::vector< std::tuple<std::string, double> > qualityAttributes = pQualityModel->getQualityAttributes();
    for (std::vector< std::tuple<std::string, double> >::iterator it = qualityAttributes.begin() ; it != qualityAttributes.end(); ++it){
        pQualityAttributes.push_back(*it);
    }
}

void Option::setQualityAttribute(std::string key, double value){
    for (std::vector< std::tuple<std::string, double> >::iterator attribute = pQualityAttributes.begin() ; attribute != pQualityAttributes.end(); ++attribute){
        if(get<0>(*attribute) == key){
            get<1>(*attribute) = value;
        }
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