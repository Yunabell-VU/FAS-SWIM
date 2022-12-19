#include "MacroOption.h"

Define_Module(MacroOption);

MacroOption::MacroOption(){

}

void MacroOption::initialize(int stage){
    
}

void MacroOption::addOption(Option * option){
    pOptions.push_back(option);
}


std::list<Option*> MacroOption::getOptions(){
    return pOptions;
}

MacroOption::~MacroOption(){
    
}