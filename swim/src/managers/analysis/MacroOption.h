#ifndef __MACROOPTION_H_
#define __MACROOPTION_H_


#include <omnetpp.h>
#include <iostream>
#include <list>
#include "model/AdaptationGoal.h"
#include "QualityModel.h"
#include "Option.h"

/**
 * Adapatation Macro Option 
 */
class MacroOption: public omnetpp::cSimpleModule{

    protected:
        typedef std::list<Option*> OptionList;
        OptionList pOptions;

        void initialize(int stage);

    public:
        void addOption(Option *option);
        std::list<Option*> getOptions();


        MacroOption();
        virtual ~MacroOption();
        
};

#endif
