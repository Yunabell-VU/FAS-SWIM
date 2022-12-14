//=========================================================================
//  EVENTLOGENTRYFACTORY.CC - part of
//                  OMNeT++/OMNEST
//           Discrete System Simulation in C++
//
//  This is a generated file -- do not modify.
//
//=========================================================================

#include <cstdio>
#include "event.h"
#include "eventlogentryfactory.h"

namespace omnetpp {
namespace eventlog {

EventLogTokenBasedEntry *EventLogEntryFactory::parseEntry(IChunk *chunk, int entryIndex, char **tokens, int numTokens)
{
    if (numTokens < 1)
        return nullptr;

    char *code = tokens[0];
    EventLogTokenBasedEntry *entry;

    if (false)
        ;
    else if (code[0]=='S' && code[1]=='B' && code[2]==0)  // SB
        entry = new SimulationBeginEntry(chunk, entryIndex);
    else if (code[0]=='S' && code[1]=='E' && code[2]==0)  // SE
        entry = new SimulationEndEntry(chunk, entryIndex);
    else if (code[0]=='E' && code[1]==0)  // E
        entry = new EventEntry(chunk, entryIndex);
    else if (code[0]=='S' && code[1]==0)  // S
        entry = new SnapshotEntry(chunk, entryIndex);
    else if (code[0]=='I' && code[1]==0)  // I
        entry = new IndexEntry(chunk, entryIndex);
    else if (code[0]=='R' && code[1]=='F' && code[2]==0)  // RF
        entry = new ReferenceFoundEntry(chunk, entryIndex);
    else if (code[0]=='R' && code[1]=='A' && code[2]==0)  // RA
        entry = new ReferenceAddedEntry(chunk, entryIndex);
    else if (code[0]=='R' && code[1]=='R' && code[2]==0)  // RR
        entry = new ReferenceRemovedEntry(chunk, entryIndex);
    else if (code[0]=='C' && code[1]=='M' && code[2]=='B' && code[3]==0)  // CMB
        entry = new ComponentMethodBeginEntry(chunk, entryIndex);
    else if (code[0]=='C' && code[1]=='M' && code[2]=='E' && code[3]==0)  // CME
        entry = new ComponentMethodEndEntry(chunk, entryIndex);
    else if (code[0]=='M' && code[1]=='C' && code[2]==0)  // MC
        entry = new ModuleCreatedEntry(chunk, entryIndex);
    else if (code[0]=='M' && code[1]=='D' && code[2]==0)  // MD
        entry = new ModuleDeletedEntry(chunk, entryIndex);
    else if (code[0]=='G' && code[1]=='C' && code[2]==0)  // GC
        entry = new GateCreatedEntry(chunk, entryIndex);
    else if (code[0]=='G' && code[1]=='D' && code[2]==0)  // GD
        entry = new GateDeletedEntry(chunk, entryIndex);
    else if (code[0]=='C' && code[1]=='C' && code[2]==0)  // CC
        entry = new ConnectionCreatedEntry(chunk, entryIndex);
    else if (code[0]=='C' && code[1]=='D' && code[2]==0)  // CD
        entry = new ConnectionDeletedEntry(chunk, entryIndex);
    else if (code[0]=='M' && code[1]=='D' && code[2]=='C' && code[3]==0)  // MDC
        entry = new ModuleDisplayStringChangedEntry(chunk, entryIndex);
    else if (code[0]=='G' && code[1]=='D' && code[2]=='C' && code[3]==0)  // GDC
        entry = new GateDisplayStringChangedEntry(chunk, entryIndex);
    else if (code[0]=='C' && code[1]=='D' && code[2]=='C' && code[3]==0)  // CDC
        entry = new ConnectionDisplayStringChangedEntry(chunk, entryIndex);
    else if (code[0]=='E' && code[1]=='D' && code[2]=='C' && code[3]==0)  // EDC
        entry = new MessageDisplayStringChangedEntry(chunk, entryIndex);
    else if (code[0]=='C' && code[1]=='M' && code[2]==0)  // CM
        entry = new CreateMessageEntry(chunk, entryIndex);
    else if (code[0]=='C' && code[1]=='L' && code[2]==0)  // CL
        entry = new CloneMessageEntry(chunk, entryIndex);
    else if (code[0]=='D' && code[1]=='M' && code[2]==0)  // DM
        entry = new DeleteMessageEntry(chunk, entryIndex);
    else if (code[0]=='E' && code[1]=='N' && code[2]==0)  // EN
        entry = new EncapsulatePacketEntry(chunk, entryIndex);
    else if (code[0]=='D' && code[1]=='E' && code[2]==0)  // DE
        entry = new DecapsulatePacketEntry(chunk, entryIndex);
    else if (code[0]=='B' && code[1]=='S' && code[2]==0)  // BS
        entry = new BeginSendEntry(chunk, entryIndex);
    else if (code[0]=='E' && code[1]=='S' && code[2]==0)  // ES
        entry = new EndSendEntry(chunk, entryIndex);
    else if (code[0]=='S' && code[1]=='D' && code[2]==0)  // SD
        entry = new SendDirectEntry(chunk, entryIndex);
    else if (code[0]=='S' && code[1]=='H' && code[2]==0)  // SH
        entry = new SendHopEntry(chunk, entryIndex);
    else if (code[0]=='C' && code[1]=='E' && code[2]==0)  // CE
        entry = new CancelEventEntry(chunk, entryIndex);
    else if (code[0]=='M' && code[1]=='F' && code[2]==0)  // MF
        entry = new ModuleFoundEntry(chunk, entryIndex);
    else if (code[0]=='G' && code[1]=='F' && code[2]==0)  // GF
        entry = new GateFoundEntry(chunk, entryIndex);
    else if (code[0]=='C' && code[1]=='F' && code[2]==0)  // CF
        entry = new ConnectionFoundEntry(chunk, entryIndex);
    else if (code[0]=='E' && code[1]=='F' && code[2]==0)  // EF
        entry = new MessageFoundEntry(chunk, entryIndex);
    else if (code[0]=='M' && code[1]=='D' && code[2]=='F' && code[3]==0)  // MDF
        entry = new ModuleDisplayStringFoundEntry(chunk, entryIndex);
    else if (code[0]=='G' && code[1]=='D' && code[2]=='F' && code[3]==0)  // GDF
        entry = new GateDisplayStringFoundEntry(chunk, entryIndex);
    else if (code[0]=='C' && code[1]=='D' && code[2]=='F' && code[3]==0)  // CDF
        entry = new ConnectionDisplayStringFoundEntry(chunk, entryIndex);
    else if (code[0]=='E' && code[1]=='D' && code[2]=='F' && code[3]==0)  // EDF
        entry = new MessageDisplayStringFoundEntry(chunk, entryIndex);
    else if (code[0]=='B' && code[1]=='U' && code[2]==0)  // BU
        entry = new BubbleEntry(chunk, entryIndex);
    else if (code[0]=='C' && code[1]=='U' && code[2]=='C' && code[3]==0)  // CUC
        entry = new CustomCreatedEntry(chunk, entryIndex);
    else if (code[0]=='C' && code[1]=='U' && code[2]=='D' && code[3]==0)  // CUD
        entry = new CustomDeletedEntry(chunk, entryIndex);
    else if (code[0]=='C' && code[1]=='U' && code[2]=='M' && code[3]==0)  // CUM
        entry = new CustomChangedEntry(chunk, entryIndex);
    else if (code[0]=='C' && code[1]=='U' && code[2]=='F' && code[3]==0)  // CUF
        entry = new CustomFoundEntry(chunk, entryIndex);
    else if (code[0]=='C' && code[1]=='U' && code[2]==0)  // CU
        entry = new CustomEntry(chunk, entryIndex);
    else
        return nullptr;

    entry->parse(tokens, numTokens);
    return entry;
}

} // namespace eventlog
} // namespace omnetpp
