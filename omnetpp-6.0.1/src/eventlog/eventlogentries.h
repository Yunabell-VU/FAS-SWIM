//=========================================================================
//  EVENTLOGENTRIES.H - part of
//                  OMNeT++/OMNEST
//           Discrete System Simulation in C++
//
//  This is a generated file -- do not modify.
//
//=========================================================================

#ifndef __OMNETPP_EVENTLOG_EVENTLOGENTRIES_H
#define __OMNETPP_EVENTLOG_EVENTLOGENTRIES_H

#include <cstdio>
#include "eventlogdefs.h"
#include "eventlogentry.h"

namespace omnetpp {
namespace eventlog {

class Event;


class EVENTLOG_API SimulationBeginEntry : public EventLogTokenBasedEntry
{
   public:
      SimulationBeginEntry();
      SimulationBeginEntry(IChunk *chunk, int entryIndex);

   public:
      int omnetppVersion;
      int eventlogVersion;
      const char * runId;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 1; }
      virtual const char *getAsString() const override { return "SB"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "SimulationBeginEntry"; }
};

class EVENTLOG_API SimulationEndEntry : public EventLogTokenBasedEntry
{
   public:
      SimulationEndEntry();
      SimulationEndEntry(IChunk *chunk, int entryIndex);

   public:
      bool isError;
      int resultCode;
      const char * message;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 2; }
      virtual const char *getAsString() const override { return "SE"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "SimulationEndEntry"; }
};

class EVENTLOG_API EventEntry : public EventLogTokenBasedEntry
{
   public:
      EventEntry();
      EventEntry(IChunk *chunk, int entryIndex);

   public:
      eventnumber_t eventNumber;
      simtime_t simulationTime;
      int moduleId;
      eventnumber_t causeEventNumber;
      msgid_t messageId;
      const char * fingerprints;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 3; }
      virtual const char *getAsString() const override { return "E"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "EventEntry"; }
};

class EVENTLOG_API SnapshotEntry : public EventLogTokenBasedEntry
{
   public:
      SnapshotEntry();
      SnapshotEntry(IChunk *chunk, int entryIndex);

   public:
      int64_t fileOffset;
      eventnumber_t eventNumber;
      simtime_t simulationTime;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 4; }
      virtual const char *getAsString() const override { return "S"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "SnapshotEntry"; }
};

class EVENTLOG_API IndexEntry : public EventLogTokenBasedEntry
{
   public:
      IndexEntry();
      IndexEntry(IChunk *chunk, int entryIndex);

   public:
      int64_t fileOffset;
      int64_t previousIndexFileOffset;
      int64_t previousSnapshotFileOffset;
      eventnumber_t eventNumber;
      simtime_t simulationTime;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 5; }
      virtual const char *getAsString() const override { return "I"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "IndexEntry"; }
};

class EVENTLOG_API ReferenceEntry : public EventLogTokenBasedEntry
{
   public:
      ReferenceEntry();
      ReferenceEntry(IChunk *chunk, int entryIndex);

   public:
      eventnumber_t eventNumber;
      int beginEntryIndex;
      int endEntryIndex;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 6; }
      virtual const char *getAsString() const override { return "abstract"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ReferenceEntry"; }
};

class EVENTLOG_API ReferenceFoundEntry : public ReferenceEntry
{
   public:
      ReferenceFoundEntry();
      ReferenceFoundEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 7; }
      virtual const char *getAsString() const override { return "RF"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ReferenceFoundEntry"; }
};

class EVENTLOG_API ReferenceAddedEntry : public ReferenceEntry
{
   public:
      ReferenceAddedEntry();
      ReferenceAddedEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 8; }
      virtual const char *getAsString() const override { return "RA"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ReferenceAddedEntry"; }
};

class EVENTLOG_API ReferenceRemovedEntry : public ReferenceEntry
{
   public:
      ReferenceRemovedEntry();
      ReferenceRemovedEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 9; }
      virtual const char *getAsString() const override { return "RR"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ReferenceRemovedEntry"; }
};

class EVENTLOG_API ModuleReferenceEntry : public EventLogTokenBasedEntry
{
   public:
      ModuleReferenceEntry();
      ModuleReferenceEntry(IChunk *chunk, int entryIndex);

   public:
      int moduleId;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 10; }
      virtual const char *getAsString() const override { return "abstract"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ModuleReferenceEntry"; }
};

class EVENTLOG_API GateReferenceEntry : public EventLogTokenBasedEntry
{
   public:
      GateReferenceEntry();
      GateReferenceEntry(IChunk *chunk, int entryIndex);

   public:
      int moduleId;
      int gateId;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 11; }
      virtual const char *getAsString() const override { return "abstract"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "GateReferenceEntry"; }
};

class EVENTLOG_API ConnectionReferenceEntry : public EventLogTokenBasedEntry
{
   public:
      ConnectionReferenceEntry();
      ConnectionReferenceEntry(IChunk *chunk, int entryIndex);

   public:
      int sourceModuleId;
      int sourceGateId;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 12; }
      virtual const char *getAsString() const override { return "abstract"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ConnectionReferenceEntry"; }
};

class EVENTLOG_API MessageReferenceEntry : public EventLogTokenBasedEntry
{
   public:
      MessageReferenceEntry();
      MessageReferenceEntry(IChunk *chunk, int entryIndex);

   public:
      msgid_t messageId;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 13; }
      virtual const char *getAsString() const override { return "abstract"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "MessageReferenceEntry"; }
};

class EVENTLOG_API ModuleDescriptionEntry : public ModuleReferenceEntry
{
   public:
      ModuleDescriptionEntry();
      ModuleDescriptionEntry(IChunk *chunk, int entryIndex);

   public:
      const char * moduleClassName;
      const char * nedTypeName;
      int parentModuleId;
      const char * fullName;
      bool compoundModule;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 14; }
      virtual const char *getAsString() const override { return "abstract"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ModuleDescriptionEntry"; }
};

class EVENTLOG_API GateDescriptionEntry : public GateReferenceEntry
{
   public:
      GateDescriptionEntry();
      GateDescriptionEntry(IChunk *chunk, int entryIndex);

   public:
      const char * name;
      int index;
      bool isOutput;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 15; }
      virtual const char *getAsString() const override { return "abstract"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "GateDescriptionEntry"; }
};

class EVENTLOG_API ConnectionDescriptionEntry : public ConnectionReferenceEntry
{
   public:
      ConnectionDescriptionEntry();
      ConnectionDescriptionEntry(IChunk *chunk, int entryIndex);

   public:
      int destModuleId;
      int destGateId;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 16; }
      virtual const char *getAsString() const override { return "abstract"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ConnectionDescriptionEntry"; }
};

class EVENTLOG_API MessageDescriptionEntry : public MessageReferenceEntry
{
   public:
      MessageDescriptionEntry();
      MessageDescriptionEntry(IChunk *chunk, int entryIndex);

   public:
      msgid_t messageTreeId;
      msgid_t messageEncapsulationId;
      msgid_t messageEncapsulationTreeId;
      const char * messageClassName;
      const char * messageName;
      short messageKind;
      short messagePriority;
      int64_t messageLength;
      bool hasBitError;
      int ownerModuleId;
      int senderModuleId;
      int senderGateId;
      simtime_t sendingTime;
      int arrivalModuleId;
      int arrivalGateId;
      simtime_t arrivalTime;
      const char * detail;
      eventnumber_t previousEventNumber;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 17; }
      virtual const char *getAsString() const override { return "abstract"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "MessageDescriptionEntry"; }
};

class EVENTLOG_API ModuleDisplayStringEntry : public ModuleReferenceEntry
{
   public:
      ModuleDisplayStringEntry();
      ModuleDisplayStringEntry(IChunk *chunk, int entryIndex);

   public:
      const char * displayString;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 18; }
      virtual const char *getAsString() const override { return "abstract"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ModuleDisplayStringEntry"; }
};

class EVENTLOG_API GateDisplayStringEntry : public GateReferenceEntry
{
   public:
      GateDisplayStringEntry();
      GateDisplayStringEntry(IChunk *chunk, int entryIndex);

   public:
      const char * displayString;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 19; }
      virtual const char *getAsString() const override { return "abstract"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "GateDisplayStringEntry"; }
};

class EVENTLOG_API ConnectionDisplayStringEntry : public ConnectionReferenceEntry
{
   public:
      ConnectionDisplayStringEntry();
      ConnectionDisplayStringEntry(IChunk *chunk, int entryIndex);

   public:
      const char * displayString;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 20; }
      virtual const char *getAsString() const override { return "abstract"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ConnectionDisplayStringEntry"; }
};

class EVENTLOG_API MessageDisplayStringEntry : public MessageReferenceEntry
{
   public:
      MessageDisplayStringEntry();
      MessageDisplayStringEntry(IChunk *chunk, int entryIndex);

   public:
      const char * displayString;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 21; }
      virtual const char *getAsString() const override { return "abstract"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "MessageDisplayStringEntry"; }
};

class EVENTLOG_API ComponentMethodBeginEntry : public EventLogTokenBasedEntry
{
   public:
      ComponentMethodBeginEntry();
      ComponentMethodBeginEntry(IChunk *chunk, int entryIndex);

   public:
      int sourceComponentId;
      int targetComponentId;
      const char * methodName;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 22; }
      virtual const char *getAsString() const override { return "CMB"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ComponentMethodBeginEntry"; }
};

class EVENTLOG_API ComponentMethodEndEntry : public EventLogTokenBasedEntry
{
   public:
      ComponentMethodEndEntry();
      ComponentMethodEndEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 23; }
      virtual const char *getAsString() const override { return "CME"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ComponentMethodEndEntry"; }
};

class EVENTLOG_API ModuleCreatedEntry : public ModuleDescriptionEntry
{
   public:
      ModuleCreatedEntry();
      ModuleCreatedEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 24; }
      virtual const char *getAsString() const override { return "MC"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ModuleCreatedEntry"; }
};

class EVENTLOG_API ModuleDeletedEntry : public ModuleReferenceEntry
{
   public:
      ModuleDeletedEntry();
      ModuleDeletedEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 25; }
      virtual const char *getAsString() const override { return "MD"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ModuleDeletedEntry"; }
};

class EVENTLOG_API GateCreatedEntry : public GateDescriptionEntry
{
   public:
      GateCreatedEntry();
      GateCreatedEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 26; }
      virtual const char *getAsString() const override { return "GC"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "GateCreatedEntry"; }
};

class EVENTLOG_API GateDeletedEntry : public GateReferenceEntry
{
   public:
      GateDeletedEntry();
      GateDeletedEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 27; }
      virtual const char *getAsString() const override { return "GD"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "GateDeletedEntry"; }
};

class EVENTLOG_API ConnectionCreatedEntry : public ConnectionDescriptionEntry
{
   public:
      ConnectionCreatedEntry();
      ConnectionCreatedEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 28; }
      virtual const char *getAsString() const override { return "CC"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ConnectionCreatedEntry"; }
};

class EVENTLOG_API ConnectionDeletedEntry : public ConnectionReferenceEntry
{
   public:
      ConnectionDeletedEntry();
      ConnectionDeletedEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 29; }
      virtual const char *getAsString() const override { return "CD"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ConnectionDeletedEntry"; }
};

class EVENTLOG_API ModuleDisplayStringChangedEntry : public ModuleDisplayStringEntry
{
   public:
      ModuleDisplayStringChangedEntry();
      ModuleDisplayStringChangedEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 30; }
      virtual const char *getAsString() const override { return "MDC"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ModuleDisplayStringChangedEntry"; }
};

class EVENTLOG_API GateDisplayStringChangedEntry : public GateDisplayStringEntry
{
   public:
      GateDisplayStringChangedEntry();
      GateDisplayStringChangedEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 31; }
      virtual const char *getAsString() const override { return "GDC"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "GateDisplayStringChangedEntry"; }
};

class EVENTLOG_API ConnectionDisplayStringChangedEntry : public ConnectionDisplayStringEntry
{
   public:
      ConnectionDisplayStringChangedEntry();
      ConnectionDisplayStringChangedEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 32; }
      virtual const char *getAsString() const override { return "CDC"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ConnectionDisplayStringChangedEntry"; }
};

class EVENTLOG_API MessageDisplayStringChangedEntry : public MessageDisplayStringEntry
{
   public:
      MessageDisplayStringChangedEntry();
      MessageDisplayStringChangedEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 33; }
      virtual const char *getAsString() const override { return "EDC"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "MessageDisplayStringChangedEntry"; }
};

class EVENTLOG_API CreateMessageEntry : public MessageDescriptionEntry
{
   public:
      CreateMessageEntry();
      CreateMessageEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 34; }
      virtual const char *getAsString() const override { return "CM"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "CreateMessageEntry"; }
};

class EVENTLOG_API CloneMessageEntry : public MessageDescriptionEntry
{
   public:
      CloneMessageEntry();
      CloneMessageEntry(IChunk *chunk, int entryIndex);

   public:
      msgid_t cloneId;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 35; }
      virtual const char *getAsString() const override { return "CL"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "CloneMessageEntry"; }
};

class EVENTLOG_API DeleteMessageEntry : public MessageDescriptionEntry
{
   public:
      DeleteMessageEntry();
      DeleteMessageEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 36; }
      virtual const char *getAsString() const override { return "DM"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "DeleteMessageEntry"; }
};

class EVENTLOG_API EncapsulatePacketEntry : public MessageReferenceEntry
{
   public:
      EncapsulatePacketEntry();
      EncapsulatePacketEntry(IChunk *chunk, int entryIndex);

   public:
      msgid_t encapsulatedPacketId;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 37; }
      virtual const char *getAsString() const override { return "EN"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "EncapsulatePacketEntry"; }
};

class EVENTLOG_API DecapsulatePacketEntry : public MessageReferenceEntry
{
   public:
      DecapsulatePacketEntry();
      DecapsulatePacketEntry(IChunk *chunk, int entryIndex);

   public:
      msgid_t encapsulatedPacketId;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 38; }
      virtual const char *getAsString() const override { return "DE"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "DecapsulatePacketEntry"; }
};

class EVENTLOG_API BeginSendEntry : public MessageDescriptionEntry
{
   public:
      BeginSendEntry();
      BeginSendEntry(IChunk *chunk, int entryIndex);

   public:
      simtime_t sendDelay;
      bool isUpdate;
      txid_t transmissionId;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 39; }
      virtual const char *getAsString() const override { return "BS"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "BeginSendEntry"; }
};

class EVENTLOG_API EndSendEntry : public MessageDescriptionEntry
{
   public:
      EndSendEntry();
      EndSendEntry(IChunk *chunk, int entryIndex);

   public:
      bool isDeliveredImmediately;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 40; }
      virtual const char *getAsString() const override { return "ES"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "EndSendEntry"; }
};

class EVENTLOG_API SendDirectEntry : public EventLogTokenBasedEntry
{
   public:
      SendDirectEntry();
      SendDirectEntry(IChunk *chunk, int entryIndex);

   public:
      int senderModuleId;
      int destModuleId;
      int destGateId;
      simtime_t propagationDelay;
      simtime_t transmissionDelay;
      simtime_t remainingDuration;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 41; }
      virtual const char *getAsString() const override { return "SD"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "SendDirectEntry"; }
};

class EVENTLOG_API SendHopEntry : public EventLogTokenBasedEntry
{
   public:
      SendHopEntry();
      SendHopEntry(IChunk *chunk, int entryIndex);

   public:
      int senderModuleId;
      int senderGateId;
      simtime_t propagationDelay;
      simtime_t transmissionDelay;
      simtime_t remainingDuration;
      bool discard;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 42; }
      virtual const char *getAsString() const override { return "SH"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "SendHopEntry"; }
};

class EVENTLOG_API CancelEventEntry : public MessageDescriptionEntry
{
   public:
      CancelEventEntry();
      CancelEventEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 43; }
      virtual const char *getAsString() const override { return "CE"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "CancelEventEntry"; }
};

class EVENTLOG_API ModuleFoundEntry : public ModuleDescriptionEntry
{
   public:
      ModuleFoundEntry();
      ModuleFoundEntry(IChunk *chunk, int entryIndex);

   public:
      eventnumber_t lastSeenEventNumber;
      int lastSeenEntryIndex;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 44; }
      virtual const char *getAsString() const override { return "MF"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ModuleFoundEntry"; }
};

class EVENTLOG_API GateFoundEntry : public GateDescriptionEntry
{
   public:
      GateFoundEntry();
      GateFoundEntry(IChunk *chunk, int entryIndex);

   public:
      eventnumber_t lastSeenEventNumber;
      int lastSeenEntryIndex;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 45; }
      virtual const char *getAsString() const override { return "GF"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "GateFoundEntry"; }
};

class EVENTLOG_API ConnectionFoundEntry : public ConnectionDescriptionEntry
{
   public:
      ConnectionFoundEntry();
      ConnectionFoundEntry(IChunk *chunk, int entryIndex);

   public:
      eventnumber_t lastSeenEventNumber;
      int lastSeenEntryIndex;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 46; }
      virtual const char *getAsString() const override { return "CF"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ConnectionFoundEntry"; }
};

class EVENTLOG_API MessageFoundEntry : public MessageDescriptionEntry
{
   public:
      MessageFoundEntry();
      MessageFoundEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 47; }
      virtual const char *getAsString() const override { return "EF"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "MessageFoundEntry"; }
};

class EVENTLOG_API ModuleDisplayStringFoundEntry : public ModuleDisplayStringEntry
{
   public:
      ModuleDisplayStringFoundEntry();
      ModuleDisplayStringFoundEntry(IChunk *chunk, int entryIndex);

   public:
      eventnumber_t lastSeenEventNumber;
      int lastSeenEntryIndex;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 48; }
      virtual const char *getAsString() const override { return "MDF"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ModuleDisplayStringFoundEntry"; }
};

class EVENTLOG_API GateDisplayStringFoundEntry : public GateDisplayStringEntry
{
   public:
      GateDisplayStringFoundEntry();
      GateDisplayStringFoundEntry(IChunk *chunk, int entryIndex);

   public:
      eventnumber_t lastSeenEventNumber;
      int lastSeenEntryIndex;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 49; }
      virtual const char *getAsString() const override { return "GDF"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "GateDisplayStringFoundEntry"; }
};

class EVENTLOG_API ConnectionDisplayStringFoundEntry : public ConnectionDisplayStringEntry
{
   public:
      ConnectionDisplayStringFoundEntry();
      ConnectionDisplayStringFoundEntry(IChunk *chunk, int entryIndex);

   public:
      eventnumber_t lastSeenEventNumber;
      int lastSeenEntryIndex;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 50; }
      virtual const char *getAsString() const override { return "CDF"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "ConnectionDisplayStringFoundEntry"; }
};

class EVENTLOG_API MessageDisplayStringFoundEntry : public MessageDisplayStringEntry
{
   public:
      MessageDisplayStringFoundEntry();
      MessageDisplayStringFoundEntry(IChunk *chunk, int entryIndex);

   public:
      eventnumber_t lastSeenEventNumber;
      int lastSeenEntryIndex;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 51; }
      virtual const char *getAsString() const override { return "EDF"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "MessageDisplayStringFoundEntry"; }
};

class EVENTLOG_API BubbleEntry : public EventLogTokenBasedEntry
{
   public:
      BubbleEntry();
      BubbleEntry(IChunk *chunk, int entryIndex);

   public:
      int moduleId;
      const char * text;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 52; }
      virtual const char *getAsString() const override { return "BU"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "BubbleEntry"; }
};

class EVENTLOG_API CustomReferenceEntry : public EventLogTokenBasedEntry
{
   public:
      CustomReferenceEntry();
      CustomReferenceEntry(IChunk *chunk, int entryIndex);

   public:
      const char * type;
      long key;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 53; }
      virtual const char *getAsString() const override { return "abstract"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "CustomReferenceEntry"; }
};

class EVENTLOG_API CustomDescriptionEntry : public CustomReferenceEntry
{
   public:
      CustomDescriptionEntry();
      CustomDescriptionEntry(IChunk *chunk, int entryIndex);

   public:
      const char * content;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 54; }
      virtual const char *getAsString() const override { return "abstract"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "CustomDescriptionEntry"; }
};

class EVENTLOG_API CustomCreatedEntry : public CustomDescriptionEntry
{
   public:
      CustomCreatedEntry();
      CustomCreatedEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 55; }
      virtual const char *getAsString() const override { return "CUC"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "CustomCreatedEntry"; }
};

class EVENTLOG_API CustomDeletedEntry : public CustomReferenceEntry
{
   public:
      CustomDeletedEntry();
      CustomDeletedEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 56; }
      virtual const char *getAsString() const override { return "CUD"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "CustomDeletedEntry"; }
};

class EVENTLOG_API CustomChangedEntry : public CustomDescriptionEntry
{
   public:
      CustomChangedEntry();
      CustomChangedEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 57; }
      virtual const char *getAsString() const override { return "CUM"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "CustomChangedEntry"; }
};

class EVENTLOG_API CustomFoundEntry : public CustomDescriptionEntry
{
   public:
      CustomFoundEntry();
      CustomFoundEntry(IChunk *chunk, int entryIndex);

   public:
      eventnumber_t lastSeenEventNumber;
      int lastSeenEntryIndex;

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 58; }
      virtual const char *getAsString() const override { return "CUF"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "CustomFoundEntry"; }
};

class EVENTLOG_API CustomEntry : public CustomDescriptionEntry
{
   public:
      CustomEntry();
      CustomEntry(IChunk *chunk, int entryIndex);

   public:

   public:
      virtual void parse(char **tokens, int numTokens) override;
      virtual void print(FILE *file) override;
      virtual int getClassIndex() override { return 59; }
      virtual const char *getAsString() const override { return "CU"; }
      virtual const std::vector<const char *> getAttributeNames() const override;
      virtual const char *getAsString(const char *attribute) const override; // BEWARE: Returns pointer into a static buffer which gets overwritten with each call!
      virtual const char *getClassName() override { return "CustomEntry"; }
};

} // namespace eventlog
} // namespace omnetpp

#endif
