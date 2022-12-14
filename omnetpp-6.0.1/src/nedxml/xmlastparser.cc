//==========================================================================
//  XMLASTPARSER.CC - part of
//
//                     OMNeT++/OMNEST
//            Discrete System Simulation in C++
//
//==========================================================================

/*--------------------------------------------------------------*
  Copyright (C) 2002-2017 Andras Varga
  Copyright (C) 2006-2017 OpenSim Ltd.

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `license' for details on this and other legal matters.
*--------------------------------------------------------------*/

#include "common/saxparser_default.h"
#include "errorstore.h"
#include "xmlastparser.h"
#include "astbuilder.h"

namespace omnetpp {
namespace nedxml {

using namespace omnetpp::common;

ASTNode *parseXML(const char *filename, ErrorStore *errors)
{
    ASTBuilder sh(filename, errors);
    DefaultSaxParser parser;

    parser.setHandler(&sh);
    parser.parseFile(filename);
    return sh.getTree();
}

}  // namespace nedxml
}  // namespace omnetpp

