#ifndef __PLASASIM_PLANNER_H_
#define __PLASASIM_PLANNER_H_

#include "BasePlanner.h"
#include <omnetpp.h>

/**
 * Simple planner
 */
class Planner : public BasePlanner,omnetpp::cListener{
  protected:
    virtual Tactic* Plan();
    
};

#endif
