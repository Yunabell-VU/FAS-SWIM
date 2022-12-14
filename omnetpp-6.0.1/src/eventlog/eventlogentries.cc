//=========================================================================
//  EVENTLOGENTRIES.CC - part of
//                  OMNeT++/OMNEST
//           Discrete System Simulation in C++
//
//  This is a generated file -- do not modify.
//
//=========================================================================

#include <cstdio>
#include "event.h"
#include "eventlogentries.h"
#include "common/stringutil.h"

namespace omnetpp {
namespace eventlog {

using namespace omnetpp::common;

SimulationBeginEntry::SimulationBeginEntry()
{
    this->chunk = nullptr;
    omnetppVersion = -1;
    eventlogVersion = -1;
    runId = nullptr;
}

SimulationBeginEntry::SimulationBeginEntry(IChunk *chunk, int entryIndex)
{
    this->chunk = chunk;
    this->entryIndex = entryIndex;
    omnetppVersion = -1;
    eventlogVersion = -1;
    runId = nullptr;
}

void SimulationBeginEntry::parse(char **tokens, int numTokens)
{
    omnetppVersion = getIntToken(tokens, numTokens, "ov", true, omnetppVersion);
    eventlogVersion = getIntToken(tokens, numTokens, "ev", true, eventlogVersion);
    runId = getStringToken(tokens, numTokens, "rid", true, runId);
}

void SimulationBeginEntry::print(FILE *fout)
{
    fprintf(fout, "SB");
    fprintf(fout, " ov %d", omnetppVersion);
    fprintf(fout, " ev %d", eventlogVersion);
    fprintf(fout, " rid %s", QUOTE(runId));
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> SimulationBeginEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    names.push_back("ov");
    names.push_back("ev");
    names.push_back("rid");
    return names;
}

const char *SimulationBeginEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "ov"))
    {
        sprintf(buffer, "%d", omnetppVersion);
        return buffer;
    }
    else if (!strcmp(attribute, "ev"))
    {
        sprintf(buffer, "%d", eventlogVersion);
        return buffer;
    }
    else if (!strcmp(attribute, "rid"))
        return runId;
    else
        return nullptr;
}

SimulationEndEntry::SimulationEndEntry()
{
    this->chunk = nullptr;
    isError = false;
    resultCode = -1;
    message = nullptr;
}

SimulationEndEntry::SimulationEndEntry(IChunk *chunk, int entryIndex)
{
    this->chunk = chunk;
    this->entryIndex = entryIndex;
    isError = false;
    resultCode = -1;
    message = nullptr;
}

void SimulationEndEntry::parse(char **tokens, int numTokens)
{
    isError = getBoolToken(tokens, numTokens, "e", true, isError);
    resultCode = getIntToken(tokens, numTokens, "c", true, resultCode);
    message = getStringToken(tokens, numTokens, "m", true, message);
}

void SimulationEndEntry::print(FILE *fout)
{
    fprintf(fout, "SE");
    fprintf(fout, " e %d", isError);
    fprintf(fout, " c %d", resultCode);
    fprintf(fout, " m %s", QUOTE(message));
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> SimulationEndEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    names.push_back("e");
    names.push_back("c");
    names.push_back("m");
    return names;
}

const char *SimulationEndEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "e"))
    {
        sprintf(buffer, "%d", isError);
        return buffer;
    }
    else if (!strcmp(attribute, "c"))
    {
        sprintf(buffer, "%d", resultCode);
        return buffer;
    }
    else if (!strcmp(attribute, "m"))
        return message;
    else
        return nullptr;
}

EventEntry::EventEntry()
{
    this->chunk = nullptr;
    eventNumber = -1;
    simulationTime = simtime_nil;
    moduleId = -1;
    causeEventNumber = -1;
    messageId = -1;
    fingerprints = NULL;
}

EventEntry::EventEntry(IChunk *chunk, int entryIndex)
{
    this->chunk = chunk;
    this->entryIndex = entryIndex;
    eventNumber = -1;
    simulationTime = simtime_nil;
    moduleId = -1;
    causeEventNumber = -1;
    messageId = -1;
    fingerprints = NULL;
}

void EventEntry::parse(char **tokens, int numTokens)
{
    eventNumber = getEventNumberToken(tokens, numTokens, "#", true, eventNumber);
    simulationTime = getSimtimeToken(tokens, numTokens, "t", true, simulationTime);
    moduleId = getIntToken(tokens, numTokens, "m", true, moduleId);
    causeEventNumber = getEventNumberToken(tokens, numTokens, "ce", true, causeEventNumber);
    messageId = getInt64Token(tokens, numTokens, "msg", true, messageId);
    fingerprints = getStringToken(tokens, numTokens, "f", false, fingerprints);
}

void EventEntry::print(FILE *fout)
{
    fprintf(fout, "E");
    fprintf(fout, " # %" EVENTNUMBER_PRINTF_FORMAT "", eventNumber);
    fprintf(fout, " t %s", simulationTime.str(buffer));
    fprintf(fout, " m %d", moduleId);
    fprintf(fout, " ce %" EVENTNUMBER_PRINTF_FORMAT "", causeEventNumber);
    fprintf(fout, " msg %" MSGID_PRINTF_FORMAT "", messageId);
    if (fingerprints)
        fprintf(fout, " f %s", QUOTE(fingerprints));
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> EventEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    names.push_back("#");
    names.push_back("t");
    names.push_back("m");
    names.push_back("ce");
    names.push_back("msg");
    names.push_back("f");
    return names;
}

const char *EventEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "#"))
    {
        sprintf(buffer, "%" EVENTNUMBER_PRINTF_FORMAT "", eventNumber);
        return buffer;
    }
    else if (!strcmp(attribute, "t"))
        return simulationTime.str(buffer);
    else if (!strcmp(attribute, "m"))
    {
        sprintf(buffer, "%d", moduleId);
        return buffer;
    }
    else if (!strcmp(attribute, "ce"))
    {
        sprintf(buffer, "%" EVENTNUMBER_PRINTF_FORMAT "", causeEventNumber);
        return buffer;
    }
    else if (!strcmp(attribute, "msg"))
    {
        sprintf(buffer, "%" MSGID_PRINTF_FORMAT "", messageId);
        return buffer;
    }
    else if (!strcmp(attribute, "f"))
        return fingerprints;
    else
        return nullptr;
}

SnapshotEntry::SnapshotEntry()
{
    this->chunk = nullptr;
    fileOffset = -1;
    eventNumber = -1;
    simulationTime = simtime_nil;
}

SnapshotEntry::SnapshotEntry(IChunk *chunk, int entryIndex)
{
    this->chunk = chunk;
    this->entryIndex = entryIndex;
    fileOffset = -1;
    eventNumber = -1;
    simulationTime = simtime_nil;
}

void SnapshotEntry::parse(char **tokens, int numTokens)
{
    fileOffset = getInt64Token(tokens, numTokens, "f", true, fileOffset);
    eventNumber = getEventNumberToken(tokens, numTokens, "#", true, eventNumber);
    simulationTime = getSimtimeToken(tokens, numTokens, "t", true, simulationTime);
}

void SnapshotEntry::print(FILE *fout)
{
    fprintf(fout, "S");
    fprintf(fout, " f %" PRId64 "", fileOffset);
    fprintf(fout, " # %" EVENTNUMBER_PRINTF_FORMAT "", eventNumber);
    fprintf(fout, " t %s", simulationTime.str(buffer));
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> SnapshotEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    names.push_back("f");
    names.push_back("#");
    names.push_back("t");
    return names;
}

const char *SnapshotEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "f"))
    {
        sprintf(buffer, "%" PRId64 "", fileOffset);
        return buffer;
    }
    else if (!strcmp(attribute, "#"))
    {
        sprintf(buffer, "%" EVENTNUMBER_PRINTF_FORMAT "", eventNumber);
        return buffer;
    }
    else if (!strcmp(attribute, "t"))
        return simulationTime.str(buffer);
    else
        return nullptr;
}

IndexEntry::IndexEntry()
{
    this->chunk = nullptr;
    fileOffset = -1;
    previousIndexFileOffset = -1;
    previousSnapshotFileOffset = -1;
    eventNumber = -1;
    simulationTime = simtime_nil;
}

IndexEntry::IndexEntry(IChunk *chunk, int entryIndex)
{
    this->chunk = chunk;
    this->entryIndex = entryIndex;
    fileOffset = -1;
    previousIndexFileOffset = -1;
    previousSnapshotFileOffset = -1;
    eventNumber = -1;
    simulationTime = simtime_nil;
}

void IndexEntry::parse(char **tokens, int numTokens)
{
    fileOffset = getInt64Token(tokens, numTokens, "f", true, fileOffset);
    previousIndexFileOffset = getInt64Token(tokens, numTokens, "i", true, previousIndexFileOffset);
    previousSnapshotFileOffset = getInt64Token(tokens, numTokens, "s", true, previousSnapshotFileOffset);
    eventNumber = getEventNumberToken(tokens, numTokens, "#", true, eventNumber);
    simulationTime = getSimtimeToken(tokens, numTokens, "t", true, simulationTime);
}

void IndexEntry::print(FILE *fout)
{
    fprintf(fout, "I");
    fprintf(fout, " f %" PRId64 "", fileOffset);
    fprintf(fout, " i %" PRId64 "", previousIndexFileOffset);
    fprintf(fout, " s %" PRId64 "", previousSnapshotFileOffset);
    fprintf(fout, " # %" EVENTNUMBER_PRINTF_FORMAT "", eventNumber);
    fprintf(fout, " t %s", simulationTime.str(buffer));
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> IndexEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    names.push_back("f");
    names.push_back("i");
    names.push_back("s");
    names.push_back("#");
    names.push_back("t");
    return names;
}

const char *IndexEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "f"))
    {
        sprintf(buffer, "%" PRId64 "", fileOffset);
        return buffer;
    }
    else if (!strcmp(attribute, "i"))
    {
        sprintf(buffer, "%" PRId64 "", previousIndexFileOffset);
        return buffer;
    }
    else if (!strcmp(attribute, "s"))
    {
        sprintf(buffer, "%" PRId64 "", previousSnapshotFileOffset);
        return buffer;
    }
    else if (!strcmp(attribute, "#"))
    {
        sprintf(buffer, "%" EVENTNUMBER_PRINTF_FORMAT "", eventNumber);
        return buffer;
    }
    else if (!strcmp(attribute, "t"))
        return simulationTime.str(buffer);
    else
        return nullptr;
}

ReferenceEntry::ReferenceEntry()
{
    this->chunk = nullptr;
    eventNumber = -1;
    beginEntryIndex = -1;
    endEntryIndex = -1;
}

ReferenceEntry::ReferenceEntry(IChunk *chunk, int entryIndex)
{
    this->chunk = chunk;
    this->entryIndex = entryIndex;
    eventNumber = -1;
    beginEntryIndex = -1;
    endEntryIndex = -1;
}

void ReferenceEntry::parse(char **tokens, int numTokens)
{
    eventNumber = getEventNumberToken(tokens, numTokens, "#", true, eventNumber);
    beginEntryIndex = getIntToken(tokens, numTokens, "b", true, beginEntryIndex);
    endEntryIndex = getIntToken(tokens, numTokens, "e", true, endEntryIndex);
}

void ReferenceEntry::print(FILE *fout)
{
    fprintf(fout, " # %" EVENTNUMBER_PRINTF_FORMAT "", eventNumber);
    fprintf(fout, " b %d", beginEntryIndex);
    fprintf(fout, " e %d", endEntryIndex);
    fflush(fout);
}

const std::vector<const char *> ReferenceEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    names.push_back("#");
    names.push_back("b");
    names.push_back("e");
    return names;
}

const char *ReferenceEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "#"))
    {
        sprintf(buffer, "%" EVENTNUMBER_PRINTF_FORMAT "", eventNumber);
        return buffer;
    }
    else if (!strcmp(attribute, "b"))
    {
        sprintf(buffer, "%d", beginEntryIndex);
        return buffer;
    }
    else if (!strcmp(attribute, "e"))
    {
        sprintf(buffer, "%d", endEntryIndex);
        return buffer;
    }
    else
        return nullptr;
}

ReferenceFoundEntry::ReferenceFoundEntry()
    : ReferenceEntry()
{
}

ReferenceFoundEntry::ReferenceFoundEntry(IChunk *chunk, int entryIndex)
    : ReferenceEntry(chunk, entryIndex)
{
}

void ReferenceFoundEntry::parse(char **tokens, int numTokens)
{
    ReferenceEntry::parse(tokens, numTokens);
}

void ReferenceFoundEntry::print(FILE *fout)
{
    fprintf(fout, "RF");
    ReferenceEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> ReferenceFoundEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = ReferenceEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *ReferenceFoundEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return ReferenceEntry::getAsString(attribute);
}

ReferenceAddedEntry::ReferenceAddedEntry()
    : ReferenceEntry()
{
}

ReferenceAddedEntry::ReferenceAddedEntry(IChunk *chunk, int entryIndex)
    : ReferenceEntry(chunk, entryIndex)
{
}

void ReferenceAddedEntry::parse(char **tokens, int numTokens)
{
    ReferenceEntry::parse(tokens, numTokens);
}

void ReferenceAddedEntry::print(FILE *fout)
{
    fprintf(fout, "RA");
    ReferenceEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> ReferenceAddedEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = ReferenceEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *ReferenceAddedEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return ReferenceEntry::getAsString(attribute);
}

ReferenceRemovedEntry::ReferenceRemovedEntry()
    : ReferenceEntry()
{
}

ReferenceRemovedEntry::ReferenceRemovedEntry(IChunk *chunk, int entryIndex)
    : ReferenceEntry(chunk, entryIndex)
{
}

void ReferenceRemovedEntry::parse(char **tokens, int numTokens)
{
    ReferenceEntry::parse(tokens, numTokens);
}

void ReferenceRemovedEntry::print(FILE *fout)
{
    fprintf(fout, "RR");
    ReferenceEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> ReferenceRemovedEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = ReferenceEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *ReferenceRemovedEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return ReferenceEntry::getAsString(attribute);
}

ModuleReferenceEntry::ModuleReferenceEntry()
{
    this->chunk = nullptr;
    moduleId = -1;
}

ModuleReferenceEntry::ModuleReferenceEntry(IChunk *chunk, int entryIndex)
{
    this->chunk = chunk;
    this->entryIndex = entryIndex;
    moduleId = -1;
}

void ModuleReferenceEntry::parse(char **tokens, int numTokens)
{
    moduleId = getIntToken(tokens, numTokens, "id", true, moduleId);
}

void ModuleReferenceEntry::print(FILE *fout)
{
    fprintf(fout, " id %d", moduleId);
    fflush(fout);
}

const std::vector<const char *> ModuleReferenceEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    names.push_back("id");
    return names;
}

const char *ModuleReferenceEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "id"))
    {
        sprintf(buffer, "%d", moduleId);
        return buffer;
    }
    else
        return nullptr;
}

GateReferenceEntry::GateReferenceEntry()
{
    this->chunk = nullptr;
    moduleId = -1;
    gateId = -1;
}

GateReferenceEntry::GateReferenceEntry(IChunk *chunk, int entryIndex)
{
    this->chunk = chunk;
    this->entryIndex = entryIndex;
    moduleId = -1;
    gateId = -1;
}

void GateReferenceEntry::parse(char **tokens, int numTokens)
{
    moduleId = getIntToken(tokens, numTokens, "m", true, moduleId);
    gateId = getIntToken(tokens, numTokens, "g", true, gateId);
}

void GateReferenceEntry::print(FILE *fout)
{
    fprintf(fout, " m %d", moduleId);
    fprintf(fout, " g %d", gateId);
    fflush(fout);
}

const std::vector<const char *> GateReferenceEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    names.push_back("m");
    names.push_back("g");
    return names;
}

const char *GateReferenceEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "m"))
    {
        sprintf(buffer, "%d", moduleId);
        return buffer;
    }
    else if (!strcmp(attribute, "g"))
    {
        sprintf(buffer, "%d", gateId);
        return buffer;
    }
    else
        return nullptr;
}

ConnectionReferenceEntry::ConnectionReferenceEntry()
{
    this->chunk = nullptr;
    sourceModuleId = -1;
    sourceGateId = -1;
}

ConnectionReferenceEntry::ConnectionReferenceEntry(IChunk *chunk, int entryIndex)
{
    this->chunk = chunk;
    this->entryIndex = entryIndex;
    sourceModuleId = -1;
    sourceGateId = -1;
}

void ConnectionReferenceEntry::parse(char **tokens, int numTokens)
{
    sourceModuleId = getIntToken(tokens, numTokens, "sm", true, sourceModuleId);
    sourceGateId = getIntToken(tokens, numTokens, "sg", true, sourceGateId);
}

void ConnectionReferenceEntry::print(FILE *fout)
{
    fprintf(fout, " sm %d", sourceModuleId);
    fprintf(fout, " sg %d", sourceGateId);
    fflush(fout);
}

const std::vector<const char *> ConnectionReferenceEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    names.push_back("sm");
    names.push_back("sg");
    return names;
}

const char *ConnectionReferenceEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "sm"))
    {
        sprintf(buffer, "%d", sourceModuleId);
        return buffer;
    }
    else if (!strcmp(attribute, "sg"))
    {
        sprintf(buffer, "%d", sourceGateId);
        return buffer;
    }
    else
        return nullptr;
}

MessageReferenceEntry::MessageReferenceEntry()
{
    this->chunk = nullptr;
    messageId = -1;
}

MessageReferenceEntry::MessageReferenceEntry(IChunk *chunk, int entryIndex)
{
    this->chunk = chunk;
    this->entryIndex = entryIndex;
    messageId = -1;
}

void MessageReferenceEntry::parse(char **tokens, int numTokens)
{
    messageId = getInt64Token(tokens, numTokens, "id", true, messageId);
}

void MessageReferenceEntry::print(FILE *fout)
{
    fprintf(fout, " id %" MSGID_PRINTF_FORMAT "", messageId);
    fflush(fout);
}

const std::vector<const char *> MessageReferenceEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    names.push_back("id");
    return names;
}

const char *MessageReferenceEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "id"))
    {
        sprintf(buffer, "%" MSGID_PRINTF_FORMAT "", messageId);
        return buffer;
    }
    else
        return nullptr;
}

ModuleDescriptionEntry::ModuleDescriptionEntry()
    : ModuleReferenceEntry()
{
    moduleClassName = nullptr;
    nedTypeName = nullptr;
    parentModuleId = -1;
    fullName = nullptr;
    compoundModule = false;
}

ModuleDescriptionEntry::ModuleDescriptionEntry(IChunk *chunk, int entryIndex)
    : ModuleReferenceEntry(chunk, entryIndex)
{
    moduleClassName = nullptr;
    nedTypeName = nullptr;
    parentModuleId = -1;
    fullName = nullptr;
    compoundModule = false;
}

void ModuleDescriptionEntry::parse(char **tokens, int numTokens)
{
    ModuleReferenceEntry::parse(tokens, numTokens);
    moduleClassName = getStringToken(tokens, numTokens, "c", true, moduleClassName);
    nedTypeName = getStringToken(tokens, numTokens, "t", true, nedTypeName);
    parentModuleId = getIntToken(tokens, numTokens, "pid", false, parentModuleId);
    fullName = getStringToken(tokens, numTokens, "n", true, fullName);
    compoundModule = getBoolToken(tokens, numTokens, "cm", false, compoundModule);
}

void ModuleDescriptionEntry::print(FILE *fout)
{
    ModuleReferenceEntry::print(fout);
    fprintf(fout, " c %s", QUOTE(moduleClassName));
    fprintf(fout, " t %s", QUOTE(nedTypeName));
    if (parentModuleId != -1)
        fprintf(fout, " pid %d", parentModuleId);
    fprintf(fout, " n %s", QUOTE(fullName));
    if (compoundModule != false)
        fprintf(fout, " cm %d", compoundModule);
    fflush(fout);
}

const std::vector<const char *> ModuleDescriptionEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = ModuleReferenceEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("c");
    names.push_back("t");
    names.push_back("pid");
    names.push_back("n");
    names.push_back("cm");
    return names;
}

const char *ModuleDescriptionEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "c"))
        return moduleClassName;
    else if (!strcmp(attribute, "t"))
        return nedTypeName;
    else if (!strcmp(attribute, "pid"))
    {
        sprintf(buffer, "%d", parentModuleId);
        return buffer;
    }
    else if (!strcmp(attribute, "n"))
        return fullName;
    else if (!strcmp(attribute, "cm"))
    {
        sprintf(buffer, "%d", compoundModule);
        return buffer;
    }
    else
        return ModuleReferenceEntry::getAsString(attribute);
}

GateDescriptionEntry::GateDescriptionEntry()
    : GateReferenceEntry()
{
    name = nullptr;
    index = -1;
    isOutput = false;
}

GateDescriptionEntry::GateDescriptionEntry(IChunk *chunk, int entryIndex)
    : GateReferenceEntry(chunk, entryIndex)
{
    name = nullptr;
    index = -1;
    isOutput = false;
}

void GateDescriptionEntry::parse(char **tokens, int numTokens)
{
    GateReferenceEntry::parse(tokens, numTokens);
    name = getStringToken(tokens, numTokens, "n", true, name);
    index = getIntToken(tokens, numTokens, "i", false, index);
    isOutput = getBoolToken(tokens, numTokens, "o", true, isOutput);
}

void GateDescriptionEntry::print(FILE *fout)
{
    GateReferenceEntry::print(fout);
    fprintf(fout, " n %s", QUOTE(name));
    if (index != -1)
        fprintf(fout, " i %d", index);
    fprintf(fout, " o %d", isOutput);
    fflush(fout);
}

const std::vector<const char *> GateDescriptionEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = GateReferenceEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("n");
    names.push_back("i");
    names.push_back("o");
    return names;
}

const char *GateDescriptionEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "n"))
        return name;
    else if (!strcmp(attribute, "i"))
    {
        sprintf(buffer, "%d", index);
        return buffer;
    }
    else if (!strcmp(attribute, "o"))
    {
        sprintf(buffer, "%d", isOutput);
        return buffer;
    }
    else
        return GateReferenceEntry::getAsString(attribute);
}

ConnectionDescriptionEntry::ConnectionDescriptionEntry()
    : ConnectionReferenceEntry()
{
    destModuleId = -1;
    destGateId = -1;
}

ConnectionDescriptionEntry::ConnectionDescriptionEntry(IChunk *chunk, int entryIndex)
    : ConnectionReferenceEntry(chunk, entryIndex)
{
    destModuleId = -1;
    destGateId = -1;
}

void ConnectionDescriptionEntry::parse(char **tokens, int numTokens)
{
    ConnectionReferenceEntry::parse(tokens, numTokens);
    destModuleId = getIntToken(tokens, numTokens, "dm", true, destModuleId);
    destGateId = getIntToken(tokens, numTokens, "dg", true, destGateId);
}

void ConnectionDescriptionEntry::print(FILE *fout)
{
    ConnectionReferenceEntry::print(fout);
    fprintf(fout, " dm %d", destModuleId);
    fprintf(fout, " dg %d", destGateId);
    fflush(fout);
}

const std::vector<const char *> ConnectionDescriptionEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = ConnectionReferenceEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("dm");
    names.push_back("dg");
    return names;
}

const char *ConnectionDescriptionEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "dm"))
    {
        sprintf(buffer, "%d", destModuleId);
        return buffer;
    }
    else if (!strcmp(attribute, "dg"))
    {
        sprintf(buffer, "%d", destGateId);
        return buffer;
    }
    else
        return ConnectionReferenceEntry::getAsString(attribute);
}

MessageDescriptionEntry::MessageDescriptionEntry()
    : MessageReferenceEntry()
{
    messageTreeId = -1;
    messageEncapsulationId = -1;
    messageEncapsulationTreeId = -1;
    messageClassName = nullptr;
    messageName = nullptr;
    messageKind = 0;
    messagePriority = 0;
    messageLength = 0;
    hasBitError = false;
    ownerModuleId = -1;
    senderModuleId = -1;
    senderGateId = -1;
    sendingTime = -1;
    arrivalModuleId = -1;
    arrivalGateId = -1;
    arrivalTime = -1;
    detail = NULL;
    previousEventNumber = -1;
}

MessageDescriptionEntry::MessageDescriptionEntry(IChunk *chunk, int entryIndex)
    : MessageReferenceEntry(chunk, entryIndex)
{
    messageTreeId = -1;
    messageEncapsulationId = -1;
    messageEncapsulationTreeId = -1;
    messageClassName = nullptr;
    messageName = nullptr;
    messageKind = 0;
    messagePriority = 0;
    messageLength = 0;
    hasBitError = false;
    ownerModuleId = -1;
    senderModuleId = -1;
    senderGateId = -1;
    sendingTime = -1;
    arrivalModuleId = -1;
    arrivalGateId = -1;
    arrivalTime = -1;
    detail = NULL;
    previousEventNumber = -1;
}

void MessageDescriptionEntry::parse(char **tokens, int numTokens)
{
    MessageReferenceEntry::parse(tokens, numTokens);
    messageTreeId = getInt64Token(tokens, numTokens, "tid", true, messageTreeId);
    messageEncapsulationId = getInt64Token(tokens, numTokens, "eid", true, messageEncapsulationId);
    messageEncapsulationTreeId = getInt64Token(tokens, numTokens, "etid", true, messageEncapsulationTreeId);
    messageClassName = getStringToken(tokens, numTokens, "c", true, messageClassName);
    messageName = getStringToken(tokens, numTokens, "n", true, messageName);
    messageKind = getShortToken(tokens, numTokens, "k", false, messageKind);
    messagePriority = getShortToken(tokens, numTokens, "p", false, messagePriority);
    messageLength = getInt64Token(tokens, numTokens, "l", false, messageLength);
    hasBitError = getBoolToken(tokens, numTokens, "er", false, hasBitError);
    ownerModuleId = getIntToken(tokens, numTokens, "m", false, ownerModuleId);
    senderModuleId = getIntToken(tokens, numTokens, "sm", false, senderModuleId);
    senderGateId = getIntToken(tokens, numTokens, "sg", false, senderGateId);
    sendingTime = getSimtimeToken(tokens, numTokens, "st", false, sendingTime);
    arrivalModuleId = getIntToken(tokens, numTokens, "am", false, arrivalModuleId);
    arrivalGateId = getIntToken(tokens, numTokens, "ag", false, arrivalGateId);
    arrivalTime = getSimtimeToken(tokens, numTokens, "at", false, arrivalTime);
    detail = getStringToken(tokens, numTokens, "d", false, detail);
    previousEventNumber = getEventNumberToken(tokens, numTokens, "pe", true, previousEventNumber);
}

void MessageDescriptionEntry::print(FILE *fout)
{
    MessageReferenceEntry::print(fout);
    fprintf(fout, " tid %" MSGID_PRINTF_FORMAT "", messageTreeId);
    fprintf(fout, " eid %" MSGID_PRINTF_FORMAT "", messageEncapsulationId);
    fprintf(fout, " etid %" MSGID_PRINTF_FORMAT "", messageEncapsulationTreeId);
    fprintf(fout, " c %s", QUOTE(messageClassName));
    fprintf(fout, " n %s", QUOTE(messageName));
    if (messageKind != 0)
        fprintf(fout, " k %d", messageKind);
    if (messagePriority != 0)
        fprintf(fout, " p %d", messagePriority);
    if (messageLength != 0)
        fprintf(fout, " l %" PRId64 "", messageLength);
    if (hasBitError != false)
        fprintf(fout, " er %d", hasBitError);
    if (ownerModuleId != -1)
        fprintf(fout, " m %d", ownerModuleId);
    if (senderModuleId != -1)
        fprintf(fout, " sm %d", senderModuleId);
    if (senderGateId != -1)
        fprintf(fout, " sg %d", senderGateId);
    if (sendingTime != -1)
        fprintf(fout, " st %s", sendingTime.str(buffer));
    if (arrivalModuleId != -1)
        fprintf(fout, " am %d", arrivalModuleId);
    if (arrivalGateId != -1)
        fprintf(fout, " ag %d", arrivalGateId);
    if (arrivalTime != -1)
        fprintf(fout, " at %s", arrivalTime.str(buffer));
    if (detail)
        fprintf(fout, " d %s", QUOTE(detail));
    fprintf(fout, " pe %" EVENTNUMBER_PRINTF_FORMAT "", previousEventNumber);
    fflush(fout);
}

const std::vector<const char *> MessageDescriptionEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = MessageReferenceEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("tid");
    names.push_back("eid");
    names.push_back("etid");
    names.push_back("c");
    names.push_back("n");
    names.push_back("k");
    names.push_back("p");
    names.push_back("l");
    names.push_back("er");
    names.push_back("m");
    names.push_back("sm");
    names.push_back("sg");
    names.push_back("st");
    names.push_back("am");
    names.push_back("ag");
    names.push_back("at");
    names.push_back("d");
    names.push_back("pe");
    return names;
}

const char *MessageDescriptionEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "tid"))
    {
        sprintf(buffer, "%" MSGID_PRINTF_FORMAT "", messageTreeId);
        return buffer;
    }
    else if (!strcmp(attribute, "eid"))
    {
        sprintf(buffer, "%" MSGID_PRINTF_FORMAT "", messageEncapsulationId);
        return buffer;
    }
    else if (!strcmp(attribute, "etid"))
    {
        sprintf(buffer, "%" MSGID_PRINTF_FORMAT "", messageEncapsulationTreeId);
        return buffer;
    }
    else if (!strcmp(attribute, "c"))
        return messageClassName;
    else if (!strcmp(attribute, "n"))
        return messageName;
    else if (!strcmp(attribute, "k"))
    {
        sprintf(buffer, "%d", messageKind);
        return buffer;
    }
    else if (!strcmp(attribute, "p"))
    {
        sprintf(buffer, "%d", messagePriority);
        return buffer;
    }
    else if (!strcmp(attribute, "l"))
    {
        sprintf(buffer, "%" PRId64 "", messageLength);
        return buffer;
    }
    else if (!strcmp(attribute, "er"))
    {
        sprintf(buffer, "%d", hasBitError);
        return buffer;
    }
    else if (!strcmp(attribute, "m"))
    {
        sprintf(buffer, "%d", ownerModuleId);
        return buffer;
    }
    else if (!strcmp(attribute, "sm"))
    {
        sprintf(buffer, "%d", senderModuleId);
        return buffer;
    }
    else if (!strcmp(attribute, "sg"))
    {
        sprintf(buffer, "%d", senderGateId);
        return buffer;
    }
    else if (!strcmp(attribute, "st"))
        return sendingTime.str(buffer);
    else if (!strcmp(attribute, "am"))
    {
        sprintf(buffer, "%d", arrivalModuleId);
        return buffer;
    }
    else if (!strcmp(attribute, "ag"))
    {
        sprintf(buffer, "%d", arrivalGateId);
        return buffer;
    }
    else if (!strcmp(attribute, "at"))
        return arrivalTime.str(buffer);
    else if (!strcmp(attribute, "d"))
        return detail;
    else if (!strcmp(attribute, "pe"))
    {
        sprintf(buffer, "%" EVENTNUMBER_PRINTF_FORMAT "", previousEventNumber);
        return buffer;
    }
    else
        return MessageReferenceEntry::getAsString(attribute);
}

ModuleDisplayStringEntry::ModuleDisplayStringEntry()
    : ModuleReferenceEntry()
{
    displayString = nullptr;
}

ModuleDisplayStringEntry::ModuleDisplayStringEntry(IChunk *chunk, int entryIndex)
    : ModuleReferenceEntry(chunk, entryIndex)
{
    displayString = nullptr;
}

void ModuleDisplayStringEntry::parse(char **tokens, int numTokens)
{
    ModuleReferenceEntry::parse(tokens, numTokens);
    displayString = getStringToken(tokens, numTokens, "d", true, displayString);
}

void ModuleDisplayStringEntry::print(FILE *fout)
{
    ModuleReferenceEntry::print(fout);
    fprintf(fout, " d %s", QUOTE(displayString));
    fflush(fout);
}

const std::vector<const char *> ModuleDisplayStringEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = ModuleReferenceEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("d");
    return names;
}

const char *ModuleDisplayStringEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "d"))
        return displayString;
    else
        return ModuleReferenceEntry::getAsString(attribute);
}

GateDisplayStringEntry::GateDisplayStringEntry()
    : GateReferenceEntry()
{
    displayString = nullptr;
}

GateDisplayStringEntry::GateDisplayStringEntry(IChunk *chunk, int entryIndex)
    : GateReferenceEntry(chunk, entryIndex)
{
    displayString = nullptr;
}

void GateDisplayStringEntry::parse(char **tokens, int numTokens)
{
    GateReferenceEntry::parse(tokens, numTokens);
    displayString = getStringToken(tokens, numTokens, "d", true, displayString);
}

void GateDisplayStringEntry::print(FILE *fout)
{
    GateReferenceEntry::print(fout);
    fprintf(fout, " d %s", QUOTE(displayString));
    fflush(fout);
}

const std::vector<const char *> GateDisplayStringEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = GateReferenceEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("d");
    return names;
}

const char *GateDisplayStringEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "d"))
        return displayString;
    else
        return GateReferenceEntry::getAsString(attribute);
}

ConnectionDisplayStringEntry::ConnectionDisplayStringEntry()
    : ConnectionReferenceEntry()
{
    displayString = nullptr;
}

ConnectionDisplayStringEntry::ConnectionDisplayStringEntry(IChunk *chunk, int entryIndex)
    : ConnectionReferenceEntry(chunk, entryIndex)
{
    displayString = nullptr;
}

void ConnectionDisplayStringEntry::parse(char **tokens, int numTokens)
{
    ConnectionReferenceEntry::parse(tokens, numTokens);
    displayString = getStringToken(tokens, numTokens, "d", true, displayString);
}

void ConnectionDisplayStringEntry::print(FILE *fout)
{
    ConnectionReferenceEntry::print(fout);
    fprintf(fout, " d %s", QUOTE(displayString));
    fflush(fout);
}

const std::vector<const char *> ConnectionDisplayStringEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = ConnectionReferenceEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("d");
    return names;
}

const char *ConnectionDisplayStringEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "d"))
        return displayString;
    else
        return ConnectionReferenceEntry::getAsString(attribute);
}

MessageDisplayStringEntry::MessageDisplayStringEntry()
    : MessageReferenceEntry()
{
    displayString = nullptr;
}

MessageDisplayStringEntry::MessageDisplayStringEntry(IChunk *chunk, int entryIndex)
    : MessageReferenceEntry(chunk, entryIndex)
{
    displayString = nullptr;
}

void MessageDisplayStringEntry::parse(char **tokens, int numTokens)
{
    MessageReferenceEntry::parse(tokens, numTokens);
    displayString = getStringToken(tokens, numTokens, "d", true, displayString);
}

void MessageDisplayStringEntry::print(FILE *fout)
{
    MessageReferenceEntry::print(fout);
    fprintf(fout, " d %s", QUOTE(displayString));
    fflush(fout);
}

const std::vector<const char *> MessageDisplayStringEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = MessageReferenceEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("d");
    return names;
}

const char *MessageDisplayStringEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "d"))
        return displayString;
    else
        return MessageReferenceEntry::getAsString(attribute);
}

ComponentMethodBeginEntry::ComponentMethodBeginEntry()
{
    this->chunk = nullptr;
    sourceComponentId = -1;
    targetComponentId = -1;
    methodName = nullptr;
}

ComponentMethodBeginEntry::ComponentMethodBeginEntry(IChunk *chunk, int entryIndex)
{
    this->chunk = chunk;
    this->entryIndex = entryIndex;
    sourceComponentId = -1;
    targetComponentId = -1;
    methodName = nullptr;
}

void ComponentMethodBeginEntry::parse(char **tokens, int numTokens)
{
    sourceComponentId = getIntToken(tokens, numTokens, "sm", true, sourceComponentId);
    targetComponentId = getIntToken(tokens, numTokens, "tm", true, targetComponentId);
    methodName = getStringToken(tokens, numTokens, "m", true, methodName);
}

void ComponentMethodBeginEntry::print(FILE *fout)
{
    fprintf(fout, "CMB");
    fprintf(fout, " sm %d", sourceComponentId);
    fprintf(fout, " tm %d", targetComponentId);
    fprintf(fout, " m %s", QUOTE(methodName));
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> ComponentMethodBeginEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    names.push_back("sm");
    names.push_back("tm");
    names.push_back("m");
    return names;
}

const char *ComponentMethodBeginEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "sm"))
    {
        sprintf(buffer, "%d", sourceComponentId);
        return buffer;
    }
    else if (!strcmp(attribute, "tm"))
    {
        sprintf(buffer, "%d", targetComponentId);
        return buffer;
    }
    else if (!strcmp(attribute, "m"))
        return methodName;
    else
        return nullptr;
}

ComponentMethodEndEntry::ComponentMethodEndEntry()
{
    this->chunk = nullptr;
}

ComponentMethodEndEntry::ComponentMethodEndEntry(IChunk *chunk, int entryIndex)
{
    this->chunk = chunk;
    this->entryIndex = entryIndex;
}

void ComponentMethodEndEntry::parse(char **tokens, int numTokens)
{
}

void ComponentMethodEndEntry::print(FILE *fout)
{
    fprintf(fout, "CME");
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> ComponentMethodEndEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    return names;
}

const char *ComponentMethodEndEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return nullptr;
}

ModuleCreatedEntry::ModuleCreatedEntry()
    : ModuleDescriptionEntry()
{
}

ModuleCreatedEntry::ModuleCreatedEntry(IChunk *chunk, int entryIndex)
    : ModuleDescriptionEntry(chunk, entryIndex)
{
}

void ModuleCreatedEntry::parse(char **tokens, int numTokens)
{
    ModuleDescriptionEntry::parse(tokens, numTokens);
}

void ModuleCreatedEntry::print(FILE *fout)
{
    fprintf(fout, "MC");
    ModuleDescriptionEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> ModuleCreatedEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = ModuleDescriptionEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *ModuleCreatedEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return ModuleDescriptionEntry::getAsString(attribute);
}

ModuleDeletedEntry::ModuleDeletedEntry()
    : ModuleReferenceEntry()
{
}

ModuleDeletedEntry::ModuleDeletedEntry(IChunk *chunk, int entryIndex)
    : ModuleReferenceEntry(chunk, entryIndex)
{
}

void ModuleDeletedEntry::parse(char **tokens, int numTokens)
{
    ModuleReferenceEntry::parse(tokens, numTokens);
}

void ModuleDeletedEntry::print(FILE *fout)
{
    fprintf(fout, "MD");
    ModuleReferenceEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> ModuleDeletedEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = ModuleReferenceEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *ModuleDeletedEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return ModuleReferenceEntry::getAsString(attribute);
}

GateCreatedEntry::GateCreatedEntry()
    : GateDescriptionEntry()
{
}

GateCreatedEntry::GateCreatedEntry(IChunk *chunk, int entryIndex)
    : GateDescriptionEntry(chunk, entryIndex)
{
}

void GateCreatedEntry::parse(char **tokens, int numTokens)
{
    GateDescriptionEntry::parse(tokens, numTokens);
}

void GateCreatedEntry::print(FILE *fout)
{
    fprintf(fout, "GC");
    GateDescriptionEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> GateCreatedEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = GateDescriptionEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *GateCreatedEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return GateDescriptionEntry::getAsString(attribute);
}

GateDeletedEntry::GateDeletedEntry()
    : GateReferenceEntry()
{
}

GateDeletedEntry::GateDeletedEntry(IChunk *chunk, int entryIndex)
    : GateReferenceEntry(chunk, entryIndex)
{
}

void GateDeletedEntry::parse(char **tokens, int numTokens)
{
    GateReferenceEntry::parse(tokens, numTokens);
}

void GateDeletedEntry::print(FILE *fout)
{
    fprintf(fout, "GD");
    GateReferenceEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> GateDeletedEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = GateReferenceEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *GateDeletedEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return GateReferenceEntry::getAsString(attribute);
}

ConnectionCreatedEntry::ConnectionCreatedEntry()
    : ConnectionDescriptionEntry()
{
}

ConnectionCreatedEntry::ConnectionCreatedEntry(IChunk *chunk, int entryIndex)
    : ConnectionDescriptionEntry(chunk, entryIndex)
{
}

void ConnectionCreatedEntry::parse(char **tokens, int numTokens)
{
    ConnectionDescriptionEntry::parse(tokens, numTokens);
}

void ConnectionCreatedEntry::print(FILE *fout)
{
    fprintf(fout, "CC");
    ConnectionDescriptionEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> ConnectionCreatedEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = ConnectionDescriptionEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *ConnectionCreatedEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return ConnectionDescriptionEntry::getAsString(attribute);
}

ConnectionDeletedEntry::ConnectionDeletedEntry()
    : ConnectionReferenceEntry()
{
}

ConnectionDeletedEntry::ConnectionDeletedEntry(IChunk *chunk, int entryIndex)
    : ConnectionReferenceEntry(chunk, entryIndex)
{
}

void ConnectionDeletedEntry::parse(char **tokens, int numTokens)
{
    ConnectionReferenceEntry::parse(tokens, numTokens);
}

void ConnectionDeletedEntry::print(FILE *fout)
{
    fprintf(fout, "CD");
    ConnectionReferenceEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> ConnectionDeletedEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = ConnectionReferenceEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *ConnectionDeletedEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return ConnectionReferenceEntry::getAsString(attribute);
}

ModuleDisplayStringChangedEntry::ModuleDisplayStringChangedEntry()
    : ModuleDisplayStringEntry()
{
}

ModuleDisplayStringChangedEntry::ModuleDisplayStringChangedEntry(IChunk *chunk, int entryIndex)
    : ModuleDisplayStringEntry(chunk, entryIndex)
{
}

void ModuleDisplayStringChangedEntry::parse(char **tokens, int numTokens)
{
    ModuleDisplayStringEntry::parse(tokens, numTokens);
}

void ModuleDisplayStringChangedEntry::print(FILE *fout)
{
    fprintf(fout, "MDC");
    ModuleDisplayStringEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> ModuleDisplayStringChangedEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = ModuleDisplayStringEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *ModuleDisplayStringChangedEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return ModuleDisplayStringEntry::getAsString(attribute);
}

GateDisplayStringChangedEntry::GateDisplayStringChangedEntry()
    : GateDisplayStringEntry()
{
}

GateDisplayStringChangedEntry::GateDisplayStringChangedEntry(IChunk *chunk, int entryIndex)
    : GateDisplayStringEntry(chunk, entryIndex)
{
}

void GateDisplayStringChangedEntry::parse(char **tokens, int numTokens)
{
    GateDisplayStringEntry::parse(tokens, numTokens);
}

void GateDisplayStringChangedEntry::print(FILE *fout)
{
    fprintf(fout, "GDC");
    GateDisplayStringEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> GateDisplayStringChangedEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = GateDisplayStringEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *GateDisplayStringChangedEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return GateDisplayStringEntry::getAsString(attribute);
}

ConnectionDisplayStringChangedEntry::ConnectionDisplayStringChangedEntry()
    : ConnectionDisplayStringEntry()
{
}

ConnectionDisplayStringChangedEntry::ConnectionDisplayStringChangedEntry(IChunk *chunk, int entryIndex)
    : ConnectionDisplayStringEntry(chunk, entryIndex)
{
}

void ConnectionDisplayStringChangedEntry::parse(char **tokens, int numTokens)
{
    ConnectionDisplayStringEntry::parse(tokens, numTokens);
}

void ConnectionDisplayStringChangedEntry::print(FILE *fout)
{
    fprintf(fout, "CDC");
    ConnectionDisplayStringEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> ConnectionDisplayStringChangedEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = ConnectionDisplayStringEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *ConnectionDisplayStringChangedEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return ConnectionDisplayStringEntry::getAsString(attribute);
}

MessageDisplayStringChangedEntry::MessageDisplayStringChangedEntry()
    : MessageDisplayStringEntry()
{
}

MessageDisplayStringChangedEntry::MessageDisplayStringChangedEntry(IChunk *chunk, int entryIndex)
    : MessageDisplayStringEntry(chunk, entryIndex)
{
}

void MessageDisplayStringChangedEntry::parse(char **tokens, int numTokens)
{
    MessageDisplayStringEntry::parse(tokens, numTokens);
}

void MessageDisplayStringChangedEntry::print(FILE *fout)
{
    fprintf(fout, "EDC");
    MessageDisplayStringEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> MessageDisplayStringChangedEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = MessageDisplayStringEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *MessageDisplayStringChangedEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return MessageDisplayStringEntry::getAsString(attribute);
}

CreateMessageEntry::CreateMessageEntry()
    : MessageDescriptionEntry()
{
}

CreateMessageEntry::CreateMessageEntry(IChunk *chunk, int entryIndex)
    : MessageDescriptionEntry(chunk, entryIndex)
{
}

void CreateMessageEntry::parse(char **tokens, int numTokens)
{
    MessageDescriptionEntry::parse(tokens, numTokens);
}

void CreateMessageEntry::print(FILE *fout)
{
    fprintf(fout, "CM");
    MessageDescriptionEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> CreateMessageEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = MessageDescriptionEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *CreateMessageEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return MessageDescriptionEntry::getAsString(attribute);
}

CloneMessageEntry::CloneMessageEntry()
    : MessageDescriptionEntry()
{
    cloneId = -1;
}

CloneMessageEntry::CloneMessageEntry(IChunk *chunk, int entryIndex)
    : MessageDescriptionEntry(chunk, entryIndex)
{
    cloneId = -1;
}

void CloneMessageEntry::parse(char **tokens, int numTokens)
{
    MessageDescriptionEntry::parse(tokens, numTokens);
    cloneId = getInt64Token(tokens, numTokens, "cid", true, cloneId);
}

void CloneMessageEntry::print(FILE *fout)
{
    fprintf(fout, "CL");
    MessageDescriptionEntry::print(fout);
    fprintf(fout, " cid %" MSGID_PRINTF_FORMAT "", cloneId);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> CloneMessageEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = MessageDescriptionEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("cid");
    return names;
}

const char *CloneMessageEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "cid"))
    {
        sprintf(buffer, "%" MSGID_PRINTF_FORMAT "", cloneId);
        return buffer;
    }
    else
        return MessageDescriptionEntry::getAsString(attribute);
}

DeleteMessageEntry::DeleteMessageEntry()
    : MessageDescriptionEntry()
{
}

DeleteMessageEntry::DeleteMessageEntry(IChunk *chunk, int entryIndex)
    : MessageDescriptionEntry(chunk, entryIndex)
{
}

void DeleteMessageEntry::parse(char **tokens, int numTokens)
{
    MessageDescriptionEntry::parse(tokens, numTokens);
}

void DeleteMessageEntry::print(FILE *fout)
{
    fprintf(fout, "DM");
    MessageDescriptionEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> DeleteMessageEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = MessageDescriptionEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *DeleteMessageEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return MessageDescriptionEntry::getAsString(attribute);
}

EncapsulatePacketEntry::EncapsulatePacketEntry()
    : MessageReferenceEntry()
{
    encapsulatedPacketId = -1;
}

EncapsulatePacketEntry::EncapsulatePacketEntry(IChunk *chunk, int entryIndex)
    : MessageReferenceEntry(chunk, entryIndex)
{
    encapsulatedPacketId = -1;
}

void EncapsulatePacketEntry::parse(char **tokens, int numTokens)
{
    MessageReferenceEntry::parse(tokens, numTokens);
    encapsulatedPacketId = getInt64Token(tokens, numTokens, "cid", true, encapsulatedPacketId);
}

void EncapsulatePacketEntry::print(FILE *fout)
{
    fprintf(fout, "EN");
    MessageReferenceEntry::print(fout);
    fprintf(fout, " cid %" MSGID_PRINTF_FORMAT "", encapsulatedPacketId);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> EncapsulatePacketEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = MessageReferenceEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("cid");
    return names;
}

const char *EncapsulatePacketEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "cid"))
    {
        sprintf(buffer, "%" MSGID_PRINTF_FORMAT "", encapsulatedPacketId);
        return buffer;
    }
    else
        return MessageReferenceEntry::getAsString(attribute);
}

DecapsulatePacketEntry::DecapsulatePacketEntry()
    : MessageReferenceEntry()
{
    encapsulatedPacketId = -1;
}

DecapsulatePacketEntry::DecapsulatePacketEntry(IChunk *chunk, int entryIndex)
    : MessageReferenceEntry(chunk, entryIndex)
{
    encapsulatedPacketId = -1;
}

void DecapsulatePacketEntry::parse(char **tokens, int numTokens)
{
    MessageReferenceEntry::parse(tokens, numTokens);
    encapsulatedPacketId = getInt64Token(tokens, numTokens, "cid", true, encapsulatedPacketId);
}

void DecapsulatePacketEntry::print(FILE *fout)
{
    fprintf(fout, "DE");
    MessageReferenceEntry::print(fout);
    fprintf(fout, " cid %" MSGID_PRINTF_FORMAT "", encapsulatedPacketId);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> DecapsulatePacketEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = MessageReferenceEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("cid");
    return names;
}

const char *DecapsulatePacketEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "cid"))
    {
        sprintf(buffer, "%" MSGID_PRINTF_FORMAT "", encapsulatedPacketId);
        return buffer;
    }
    else
        return MessageReferenceEntry::getAsString(attribute);
}

BeginSendEntry::BeginSendEntry()
    : MessageDescriptionEntry()
{
    sendDelay = 0;
    isUpdate = false;
    transmissionId = -1;
}

BeginSendEntry::BeginSendEntry(IChunk *chunk, int entryIndex)
    : MessageDescriptionEntry(chunk, entryIndex)
{
    sendDelay = 0;
    isUpdate = false;
    transmissionId = -1;
}

void BeginSendEntry::parse(char **tokens, int numTokens)
{
    MessageDescriptionEntry::parse(tokens, numTokens);
    sendDelay = getSimtimeToken(tokens, numTokens, "sd", false, sendDelay);
    isUpdate = getBoolToken(tokens, numTokens, "up", false, isUpdate);
    transmissionId = getInt64Token(tokens, numTokens, "tx", false, transmissionId);
}

void BeginSendEntry::print(FILE *fout)
{
    fprintf(fout, "BS");
    MessageDescriptionEntry::print(fout);
    if (sendDelay != 0)
        fprintf(fout, " sd %s", sendDelay.str(buffer));
    if (isUpdate != false)
        fprintf(fout, " up %d", isUpdate);
    if (transmissionId != -1)
        fprintf(fout, " tx %" TXID_PRINTF_FORMAT "", transmissionId);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> BeginSendEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = MessageDescriptionEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("sd");
    names.push_back("up");
    names.push_back("tx");
    return names;
}

const char *BeginSendEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "sd"))
        return sendDelay.str(buffer);
    else if (!strcmp(attribute, "up"))
    {
        sprintf(buffer, "%d", isUpdate);
        return buffer;
    }
    else if (!strcmp(attribute, "tx"))
    {
        sprintf(buffer, "%" TXID_PRINTF_FORMAT "", transmissionId);
        return buffer;
    }
    else
        return MessageDescriptionEntry::getAsString(attribute);
}

EndSendEntry::EndSendEntry()
    : MessageDescriptionEntry()
{
    isDeliveredImmediately = false;
}

EndSendEntry::EndSendEntry(IChunk *chunk, int entryIndex)
    : MessageDescriptionEntry(chunk, entryIndex)
{
    isDeliveredImmediately = false;
}

void EndSendEntry::parse(char **tokens, int numTokens)
{
    MessageDescriptionEntry::parse(tokens, numTokens);
    isDeliveredImmediately = getBoolToken(tokens, numTokens, "i", false, isDeliveredImmediately);
}

void EndSendEntry::print(FILE *fout)
{
    fprintf(fout, "ES");
    MessageDescriptionEntry::print(fout);
    if (isDeliveredImmediately != false)
        fprintf(fout, " i %d", isDeliveredImmediately);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> EndSendEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = MessageDescriptionEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("i");
    return names;
}

const char *EndSendEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "i"))
    {
        sprintf(buffer, "%d", isDeliveredImmediately);
        return buffer;
    }
    else
        return MessageDescriptionEntry::getAsString(attribute);
}

SendDirectEntry::SendDirectEntry()
{
    this->chunk = nullptr;
    senderModuleId = -1;
    destModuleId = -1;
    destGateId = -1;
    propagationDelay = 0;
    transmissionDelay = 0;
    remainingDuration = 0;
}

SendDirectEntry::SendDirectEntry(IChunk *chunk, int entryIndex)
{
    this->chunk = chunk;
    this->entryIndex = entryIndex;
    senderModuleId = -1;
    destModuleId = -1;
    destGateId = -1;
    propagationDelay = 0;
    transmissionDelay = 0;
    remainingDuration = 0;
}

void SendDirectEntry::parse(char **tokens, int numTokens)
{
    senderModuleId = getIntToken(tokens, numTokens, "sm", true, senderModuleId);
    destModuleId = getIntToken(tokens, numTokens, "dm", true, destModuleId);
    destGateId = getIntToken(tokens, numTokens, "dg", true, destGateId);
    propagationDelay = getSimtimeToken(tokens, numTokens, "pd", false, propagationDelay);
    transmissionDelay = getSimtimeToken(tokens, numTokens, "td", false, transmissionDelay);
    remainingDuration = getSimtimeToken(tokens, numTokens, "rd", false, remainingDuration);
}

void SendDirectEntry::print(FILE *fout)
{
    fprintf(fout, "SD");
    fprintf(fout, " sm %d", senderModuleId);
    fprintf(fout, " dm %d", destModuleId);
    fprintf(fout, " dg %d", destGateId);
    if (propagationDelay != 0)
        fprintf(fout, " pd %s", propagationDelay.str(buffer));
    if (transmissionDelay != 0)
        fprintf(fout, " td %s", transmissionDelay.str(buffer));
    if (remainingDuration != 0)
        fprintf(fout, " rd %s", remainingDuration.str(buffer));
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> SendDirectEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    names.push_back("sm");
    names.push_back("dm");
    names.push_back("dg");
    names.push_back("pd");
    names.push_back("td");
    names.push_back("rd");
    return names;
}

const char *SendDirectEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "sm"))
    {
        sprintf(buffer, "%d", senderModuleId);
        return buffer;
    }
    else if (!strcmp(attribute, "dm"))
    {
        sprintf(buffer, "%d", destModuleId);
        return buffer;
    }
    else if (!strcmp(attribute, "dg"))
    {
        sprintf(buffer, "%d", destGateId);
        return buffer;
    }
    else if (!strcmp(attribute, "pd"))
        return propagationDelay.str(buffer);
    else if (!strcmp(attribute, "td"))
        return transmissionDelay.str(buffer);
    else if (!strcmp(attribute, "rd"))
        return remainingDuration.str(buffer);
    else
        return nullptr;
}

SendHopEntry::SendHopEntry()
{
    this->chunk = nullptr;
    senderModuleId = -1;
    senderGateId = -1;
    propagationDelay = 0;
    transmissionDelay = 0;
    remainingDuration = 0;
    discard = false;
}

SendHopEntry::SendHopEntry(IChunk *chunk, int entryIndex)
{
    this->chunk = chunk;
    this->entryIndex = entryIndex;
    senderModuleId = -1;
    senderGateId = -1;
    propagationDelay = 0;
    transmissionDelay = 0;
    remainingDuration = 0;
    discard = false;
}

void SendHopEntry::parse(char **tokens, int numTokens)
{
    senderModuleId = getIntToken(tokens, numTokens, "sm", true, senderModuleId);
    senderGateId = getIntToken(tokens, numTokens, "sg", true, senderGateId);
    propagationDelay = getSimtimeToken(tokens, numTokens, "pd", false, propagationDelay);
    transmissionDelay = getSimtimeToken(tokens, numTokens, "td", false, transmissionDelay);
    remainingDuration = getSimtimeToken(tokens, numTokens, "rd", false, remainingDuration);
    discard = getBoolToken(tokens, numTokens, "d", false, discard);
}

void SendHopEntry::print(FILE *fout)
{
    fprintf(fout, "SH");
    fprintf(fout, " sm %d", senderModuleId);
    fprintf(fout, " sg %d", senderGateId);
    if (propagationDelay != 0)
        fprintf(fout, " pd %s", propagationDelay.str(buffer));
    if (transmissionDelay != 0)
        fprintf(fout, " td %s", transmissionDelay.str(buffer));
    if (remainingDuration != 0)
        fprintf(fout, " rd %s", remainingDuration.str(buffer));
    if (discard != false)
        fprintf(fout, " d %d", discard);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> SendHopEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    names.push_back("sm");
    names.push_back("sg");
    names.push_back("pd");
    names.push_back("td");
    names.push_back("rd");
    names.push_back("d");
    return names;
}

const char *SendHopEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "sm"))
    {
        sprintf(buffer, "%d", senderModuleId);
        return buffer;
    }
    else if (!strcmp(attribute, "sg"))
    {
        sprintf(buffer, "%d", senderGateId);
        return buffer;
    }
    else if (!strcmp(attribute, "pd"))
        return propagationDelay.str(buffer);
    else if (!strcmp(attribute, "td"))
        return transmissionDelay.str(buffer);
    else if (!strcmp(attribute, "rd"))
        return remainingDuration.str(buffer);
    else if (!strcmp(attribute, "d"))
    {
        sprintf(buffer, "%d", discard);
        return buffer;
    }
    else
        return nullptr;
}

CancelEventEntry::CancelEventEntry()
    : MessageDescriptionEntry()
{
}

CancelEventEntry::CancelEventEntry(IChunk *chunk, int entryIndex)
    : MessageDescriptionEntry(chunk, entryIndex)
{
}

void CancelEventEntry::parse(char **tokens, int numTokens)
{
    MessageDescriptionEntry::parse(tokens, numTokens);
}

void CancelEventEntry::print(FILE *fout)
{
    fprintf(fout, "CE");
    MessageDescriptionEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> CancelEventEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = MessageDescriptionEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *CancelEventEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return MessageDescriptionEntry::getAsString(attribute);
}

ModuleFoundEntry::ModuleFoundEntry()
    : ModuleDescriptionEntry()
{
    lastSeenEventNumber = -1;
    lastSeenEntryIndex = -1;
}

ModuleFoundEntry::ModuleFoundEntry(IChunk *chunk, int entryIndex)
    : ModuleDescriptionEntry(chunk, entryIndex)
{
    lastSeenEventNumber = -1;
    lastSeenEntryIndex = -1;
}

void ModuleFoundEntry::parse(char **tokens, int numTokens)
{
    ModuleDescriptionEntry::parse(tokens, numTokens);
    lastSeenEventNumber = getEventNumberToken(tokens, numTokens, "#", true, lastSeenEventNumber);
    lastSeenEntryIndex = getIntToken(tokens, numTokens, "ei", true, lastSeenEntryIndex);
}

void ModuleFoundEntry::print(FILE *fout)
{
    fprintf(fout, "MF");
    ModuleDescriptionEntry::print(fout);
    fprintf(fout, " # %" EVENTNUMBER_PRINTF_FORMAT "", lastSeenEventNumber);
    fprintf(fout, " ei %d", lastSeenEntryIndex);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> ModuleFoundEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = ModuleDescriptionEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("#");
    names.push_back("ei");
    return names;
}

const char *ModuleFoundEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "#"))
    {
        sprintf(buffer, "%" EVENTNUMBER_PRINTF_FORMAT "", lastSeenEventNumber);
        return buffer;
    }
    else if (!strcmp(attribute, "ei"))
    {
        sprintf(buffer, "%d", lastSeenEntryIndex);
        return buffer;
    }
    else
        return ModuleDescriptionEntry::getAsString(attribute);
}

GateFoundEntry::GateFoundEntry()
    : GateDescriptionEntry()
{
    lastSeenEventNumber = -1;
    lastSeenEntryIndex = -1;
}

GateFoundEntry::GateFoundEntry(IChunk *chunk, int entryIndex)
    : GateDescriptionEntry(chunk, entryIndex)
{
    lastSeenEventNumber = -1;
    lastSeenEntryIndex = -1;
}

void GateFoundEntry::parse(char **tokens, int numTokens)
{
    GateDescriptionEntry::parse(tokens, numTokens);
    lastSeenEventNumber = getEventNumberToken(tokens, numTokens, "#", true, lastSeenEventNumber);
    lastSeenEntryIndex = getIntToken(tokens, numTokens, "ei", true, lastSeenEntryIndex);
}

void GateFoundEntry::print(FILE *fout)
{
    fprintf(fout, "GF");
    GateDescriptionEntry::print(fout);
    fprintf(fout, " # %" EVENTNUMBER_PRINTF_FORMAT "", lastSeenEventNumber);
    fprintf(fout, " ei %d", lastSeenEntryIndex);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> GateFoundEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = GateDescriptionEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("#");
    names.push_back("ei");
    return names;
}

const char *GateFoundEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "#"))
    {
        sprintf(buffer, "%" EVENTNUMBER_PRINTF_FORMAT "", lastSeenEventNumber);
        return buffer;
    }
    else if (!strcmp(attribute, "ei"))
    {
        sprintf(buffer, "%d", lastSeenEntryIndex);
        return buffer;
    }
    else
        return GateDescriptionEntry::getAsString(attribute);
}

ConnectionFoundEntry::ConnectionFoundEntry()
    : ConnectionDescriptionEntry()
{
    lastSeenEventNumber = -1;
    lastSeenEntryIndex = -1;
}

ConnectionFoundEntry::ConnectionFoundEntry(IChunk *chunk, int entryIndex)
    : ConnectionDescriptionEntry(chunk, entryIndex)
{
    lastSeenEventNumber = -1;
    lastSeenEntryIndex = -1;
}

void ConnectionFoundEntry::parse(char **tokens, int numTokens)
{
    ConnectionDescriptionEntry::parse(tokens, numTokens);
    lastSeenEventNumber = getEventNumberToken(tokens, numTokens, "#", true, lastSeenEventNumber);
    lastSeenEntryIndex = getIntToken(tokens, numTokens, "ei", true, lastSeenEntryIndex);
}

void ConnectionFoundEntry::print(FILE *fout)
{
    fprintf(fout, "CF");
    ConnectionDescriptionEntry::print(fout);
    fprintf(fout, " # %" EVENTNUMBER_PRINTF_FORMAT "", lastSeenEventNumber);
    fprintf(fout, " ei %d", lastSeenEntryIndex);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> ConnectionFoundEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = ConnectionDescriptionEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("#");
    names.push_back("ei");
    return names;
}

const char *ConnectionFoundEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "#"))
    {
        sprintf(buffer, "%" EVENTNUMBER_PRINTF_FORMAT "", lastSeenEventNumber);
        return buffer;
    }
    else if (!strcmp(attribute, "ei"))
    {
        sprintf(buffer, "%d", lastSeenEntryIndex);
        return buffer;
    }
    else
        return ConnectionDescriptionEntry::getAsString(attribute);
}

MessageFoundEntry::MessageFoundEntry()
    : MessageDescriptionEntry()
{
}

MessageFoundEntry::MessageFoundEntry(IChunk *chunk, int entryIndex)
    : MessageDescriptionEntry(chunk, entryIndex)
{
}

void MessageFoundEntry::parse(char **tokens, int numTokens)
{
    MessageDescriptionEntry::parse(tokens, numTokens);
}

void MessageFoundEntry::print(FILE *fout)
{
    fprintf(fout, "EF");
    MessageDescriptionEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> MessageFoundEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = MessageDescriptionEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *MessageFoundEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return MessageDescriptionEntry::getAsString(attribute);
}

ModuleDisplayStringFoundEntry::ModuleDisplayStringFoundEntry()
    : ModuleDisplayStringEntry()
{
    lastSeenEventNumber = -1;
    lastSeenEntryIndex = -1;
}

ModuleDisplayStringFoundEntry::ModuleDisplayStringFoundEntry(IChunk *chunk, int entryIndex)
    : ModuleDisplayStringEntry(chunk, entryIndex)
{
    lastSeenEventNumber = -1;
    lastSeenEntryIndex = -1;
}

void ModuleDisplayStringFoundEntry::parse(char **tokens, int numTokens)
{
    ModuleDisplayStringEntry::parse(tokens, numTokens);
    lastSeenEventNumber = getEventNumberToken(tokens, numTokens, "#", true, lastSeenEventNumber);
    lastSeenEntryIndex = getIntToken(tokens, numTokens, "ei", true, lastSeenEntryIndex);
}

void ModuleDisplayStringFoundEntry::print(FILE *fout)
{
    fprintf(fout, "MDF");
    ModuleDisplayStringEntry::print(fout);
    fprintf(fout, " # %" EVENTNUMBER_PRINTF_FORMAT "", lastSeenEventNumber);
    fprintf(fout, " ei %d", lastSeenEntryIndex);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> ModuleDisplayStringFoundEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = ModuleDisplayStringEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("#");
    names.push_back("ei");
    return names;
}

const char *ModuleDisplayStringFoundEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "#"))
    {
        sprintf(buffer, "%" EVENTNUMBER_PRINTF_FORMAT "", lastSeenEventNumber);
        return buffer;
    }
    else if (!strcmp(attribute, "ei"))
    {
        sprintf(buffer, "%d", lastSeenEntryIndex);
        return buffer;
    }
    else
        return ModuleDisplayStringEntry::getAsString(attribute);
}

GateDisplayStringFoundEntry::GateDisplayStringFoundEntry()
    : GateDisplayStringEntry()
{
    lastSeenEventNumber = -1;
    lastSeenEntryIndex = -1;
}

GateDisplayStringFoundEntry::GateDisplayStringFoundEntry(IChunk *chunk, int entryIndex)
    : GateDisplayStringEntry(chunk, entryIndex)
{
    lastSeenEventNumber = -1;
    lastSeenEntryIndex = -1;
}

void GateDisplayStringFoundEntry::parse(char **tokens, int numTokens)
{
    GateDisplayStringEntry::parse(tokens, numTokens);
    lastSeenEventNumber = getEventNumberToken(tokens, numTokens, "#", true, lastSeenEventNumber);
    lastSeenEntryIndex = getIntToken(tokens, numTokens, "ei", true, lastSeenEntryIndex);
}

void GateDisplayStringFoundEntry::print(FILE *fout)
{
    fprintf(fout, "GDF");
    GateDisplayStringEntry::print(fout);
    fprintf(fout, " # %" EVENTNUMBER_PRINTF_FORMAT "", lastSeenEventNumber);
    fprintf(fout, " ei %d", lastSeenEntryIndex);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> GateDisplayStringFoundEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = GateDisplayStringEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("#");
    names.push_back("ei");
    return names;
}

const char *GateDisplayStringFoundEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "#"))
    {
        sprintf(buffer, "%" EVENTNUMBER_PRINTF_FORMAT "", lastSeenEventNumber);
        return buffer;
    }
    else if (!strcmp(attribute, "ei"))
    {
        sprintf(buffer, "%d", lastSeenEntryIndex);
        return buffer;
    }
    else
        return GateDisplayStringEntry::getAsString(attribute);
}

ConnectionDisplayStringFoundEntry::ConnectionDisplayStringFoundEntry()
    : ConnectionDisplayStringEntry()
{
    lastSeenEventNumber = -1;
    lastSeenEntryIndex = -1;
}

ConnectionDisplayStringFoundEntry::ConnectionDisplayStringFoundEntry(IChunk *chunk, int entryIndex)
    : ConnectionDisplayStringEntry(chunk, entryIndex)
{
    lastSeenEventNumber = -1;
    lastSeenEntryIndex = -1;
}

void ConnectionDisplayStringFoundEntry::parse(char **tokens, int numTokens)
{
    ConnectionDisplayStringEntry::parse(tokens, numTokens);
    lastSeenEventNumber = getEventNumberToken(tokens, numTokens, "#", true, lastSeenEventNumber);
    lastSeenEntryIndex = getIntToken(tokens, numTokens, "ei", true, lastSeenEntryIndex);
}

void ConnectionDisplayStringFoundEntry::print(FILE *fout)
{
    fprintf(fout, "CDF");
    ConnectionDisplayStringEntry::print(fout);
    fprintf(fout, " # %" EVENTNUMBER_PRINTF_FORMAT "", lastSeenEventNumber);
    fprintf(fout, " ei %d", lastSeenEntryIndex);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> ConnectionDisplayStringFoundEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = ConnectionDisplayStringEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("#");
    names.push_back("ei");
    return names;
}

const char *ConnectionDisplayStringFoundEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "#"))
    {
        sprintf(buffer, "%" EVENTNUMBER_PRINTF_FORMAT "", lastSeenEventNumber);
        return buffer;
    }
    else if (!strcmp(attribute, "ei"))
    {
        sprintf(buffer, "%d", lastSeenEntryIndex);
        return buffer;
    }
    else
        return ConnectionDisplayStringEntry::getAsString(attribute);
}

MessageDisplayStringFoundEntry::MessageDisplayStringFoundEntry()
    : MessageDisplayStringEntry()
{
    lastSeenEventNumber = -1;
    lastSeenEntryIndex = -1;
}

MessageDisplayStringFoundEntry::MessageDisplayStringFoundEntry(IChunk *chunk, int entryIndex)
    : MessageDisplayStringEntry(chunk, entryIndex)
{
    lastSeenEventNumber = -1;
    lastSeenEntryIndex = -1;
}

void MessageDisplayStringFoundEntry::parse(char **tokens, int numTokens)
{
    MessageDisplayStringEntry::parse(tokens, numTokens);
    lastSeenEventNumber = getEventNumberToken(tokens, numTokens, "#", true, lastSeenEventNumber);
    lastSeenEntryIndex = getIntToken(tokens, numTokens, "ei", true, lastSeenEntryIndex);
}

void MessageDisplayStringFoundEntry::print(FILE *fout)
{
    fprintf(fout, "EDF");
    MessageDisplayStringEntry::print(fout);
    fprintf(fout, " # %" EVENTNUMBER_PRINTF_FORMAT "", lastSeenEventNumber);
    fprintf(fout, " ei %d", lastSeenEntryIndex);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> MessageDisplayStringFoundEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = MessageDisplayStringEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("#");
    names.push_back("ei");
    return names;
}

const char *MessageDisplayStringFoundEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "#"))
    {
        sprintf(buffer, "%" EVENTNUMBER_PRINTF_FORMAT "", lastSeenEventNumber);
        return buffer;
    }
    else if (!strcmp(attribute, "ei"))
    {
        sprintf(buffer, "%d", lastSeenEntryIndex);
        return buffer;
    }
    else
        return MessageDisplayStringEntry::getAsString(attribute);
}

BubbleEntry::BubbleEntry()
{
    this->chunk = nullptr;
    moduleId = -1;
    text = nullptr;
}

BubbleEntry::BubbleEntry(IChunk *chunk, int entryIndex)
{
    this->chunk = chunk;
    this->entryIndex = entryIndex;
    moduleId = -1;
    text = nullptr;
}

void BubbleEntry::parse(char **tokens, int numTokens)
{
    moduleId = getIntToken(tokens, numTokens, "id", true, moduleId);
    text = getStringToken(tokens, numTokens, "txt", true, text);
}

void BubbleEntry::print(FILE *fout)
{
    fprintf(fout, "BU");
    fprintf(fout, " id %d", moduleId);
    fprintf(fout, " txt %s", QUOTE(text));
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> BubbleEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    names.push_back("id");
    names.push_back("txt");
    return names;
}

const char *BubbleEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "id"))
    {
        sprintf(buffer, "%d", moduleId);
        return buffer;
    }
    else if (!strcmp(attribute, "txt"))
        return text;
    else
        return nullptr;
}

CustomReferenceEntry::CustomReferenceEntry()
{
    this->chunk = nullptr;
    type = nullptr;
    key = -1;
}

CustomReferenceEntry::CustomReferenceEntry(IChunk *chunk, int entryIndex)
{
    this->chunk = chunk;
    this->entryIndex = entryIndex;
    type = nullptr;
    key = -1;
}

void CustomReferenceEntry::parse(char **tokens, int numTokens)
{
    type = getStringToken(tokens, numTokens, "t", true, type);
    key = getLongToken(tokens, numTokens, "k", true, key);
}

void CustomReferenceEntry::print(FILE *fout)
{
    fprintf(fout, " t %s", QUOTE(type));
    fprintf(fout, " k %ld", key);
    fflush(fout);
}

const std::vector<const char *> CustomReferenceEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    names.push_back("t");
    names.push_back("k");
    return names;
}

const char *CustomReferenceEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "t"))
        return type;
    else if (!strcmp(attribute, "k"))
    {
        sprintf(buffer, "%ld", key);
        return buffer;
    }
    else
        return nullptr;
}

CustomDescriptionEntry::CustomDescriptionEntry()
    : CustomReferenceEntry()
{
    content = nullptr;
}

CustomDescriptionEntry::CustomDescriptionEntry(IChunk *chunk, int entryIndex)
    : CustomReferenceEntry(chunk, entryIndex)
{
    content = nullptr;
}

void CustomDescriptionEntry::parse(char **tokens, int numTokens)
{
    CustomReferenceEntry::parse(tokens, numTokens);
    content = getStringToken(tokens, numTokens, "c", true, content);
}

void CustomDescriptionEntry::print(FILE *fout)
{
    CustomReferenceEntry::print(fout);
    fprintf(fout, " c %s", QUOTE(content));
    fflush(fout);
}

const std::vector<const char *> CustomDescriptionEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = CustomReferenceEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("c");
    return names;
}

const char *CustomDescriptionEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "c"))
        return content;
    else
        return CustomReferenceEntry::getAsString(attribute);
}

CustomCreatedEntry::CustomCreatedEntry()
    : CustomDescriptionEntry()
{
}

CustomCreatedEntry::CustomCreatedEntry(IChunk *chunk, int entryIndex)
    : CustomDescriptionEntry(chunk, entryIndex)
{
}

void CustomCreatedEntry::parse(char **tokens, int numTokens)
{
    CustomDescriptionEntry::parse(tokens, numTokens);
}

void CustomCreatedEntry::print(FILE *fout)
{
    fprintf(fout, "CUC");
    CustomDescriptionEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> CustomCreatedEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = CustomDescriptionEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *CustomCreatedEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return CustomDescriptionEntry::getAsString(attribute);
}

CustomDeletedEntry::CustomDeletedEntry()
    : CustomReferenceEntry()
{
}

CustomDeletedEntry::CustomDeletedEntry(IChunk *chunk, int entryIndex)
    : CustomReferenceEntry(chunk, entryIndex)
{
}

void CustomDeletedEntry::parse(char **tokens, int numTokens)
{
    CustomReferenceEntry::parse(tokens, numTokens);
}

void CustomDeletedEntry::print(FILE *fout)
{
    fprintf(fout, "CUD");
    CustomReferenceEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> CustomDeletedEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = CustomReferenceEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *CustomDeletedEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return CustomReferenceEntry::getAsString(attribute);
}

CustomChangedEntry::CustomChangedEntry()
    : CustomDescriptionEntry()
{
}

CustomChangedEntry::CustomChangedEntry(IChunk *chunk, int entryIndex)
    : CustomDescriptionEntry(chunk, entryIndex)
{
}

void CustomChangedEntry::parse(char **tokens, int numTokens)
{
    CustomDescriptionEntry::parse(tokens, numTokens);
}

void CustomChangedEntry::print(FILE *fout)
{
    fprintf(fout, "CUM");
    CustomDescriptionEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> CustomChangedEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = CustomDescriptionEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *CustomChangedEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return CustomDescriptionEntry::getAsString(attribute);
}

CustomFoundEntry::CustomFoundEntry()
    : CustomDescriptionEntry()
{
    lastSeenEventNumber = -1;
    lastSeenEntryIndex = -1;
}

CustomFoundEntry::CustomFoundEntry(IChunk *chunk, int entryIndex)
    : CustomDescriptionEntry(chunk, entryIndex)
{
    lastSeenEventNumber = -1;
    lastSeenEntryIndex = -1;
}

void CustomFoundEntry::parse(char **tokens, int numTokens)
{
    CustomDescriptionEntry::parse(tokens, numTokens);
    lastSeenEventNumber = getEventNumberToken(tokens, numTokens, "#", true, lastSeenEventNumber);
    lastSeenEntryIndex = getIntToken(tokens, numTokens, "ei", true, lastSeenEntryIndex);
}

void CustomFoundEntry::print(FILE *fout)
{
    fprintf(fout, "CUF");
    CustomDescriptionEntry::print(fout);
    fprintf(fout, " # %" EVENTNUMBER_PRINTF_FORMAT "", lastSeenEventNumber);
    fprintf(fout, " ei %d", lastSeenEntryIndex);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> CustomFoundEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = CustomDescriptionEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    names.push_back("#");
    names.push_back("ei");
    return names;
}

const char *CustomFoundEntry::getAsString(const char *attribute) const
{
    if (false);
    else if (!strcmp(attribute, "#"))
    {
        sprintf(buffer, "%" EVENTNUMBER_PRINTF_FORMAT "", lastSeenEventNumber);
        return buffer;
    }
    else if (!strcmp(attribute, "ei"))
    {
        sprintf(buffer, "%d", lastSeenEntryIndex);
        return buffer;
    }
    else
        return CustomDescriptionEntry::getAsString(attribute);
}

CustomEntry::CustomEntry()
    : CustomDescriptionEntry()
{
}

CustomEntry::CustomEntry(IChunk *chunk, int entryIndex)
    : CustomDescriptionEntry(chunk, entryIndex)
{
}

void CustomEntry::parse(char **tokens, int numTokens)
{
    CustomDescriptionEntry::parse(tokens, numTokens);
}

void CustomEntry::print(FILE *fout)
{
    fprintf(fout, "CU");
    CustomDescriptionEntry::print(fout);
    fprintf(fout, "\n");
    fflush(fout);
}

const std::vector<const char *> CustomEntry::getAttributeNames() const
{
    std::vector<const char *> names;
    std::vector<const char *> superNames = CustomDescriptionEntry::getAttributeNames();
    names.insert(names.begin(), superNames.begin(), superNames.end());
    return names;
}

const char *CustomEntry::getAsString(const char *attribute) const
{
    if (false);
    else
        return CustomDescriptionEntry::getAsString(attribute);
}

} // namespace eventlog
} // namespace omnetpp
