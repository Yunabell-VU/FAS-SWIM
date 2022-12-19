#ifndef __PLASA_BASEANALYSER_H_
#define __PLASA_BASEANALYSER_H_

#include <omnetpp.h>
#include "model/Model.h"

/**
 * Base class for all adaptation analyer modules
 */
class BaseAnalyser : public omnetpp::cSimpleModule
{

    omnetpp::simsignal_t analysisTimeSignal;

    Model* pModel;
    bool pDecision;

protected:
    omnetpp::cMessage *periodEvent; // pointer to the event object which we'll use for timing
    omnetpp::cMessage *analysisCompleteEvent; // event for notifying of analysis completion

  virtual int numInitStages() const {return 2;}
  virtual void initialize(int stage);

  /**
   * Dispatches the execution of the result of the analysis
   */
  virtual void analysisComplete();

  inline Model* getModel() { return pModel; }

  /**
   * Adaptation decision implementation
   *
   * @return bool Evaluation if adaption is needed.
   * 
   */
  virtual bool evaluate() = 0;

public:

  static const char* SIG_ANALYSIS_DONE;
  static const char* SIG_ANALYSIS_TIME;
  
  BaseAnalyser();
  virtual ~BaseAnalyser();
};

#endif
