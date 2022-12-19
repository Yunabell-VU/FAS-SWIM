#ifndef ADAPTATIONGOAL_H_
#define ADAPTATIONGOAL_H_

#include <iostream>
#include <omnetpp.h>
#include <tuple>
#include <vector>

class AdaptationGoal : public omnetpp::cSimpleModule{

double allowedResponseTime;
double serverCost;
double optRevenue;
double utility;
double serverCostCoefficient;
double optRevenueCoefficient;

protected:
    std::vector< std::tuple<std::string, double> > adaptationGoals;

public:
    AdaptationGoal();
    virtual ~AdaptationGoal();
    void addAdaptationGoal(std::string key,double value);

    virtual void initialize(int stage);

    std::vector< std::tuple<std::string, double> > getAdaptationGoals();

};

#endif /* ADAPTATIONGOAL_H_ */
