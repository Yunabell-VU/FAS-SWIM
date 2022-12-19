#include "QualityModel.h"

Define_Module(QualityModel);

QualityModel::QualityModel(){

}

void QualityModel::addQualityModel(std::tuple<std::string, double> pQualityAttribute){
    //tuple<std::string,double>();
    qualityAttributes.push_back(pQualityAttribute);
}

 void QualityModel::configureQualityModel(AdaptationGoal *pAdaptationGoal){
    std::vector< std::tuple<std::string, double> > adaptationGoals = pAdaptationGoal->getAdaptationGoals();
    for (std::vector< std::tuple<std::string, double> >::iterator it = adaptationGoals.begin() ; it != adaptationGoals.end(); ++it){
        addQualityModel(*it);
    }
 };

std::vector< std::tuple<std::string, double> > QualityModel::getQualityAttributes(){
    return qualityAttributes;
}

QualityModel::~QualityModel(){
    
}