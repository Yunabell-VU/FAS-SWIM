#ifndef __PLASA_BASEPLANNER_H_
#define __PLASA_BASEPLANNER_H_

#include <omnetpp.h>
#include "model/Model.h"
#include "managers/execution/Tactic.h"
#include "managers/analysis/BaseAnalyser.h"
#include "managers/analysis/MacroOption.h"
#include "managers/analysis/Option.h"

/**
 * Base class for all adaptation planner modules
 */
class BasePlanner : public omnetpp::cSimpleModule, omnetpp::cListener
{
   // Subscribe siganl when analysis is done 
    omnetpp::simsignal_t analysisDoneSignal;
    omnetpp::simsignal_t decisionTimeSignal;
    Model* pModel;

protected:
    omnetpp::cMessage *periodEvent; // pointer to the event object which we'll use for timing
    omnetpp::cMessage *decisionCompleteEvent; // event for notifying of decision completion

  Tactic* pTactic;
  MacroOption * pMacroOption;
  typedef std::list<Option*> OptionList;
  OptionList pOptions;

  virtual int numInitStages() const {return 2;}
  virtual void initialize(int stage);
  virtual void handleMessage(omnetpp::cMessage *msg);

  /**
   * Dispatches the execution of the result of the decision
   */
  virtual void decisionComplete();

  inline Model* getModel() { return pModel; }

  /**
   * Adaptation decision implementation
   *
   * @return Tactic* (possibly a MacroTactic*) or null if none must be executed.
   *   Deletion of the tactic object is done by the caller of this method.
   */
  virtual Tactic* Plan() = 0;

public:
  BasePlanner();
  virtual ~BasePlanner();
  void receiveSignal(omnetpp::cComponent *source, omnetpp::simsignal_t signalID, bool value, cObject *details) override;

};

#endif
