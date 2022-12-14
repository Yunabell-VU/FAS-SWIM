//=========================================================================
// EVENTLOGWRITER.CC - part of
//                  OMNeT++/OMNEST
//           Discrete System Simulation in C++
//
//  This is a generated file -- do not modify.
//
//=========================================================================


#include "eventlogwriter.h"
#include "common/stringutil.h"
#include "omnetpp/cconfigoption.h"
#include "omnetpp/csimulation.h"
#include "omnetpp/cmodule.h"
#include "omnetpp/cexception.h"

#ifdef CHECK
#undef CHECK
#endif
#define CHECK(fprintf)    if (fprintf<0) throw cRuntimeError("Cannot write event log file, disk full?");

namespace omnetpp {
namespace envir {

using namespace omnetpp::common;

void EventLogWriter::recordLogLine(FILE *f, const char *prefix, const char *line, int lineLength)
{
    CHECK(fprintf(f, "- %s", prefix));
    CHECK(fwrite(line, 1, lineLength, f));
}

void EventLogWriter::recordSimulationBeginEntry_ov_ev_rid(FILE *f, int omnetppVersion, int eventlogVersion, const char * runId)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "SB ov %d ev %d rid %s\n", omnetppVersion, eventlogVersion, QUOTE(runId)));
}

void EventLogWriter::recordSimulationEndEntry_e_c_m(FILE *f, bool isError, int resultCode, const char * message)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "SE e %d c %d m %s\n", isError, resultCode, QUOTE(message)));
}

void EventLogWriter::recordEventEntry_e_t_m_ce_msg(FILE *f, eventnumber_t eventNumber, simtime_t simulationTime, int moduleId, eventnumber_t causeEventNumber, msgid_t messageId)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "E # %" PRId64 " t %s m %d ce %" PRId64 " msg %" PRId64 "\n", eventNumber, SIMTIME_STR(simulationTime), moduleId, causeEventNumber, messageId));
}

void EventLogWriter::recordEventEntry_e_t_m_ce_msg_f(FILE *f, eventnumber_t eventNumber, simtime_t simulationTime, int moduleId, eventnumber_t causeEventNumber, msgid_t messageId, const char * fingerprints)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "E # %" PRId64 " t %s m %d ce %" PRId64 " msg %" PRId64 "", eventNumber, SIMTIME_STR(simulationTime), moduleId, causeEventNumber, messageId));
    if (fingerprints!=NULL)
        CHECK(fprintf(f, " f %s", QUOTE(fingerprints)));
    CHECK(fprintf(f, "\n"));
}

void EventLogWriter::recordSnapshotEntry_f_e_t(FILE *f, int64_t fileOffset, eventnumber_t eventNumber, simtime_t simulationTime)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "S f %" PRId64 " # %" PRId64 " t %s\n", fileOffset, eventNumber, SIMTIME_STR(simulationTime)));
}

void EventLogWriter::recordIndexEntry_f_i_s_e_t(FILE *f, int64_t fileOffset, int64_t previousIndexFileOffset, int64_t previousSnapshotFileOffset, eventnumber_t eventNumber, simtime_t simulationTime)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "I f %" PRId64 " i %" PRId64 " s %" PRId64 " # %" PRId64 " t %s\n", fileOffset, previousIndexFileOffset, previousSnapshotFileOffset, eventNumber, SIMTIME_STR(simulationTime)));
}

void EventLogWriter::recordReferenceEntry_e_b_e(FILE *f, eventnumber_t eventNumber, int beginEntryIndex, int endEntryIndex)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "abstract # %" PRId64 " b %d e %d\n", eventNumber, beginEntryIndex, endEntryIndex));
}

void EventLogWriter::recordReferenceFoundEntry_e_b_e(FILE *f, eventnumber_t eventNumber, int beginEntryIndex, int endEntryIndex)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "RF # %" PRId64 " b %d e %d\n", eventNumber, beginEntryIndex, endEntryIndex));
}

void EventLogWriter::recordReferenceAddedEntry_e_b_e(FILE *f, eventnumber_t eventNumber, int beginEntryIndex, int endEntryIndex)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "RA # %" PRId64 " b %d e %d\n", eventNumber, beginEntryIndex, endEntryIndex));
}

void EventLogWriter::recordReferenceRemovedEntry_e_b_e(FILE *f, eventnumber_t eventNumber, int beginEntryIndex, int endEntryIndex)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "RR # %" PRId64 " b %d e %d\n", eventNumber, beginEntryIndex, endEntryIndex));
}

void EventLogWriter::recordModuleReferenceEntry_id(FILE *f, int moduleId)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "abstract id %d\n", moduleId));
}

void EventLogWriter::recordGateReferenceEntry_m_g(FILE *f, int moduleId, int gateId)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "abstract m %d g %d\n", moduleId, gateId));
}

void EventLogWriter::recordConnectionReferenceEntry_sm_sg(FILE *f, int sourceModuleId, int sourceGateId)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "abstract sm %d sg %d\n", sourceModuleId, sourceGateId));
}

void EventLogWriter::recordMessageReferenceEntry_id(FILE *f, msgid_t messageId)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "abstract id %" PRId64 "\n", messageId));
}

void EventLogWriter::recordModuleDescriptionEntry_id_c_t_n(FILE *f, int moduleId, const char * moduleClassName, const char * nedTypeName, const char * fullName)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "abstract id %d c %s t %s n %s\n", moduleId, QUOTE(moduleClassName), QUOTE(nedTypeName), QUOTE(fullName)));
}

void EventLogWriter::recordModuleDescriptionEntry_id_c_t_pid_n_cm(FILE *f, int moduleId, const char * moduleClassName, const char * nedTypeName, int parentModuleId, const char * fullName, bool compoundModule)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "abstract id %d c %s t %s", moduleId, QUOTE(moduleClassName), QUOTE(nedTypeName)));
    if (parentModuleId!=-1)
        CHECK(fprintf(f, " pid %d", parentModuleId));
    CHECK(fprintf(f, " n %s", QUOTE(fullName)));
    if (compoundModule!=false)
        CHECK(fprintf(f, " cm %d", compoundModule));
    CHECK(fprintf(f, "\n"));
}

void EventLogWriter::recordGateDescriptionEntry_m_g_n_o(FILE *f, int moduleId, int gateId, const char * name, bool isOutput)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "abstract m %d g %d n %s o %d\n", moduleId, gateId, QUOTE(name), isOutput));
}

void EventLogWriter::recordGateDescriptionEntry_m_g_n_i_o(FILE *f, int moduleId, int gateId, const char * name, int index, bool isOutput)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "abstract m %d g %d n %s", moduleId, gateId, QUOTE(name)));
    if (index!=-1)
        CHECK(fprintf(f, " i %d", index));
    CHECK(fprintf(f, " o %d\n", isOutput));
}

void EventLogWriter::recordConnectionDescriptionEntry_sm_sg_dm_dg(FILE *f, int sourceModuleId, int sourceGateId, int destModuleId, int destGateId)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "abstract sm %d sg %d dm %d dg %d\n", sourceModuleId, sourceGateId, destModuleId, destGateId));
}

void EventLogWriter::recordMessageDescriptionEntry_id_tid_eid_etid_c_n_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "abstract id %" PRId64 " tid %" PRId64 " eid %" PRId64 " etid %" PRId64 " c %s n %s pe %" PRId64 "\n", messageId, messageTreeId, messageEncapsulationId, messageEncapsulationTreeId, QUOTE(messageClassName), QUOTE(messageName), previousEventNumber));
}

void EventLogWriter::recordMessageDescriptionEntry_id_tid_eid_etid_c_n_k_p_l_er_m_sm_sg_st_am_ag_at_d_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64_t messageLength, bool hasBitError, int ownerModuleId, int senderModuleId, int senderGateId, simtime_t sendingTime, int arrivalModuleId, int arrivalGateId, simtime_t arrivalTime, const char * detail, eventnumber_t previousEventNumber)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "abstract id %" PRId64 " tid %" PRId64 " eid %" PRId64 " etid %" PRId64 " c %s n %s", messageId, messageTreeId, messageEncapsulationId, messageEncapsulationTreeId, QUOTE(messageClassName), QUOTE(messageName)));
    if (messageKind!=0)
        CHECK(fprintf(f, " k %d", messageKind));
    if (messagePriority!=0)
        CHECK(fprintf(f, " p %d", messagePriority));
    if (messageLength!=0)
        CHECK(fprintf(f, " l %" PRId64 "", messageLength));
    if (hasBitError!=false)
        CHECK(fprintf(f, " er %d", hasBitError));
    if (ownerModuleId!=-1)
        CHECK(fprintf(f, " m %d", ownerModuleId));
    if (senderModuleId!=-1)
        CHECK(fprintf(f, " sm %d", senderModuleId));
    if (senderGateId!=-1)
        CHECK(fprintf(f, " sg %d", senderGateId));
    if (sendingTime!=-1)
        CHECK(fprintf(f, " st %s", SIMTIME_STR(sendingTime)));
    if (arrivalModuleId!=-1)
        CHECK(fprintf(f, " am %d", arrivalModuleId));
    if (arrivalGateId!=-1)
        CHECK(fprintf(f, " ag %d", arrivalGateId));
    if (arrivalTime!=-1)
        CHECK(fprintf(f, " at %s", SIMTIME_STR(arrivalTime)));
    if (detail!=NULL)
        CHECK(fprintf(f, " d %s", QUOTE(detail)));
    CHECK(fprintf(f, " pe %" PRId64 "\n", previousEventNumber));
}

void EventLogWriter::recordModuleDisplayStringEntry_id_d(FILE *f, int moduleId, const char * displayString)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "abstract id %d d %s\n", moduleId, QUOTE(displayString)));
}

void EventLogWriter::recordGateDisplayStringEntry_m_g_d(FILE *f, int moduleId, int gateId, const char * displayString)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "abstract m %d g %d d %s\n", moduleId, gateId, QUOTE(displayString)));
}

void EventLogWriter::recordConnectionDisplayStringEntry_sm_sg_d(FILE *f, int sourceModuleId, int sourceGateId, const char * displayString)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "abstract sm %d sg %d d %s\n", sourceModuleId, sourceGateId, QUOTE(displayString)));
}

void EventLogWriter::recordMessageDisplayStringEntry_id_d(FILE *f, msgid_t messageId, const char * displayString)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "abstract id %" PRId64 " d %s\n", messageId, QUOTE(displayString)));
}

void EventLogWriter::recordComponentMethodBeginEntry_sm_tm_m(FILE *f, int sourceComponentId, int targetComponentId, const char * methodName)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "CMB sm %d tm %d m %s\n", sourceComponentId, targetComponentId, QUOTE(methodName)));
}

void EventLogWriter::recordComponentMethodEndEntry(FILE *f)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "CME\n"));
}

void EventLogWriter::recordModuleCreatedEntry_id_c_t_n(FILE *f, int moduleId, const char * moduleClassName, const char * nedTypeName, const char * fullName)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "MC id %d c %s t %s n %s\n", moduleId, QUOTE(moduleClassName), QUOTE(nedTypeName), QUOTE(fullName)));
}

void EventLogWriter::recordModuleCreatedEntry_id_c_t_pid_n_cm(FILE *f, int moduleId, const char * moduleClassName, const char * nedTypeName, int parentModuleId, const char * fullName, bool compoundModule)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "MC id %d c %s t %s", moduleId, QUOTE(moduleClassName), QUOTE(nedTypeName)));
    if (parentModuleId!=-1)
        CHECK(fprintf(f, " pid %d", parentModuleId));
    CHECK(fprintf(f, " n %s", QUOTE(fullName)));
    if (compoundModule!=false)
        CHECK(fprintf(f, " cm %d", compoundModule));
    CHECK(fprintf(f, "\n"));
}

void EventLogWriter::recordModuleDeletedEntry_id(FILE *f, int moduleId)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "MD id %d\n", moduleId));
}

void EventLogWriter::recordGateCreatedEntry_m_g_n_o(FILE *f, int moduleId, int gateId, const char * name, bool isOutput)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "GC m %d g %d n %s o %d\n", moduleId, gateId, QUOTE(name), isOutput));
}

void EventLogWriter::recordGateCreatedEntry_m_g_n_i_o(FILE *f, int moduleId, int gateId, const char * name, int index, bool isOutput)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "GC m %d g %d n %s", moduleId, gateId, QUOTE(name)));
    if (index!=-1)
        CHECK(fprintf(f, " i %d", index));
    CHECK(fprintf(f, " o %d\n", isOutput));
}

void EventLogWriter::recordGateDeletedEntry_m_g(FILE *f, int moduleId, int gateId)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "GD m %d g %d\n", moduleId, gateId));
}

void EventLogWriter::recordConnectionCreatedEntry_sm_sg_dm_dg(FILE *f, int sourceModuleId, int sourceGateId, int destModuleId, int destGateId)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "CC sm %d sg %d dm %d dg %d\n", sourceModuleId, sourceGateId, destModuleId, destGateId));
}

void EventLogWriter::recordConnectionDeletedEntry_sm_sg(FILE *f, int sourceModuleId, int sourceGateId)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "CD sm %d sg %d\n", sourceModuleId, sourceGateId));
}

void EventLogWriter::recordModuleDisplayStringChangedEntry_id_d(FILE *f, int moduleId, const char * displayString)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "MDC id %d d %s\n", moduleId, QUOTE(displayString)));
}

void EventLogWriter::recordGateDisplayStringChangedEntry_m_g_d(FILE *f, int moduleId, int gateId, const char * displayString)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "GDC m %d g %d d %s\n", moduleId, gateId, QUOTE(displayString)));
}

void EventLogWriter::recordConnectionDisplayStringChangedEntry_sm_sg_d(FILE *f, int sourceModuleId, int sourceGateId, const char * displayString)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "CDC sm %d sg %d d %s\n", sourceModuleId, sourceGateId, QUOTE(displayString)));
}

void EventLogWriter::recordMessageDisplayStringChangedEntry_id_d(FILE *f, msgid_t messageId, const char * displayString)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "EDC id %" PRId64 " d %s\n", messageId, QUOTE(displayString)));
}

void EventLogWriter::recordCreateMessageEntry_id_tid_eid_etid_c_n_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "CM id %" PRId64 " tid %" PRId64 " eid %" PRId64 " etid %" PRId64 " c %s n %s pe %" PRId64 "\n", messageId, messageTreeId, messageEncapsulationId, messageEncapsulationTreeId, QUOTE(messageClassName), QUOTE(messageName), previousEventNumber));
}

void EventLogWriter::recordCreateMessageEntry_id_tid_eid_etid_c_n_k_p_l_er_m_sm_sg_st_am_ag_at_d_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64_t messageLength, bool hasBitError, int ownerModuleId, int senderModuleId, int senderGateId, simtime_t sendingTime, int arrivalModuleId, int arrivalGateId, simtime_t arrivalTime, const char * detail, eventnumber_t previousEventNumber)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "CM id %" PRId64 " tid %" PRId64 " eid %" PRId64 " etid %" PRId64 " c %s n %s", messageId, messageTreeId, messageEncapsulationId, messageEncapsulationTreeId, QUOTE(messageClassName), QUOTE(messageName)));
    if (messageKind!=0)
        CHECK(fprintf(f, " k %d", messageKind));
    if (messagePriority!=0)
        CHECK(fprintf(f, " p %d", messagePriority));
    if (messageLength!=0)
        CHECK(fprintf(f, " l %" PRId64 "", messageLength));
    if (hasBitError!=false)
        CHECK(fprintf(f, " er %d", hasBitError));
    if (ownerModuleId!=-1)
        CHECK(fprintf(f, " m %d", ownerModuleId));
    if (senderModuleId!=-1)
        CHECK(fprintf(f, " sm %d", senderModuleId));
    if (senderGateId!=-1)
        CHECK(fprintf(f, " sg %d", senderGateId));
    if (sendingTime!=-1)
        CHECK(fprintf(f, " st %s", SIMTIME_STR(sendingTime)));
    if (arrivalModuleId!=-1)
        CHECK(fprintf(f, " am %d", arrivalModuleId));
    if (arrivalGateId!=-1)
        CHECK(fprintf(f, " ag %d", arrivalGateId));
    if (arrivalTime!=-1)
        CHECK(fprintf(f, " at %s", SIMTIME_STR(arrivalTime)));
    if (detail!=NULL)
        CHECK(fprintf(f, " d %s", QUOTE(detail)));
    CHECK(fprintf(f, " pe %" PRId64 "\n", previousEventNumber));
}

void EventLogWriter::recordCloneMessageEntry_id_tid_eid_etid_c_n_pe_cid(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber, msgid_t cloneId)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "CL id %" PRId64 " tid %" PRId64 " eid %" PRId64 " etid %" PRId64 " c %s n %s pe %" PRId64 " cid %" PRId64 "\n", messageId, messageTreeId, messageEncapsulationId, messageEncapsulationTreeId, QUOTE(messageClassName), QUOTE(messageName), previousEventNumber, cloneId));
}

void EventLogWriter::recordCloneMessageEntry_id_tid_eid_etid_c_n_k_p_l_er_m_sm_sg_st_am_ag_at_d_pe_cid(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64_t messageLength, bool hasBitError, int ownerModuleId, int senderModuleId, int senderGateId, simtime_t sendingTime, int arrivalModuleId, int arrivalGateId, simtime_t arrivalTime, const char * detail, eventnumber_t previousEventNumber, msgid_t cloneId)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "CL id %" PRId64 " tid %" PRId64 " eid %" PRId64 " etid %" PRId64 " c %s n %s", messageId, messageTreeId, messageEncapsulationId, messageEncapsulationTreeId, QUOTE(messageClassName), QUOTE(messageName)));
    if (messageKind!=0)
        CHECK(fprintf(f, " k %d", messageKind));
    if (messagePriority!=0)
        CHECK(fprintf(f, " p %d", messagePriority));
    if (messageLength!=0)
        CHECK(fprintf(f, " l %" PRId64 "", messageLength));
    if (hasBitError!=false)
        CHECK(fprintf(f, " er %d", hasBitError));
    if (ownerModuleId!=-1)
        CHECK(fprintf(f, " m %d", ownerModuleId));
    if (senderModuleId!=-1)
        CHECK(fprintf(f, " sm %d", senderModuleId));
    if (senderGateId!=-1)
        CHECK(fprintf(f, " sg %d", senderGateId));
    if (sendingTime!=-1)
        CHECK(fprintf(f, " st %s", SIMTIME_STR(sendingTime)));
    if (arrivalModuleId!=-1)
        CHECK(fprintf(f, " am %d", arrivalModuleId));
    if (arrivalGateId!=-1)
        CHECK(fprintf(f, " ag %d", arrivalGateId));
    if (arrivalTime!=-1)
        CHECK(fprintf(f, " at %s", SIMTIME_STR(arrivalTime)));
    if (detail!=NULL)
        CHECK(fprintf(f, " d %s", QUOTE(detail)));
    CHECK(fprintf(f, " pe %" PRId64 " cid %" PRId64 "\n", previousEventNumber, cloneId));
}

void EventLogWriter::recordDeleteMessageEntry_id_tid_eid_etid_c_n_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "DM id %" PRId64 " tid %" PRId64 " eid %" PRId64 " etid %" PRId64 " c %s n %s pe %" PRId64 "\n", messageId, messageTreeId, messageEncapsulationId, messageEncapsulationTreeId, QUOTE(messageClassName), QUOTE(messageName), previousEventNumber));
}

void EventLogWriter::recordDeleteMessageEntry_id_tid_eid_etid_c_n_k_p_l_er_m_sm_sg_st_am_ag_at_d_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64_t messageLength, bool hasBitError, int ownerModuleId, int senderModuleId, int senderGateId, simtime_t sendingTime, int arrivalModuleId, int arrivalGateId, simtime_t arrivalTime, const char * detail, eventnumber_t previousEventNumber)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "DM id %" PRId64 " tid %" PRId64 " eid %" PRId64 " etid %" PRId64 " c %s n %s", messageId, messageTreeId, messageEncapsulationId, messageEncapsulationTreeId, QUOTE(messageClassName), QUOTE(messageName)));
    if (messageKind!=0)
        CHECK(fprintf(f, " k %d", messageKind));
    if (messagePriority!=0)
        CHECK(fprintf(f, " p %d", messagePriority));
    if (messageLength!=0)
        CHECK(fprintf(f, " l %" PRId64 "", messageLength));
    if (hasBitError!=false)
        CHECK(fprintf(f, " er %d", hasBitError));
    if (ownerModuleId!=-1)
        CHECK(fprintf(f, " m %d", ownerModuleId));
    if (senderModuleId!=-1)
        CHECK(fprintf(f, " sm %d", senderModuleId));
    if (senderGateId!=-1)
        CHECK(fprintf(f, " sg %d", senderGateId));
    if (sendingTime!=-1)
        CHECK(fprintf(f, " st %s", SIMTIME_STR(sendingTime)));
    if (arrivalModuleId!=-1)
        CHECK(fprintf(f, " am %d", arrivalModuleId));
    if (arrivalGateId!=-1)
        CHECK(fprintf(f, " ag %d", arrivalGateId));
    if (arrivalTime!=-1)
        CHECK(fprintf(f, " at %s", SIMTIME_STR(arrivalTime)));
    if (detail!=NULL)
        CHECK(fprintf(f, " d %s", QUOTE(detail)));
    CHECK(fprintf(f, " pe %" PRId64 "\n", previousEventNumber));
}

void EventLogWriter::recordEncapsulatePacketEntry_id_cid(FILE *f, msgid_t messageId, msgid_t encapsulatedPacketId)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "EN id %" PRId64 " cid %" PRId64 "\n", messageId, encapsulatedPacketId));
}

void EventLogWriter::recordDecapsulatePacketEntry_id_cid(FILE *f, msgid_t messageId, msgid_t encapsulatedPacketId)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "DE id %" PRId64 " cid %" PRId64 "\n", messageId, encapsulatedPacketId));
}

void EventLogWriter::recordBeginSendEntry_id_tid_eid_etid_c_n_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "BS id %" PRId64 " tid %" PRId64 " eid %" PRId64 " etid %" PRId64 " c %s n %s pe %" PRId64 "\n", messageId, messageTreeId, messageEncapsulationId, messageEncapsulationTreeId, QUOTE(messageClassName), QUOTE(messageName), previousEventNumber));
}

void EventLogWriter::recordBeginSendEntry_id_tid_eid_etid_c_n_k_p_l_er_m_sm_sg_st_am_ag_at_d_pe_sd_up_tx(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64_t messageLength, bool hasBitError, int ownerModuleId, int senderModuleId, int senderGateId, simtime_t sendingTime, int arrivalModuleId, int arrivalGateId, simtime_t arrivalTime, const char * detail, eventnumber_t previousEventNumber, simtime_t sendDelay, bool isUpdate, txid_t transmissionId)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "BS id %" PRId64 " tid %" PRId64 " eid %" PRId64 " etid %" PRId64 " c %s n %s", messageId, messageTreeId, messageEncapsulationId, messageEncapsulationTreeId, QUOTE(messageClassName), QUOTE(messageName)));
    if (messageKind!=0)
        CHECK(fprintf(f, " k %d", messageKind));
    if (messagePriority!=0)
        CHECK(fprintf(f, " p %d", messagePriority));
    if (messageLength!=0)
        CHECK(fprintf(f, " l %" PRId64 "", messageLength));
    if (hasBitError!=false)
        CHECK(fprintf(f, " er %d", hasBitError));
    if (ownerModuleId!=-1)
        CHECK(fprintf(f, " m %d", ownerModuleId));
    if (senderModuleId!=-1)
        CHECK(fprintf(f, " sm %d", senderModuleId));
    if (senderGateId!=-1)
        CHECK(fprintf(f, " sg %d", senderGateId));
    if (sendingTime!=-1)
        CHECK(fprintf(f, " st %s", SIMTIME_STR(sendingTime)));
    if (arrivalModuleId!=-1)
        CHECK(fprintf(f, " am %d", arrivalModuleId));
    if (arrivalGateId!=-1)
        CHECK(fprintf(f, " ag %d", arrivalGateId));
    if (arrivalTime!=-1)
        CHECK(fprintf(f, " at %s", SIMTIME_STR(arrivalTime)));
    if (detail!=NULL)
        CHECK(fprintf(f, " d %s", QUOTE(detail)));
    CHECK(fprintf(f, " pe %" PRId64 "", previousEventNumber));
    if (sendDelay!=0)
        CHECK(fprintf(f, " sd %s", SIMTIME_STR(sendDelay)));
    if (isUpdate!=false)
        CHECK(fprintf(f, " up %d", isUpdate));
    if (transmissionId!=-1)
        CHECK(fprintf(f, " tx %" PRId64 "", transmissionId));
    CHECK(fprintf(f, "\n"));
}

void EventLogWriter::recordEndSendEntry_id_tid_eid_etid_c_n_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "ES id %" PRId64 " tid %" PRId64 " eid %" PRId64 " etid %" PRId64 " c %s n %s pe %" PRId64 "\n", messageId, messageTreeId, messageEncapsulationId, messageEncapsulationTreeId, QUOTE(messageClassName), QUOTE(messageName), previousEventNumber));
}

void EventLogWriter::recordEndSendEntry_id_tid_eid_etid_c_n_k_p_l_er_m_sm_sg_st_am_ag_at_d_pe_i(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64_t messageLength, bool hasBitError, int ownerModuleId, int senderModuleId, int senderGateId, simtime_t sendingTime, int arrivalModuleId, int arrivalGateId, simtime_t arrivalTime, const char * detail, eventnumber_t previousEventNumber, bool isDeliveredImmediately)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "ES id %" PRId64 " tid %" PRId64 " eid %" PRId64 " etid %" PRId64 " c %s n %s", messageId, messageTreeId, messageEncapsulationId, messageEncapsulationTreeId, QUOTE(messageClassName), QUOTE(messageName)));
    if (messageKind!=0)
        CHECK(fprintf(f, " k %d", messageKind));
    if (messagePriority!=0)
        CHECK(fprintf(f, " p %d", messagePriority));
    if (messageLength!=0)
        CHECK(fprintf(f, " l %" PRId64 "", messageLength));
    if (hasBitError!=false)
        CHECK(fprintf(f, " er %d", hasBitError));
    if (ownerModuleId!=-1)
        CHECK(fprintf(f, " m %d", ownerModuleId));
    if (senderModuleId!=-1)
        CHECK(fprintf(f, " sm %d", senderModuleId));
    if (senderGateId!=-1)
        CHECK(fprintf(f, " sg %d", senderGateId));
    if (sendingTime!=-1)
        CHECK(fprintf(f, " st %s", SIMTIME_STR(sendingTime)));
    if (arrivalModuleId!=-1)
        CHECK(fprintf(f, " am %d", arrivalModuleId));
    if (arrivalGateId!=-1)
        CHECK(fprintf(f, " ag %d", arrivalGateId));
    if (arrivalTime!=-1)
        CHECK(fprintf(f, " at %s", SIMTIME_STR(arrivalTime)));
    if (detail!=NULL)
        CHECK(fprintf(f, " d %s", QUOTE(detail)));
    CHECK(fprintf(f, " pe %" PRId64 "", previousEventNumber));
    if (isDeliveredImmediately!=false)
        CHECK(fprintf(f, " i %d", isDeliveredImmediately));
    CHECK(fprintf(f, "\n"));
}

void EventLogWriter::recordSendDirectEntry_sm_dm_dg(FILE *f, int senderModuleId, int destModuleId, int destGateId)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "SD sm %d dm %d dg %d\n", senderModuleId, destModuleId, destGateId));
}

void EventLogWriter::recordSendDirectEntry_sm_dm_dg_pd_td_rd(FILE *f, int senderModuleId, int destModuleId, int destGateId, simtime_t propagationDelay, simtime_t transmissionDelay, simtime_t remainingDuration)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "SD sm %d dm %d dg %d", senderModuleId, destModuleId, destGateId));
    if (propagationDelay!=0)
        CHECK(fprintf(f, " pd %s", SIMTIME_STR(propagationDelay)));
    if (transmissionDelay!=0)
        CHECK(fprintf(f, " td %s", SIMTIME_STR(transmissionDelay)));
    if (remainingDuration!=0)
        CHECK(fprintf(f, " rd %s", SIMTIME_STR(remainingDuration)));
    CHECK(fprintf(f, "\n"));
}

void EventLogWriter::recordSendHopEntry_sm_sg(FILE *f, int senderModuleId, int senderGateId)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "SH sm %d sg %d\n", senderModuleId, senderGateId));
}

void EventLogWriter::recordSendHopEntry_sm_sg_pd_td_rd_d(FILE *f, int senderModuleId, int senderGateId, simtime_t propagationDelay, simtime_t transmissionDelay, simtime_t remainingDuration, bool discard)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "SH sm %d sg %d", senderModuleId, senderGateId));
    if (propagationDelay!=0)
        CHECK(fprintf(f, " pd %s", SIMTIME_STR(propagationDelay)));
    if (transmissionDelay!=0)
        CHECK(fprintf(f, " td %s", SIMTIME_STR(transmissionDelay)));
    if (remainingDuration!=0)
        CHECK(fprintf(f, " rd %s", SIMTIME_STR(remainingDuration)));
    if (discard!=false)
        CHECK(fprintf(f, " d %d", discard));
    CHECK(fprintf(f, "\n"));
}

void EventLogWriter::recordCancelEventEntry_id_tid_eid_etid_c_n_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "CE id %" PRId64 " tid %" PRId64 " eid %" PRId64 " etid %" PRId64 " c %s n %s pe %" PRId64 "\n", messageId, messageTreeId, messageEncapsulationId, messageEncapsulationTreeId, QUOTE(messageClassName), QUOTE(messageName), previousEventNumber));
}

void EventLogWriter::recordCancelEventEntry_id_tid_eid_etid_c_n_k_p_l_er_m_sm_sg_st_am_ag_at_d_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64_t messageLength, bool hasBitError, int ownerModuleId, int senderModuleId, int senderGateId, simtime_t sendingTime, int arrivalModuleId, int arrivalGateId, simtime_t arrivalTime, const char * detail, eventnumber_t previousEventNumber)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "CE id %" PRId64 " tid %" PRId64 " eid %" PRId64 " etid %" PRId64 " c %s n %s", messageId, messageTreeId, messageEncapsulationId, messageEncapsulationTreeId, QUOTE(messageClassName), QUOTE(messageName)));
    if (messageKind!=0)
        CHECK(fprintf(f, " k %d", messageKind));
    if (messagePriority!=0)
        CHECK(fprintf(f, " p %d", messagePriority));
    if (messageLength!=0)
        CHECK(fprintf(f, " l %" PRId64 "", messageLength));
    if (hasBitError!=false)
        CHECK(fprintf(f, " er %d", hasBitError));
    if (ownerModuleId!=-1)
        CHECK(fprintf(f, " m %d", ownerModuleId));
    if (senderModuleId!=-1)
        CHECK(fprintf(f, " sm %d", senderModuleId));
    if (senderGateId!=-1)
        CHECK(fprintf(f, " sg %d", senderGateId));
    if (sendingTime!=-1)
        CHECK(fprintf(f, " st %s", SIMTIME_STR(sendingTime)));
    if (arrivalModuleId!=-1)
        CHECK(fprintf(f, " am %d", arrivalModuleId));
    if (arrivalGateId!=-1)
        CHECK(fprintf(f, " ag %d", arrivalGateId));
    if (arrivalTime!=-1)
        CHECK(fprintf(f, " at %s", SIMTIME_STR(arrivalTime)));
    if (detail!=NULL)
        CHECK(fprintf(f, " d %s", QUOTE(detail)));
    CHECK(fprintf(f, " pe %" PRId64 "\n", previousEventNumber));
}

void EventLogWriter::recordModuleFoundEntry_id_c_t_n_e_ei(FILE *f, int moduleId, const char * moduleClassName, const char * nedTypeName, const char * fullName, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "MF id %d c %s t %s n %s # %" PRId64 " ei %d\n", moduleId, QUOTE(moduleClassName), QUOTE(nedTypeName), QUOTE(fullName), lastSeenEventNumber, lastSeenEntryIndex));
}

void EventLogWriter::recordModuleFoundEntry_id_c_t_pid_n_cm_e_ei(FILE *f, int moduleId, const char * moduleClassName, const char * nedTypeName, int parentModuleId, const char * fullName, bool compoundModule, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "MF id %d c %s t %s", moduleId, QUOTE(moduleClassName), QUOTE(nedTypeName)));
    if (parentModuleId!=-1)
        CHECK(fprintf(f, " pid %d", parentModuleId));
    CHECK(fprintf(f, " n %s", QUOTE(fullName)));
    if (compoundModule!=false)
        CHECK(fprintf(f, " cm %d", compoundModule));
    CHECK(fprintf(f, " # %" PRId64 " ei %d\n", lastSeenEventNumber, lastSeenEntryIndex));
}

void EventLogWriter::recordGateFoundEntry_m_g_n_o_e_ei(FILE *f, int moduleId, int gateId, const char * name, bool isOutput, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "GF m %d g %d n %s o %d # %" PRId64 " ei %d\n", moduleId, gateId, QUOTE(name), isOutput, lastSeenEventNumber, lastSeenEntryIndex));
}

void EventLogWriter::recordGateFoundEntry_m_g_n_i_o_e_ei(FILE *f, int moduleId, int gateId, const char * name, int index, bool isOutput, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "GF m %d g %d n %s", moduleId, gateId, QUOTE(name)));
    if (index!=-1)
        CHECK(fprintf(f, " i %d", index));
    CHECK(fprintf(f, " o %d # %" PRId64 " ei %d\n", isOutput, lastSeenEventNumber, lastSeenEntryIndex));
}

void EventLogWriter::recordConnectionFoundEntry_sm_sg_dm_dg_e_ei(FILE *f, int sourceModuleId, int sourceGateId, int destModuleId, int destGateId, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "CF sm %d sg %d dm %d dg %d # %" PRId64 " ei %d\n", sourceModuleId, sourceGateId, destModuleId, destGateId, lastSeenEventNumber, lastSeenEntryIndex));
}

void EventLogWriter::recordMessageFoundEntry_id_tid_eid_etid_c_n_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "EF id %" PRId64 " tid %" PRId64 " eid %" PRId64 " etid %" PRId64 " c %s n %s pe %" PRId64 "\n", messageId, messageTreeId, messageEncapsulationId, messageEncapsulationTreeId, QUOTE(messageClassName), QUOTE(messageName), previousEventNumber));
}

void EventLogWriter::recordMessageFoundEntry_id_tid_eid_etid_c_n_k_p_l_er_m_sm_sg_st_am_ag_at_d_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64_t messageLength, bool hasBitError, int ownerModuleId, int senderModuleId, int senderGateId, simtime_t sendingTime, int arrivalModuleId, int arrivalGateId, simtime_t arrivalTime, const char * detail, eventnumber_t previousEventNumber)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "EF id %" PRId64 " tid %" PRId64 " eid %" PRId64 " etid %" PRId64 " c %s n %s", messageId, messageTreeId, messageEncapsulationId, messageEncapsulationTreeId, QUOTE(messageClassName), QUOTE(messageName)));
    if (messageKind!=0)
        CHECK(fprintf(f, " k %d", messageKind));
    if (messagePriority!=0)
        CHECK(fprintf(f, " p %d", messagePriority));
    if (messageLength!=0)
        CHECK(fprintf(f, " l %" PRId64 "", messageLength));
    if (hasBitError!=false)
        CHECK(fprintf(f, " er %d", hasBitError));
    if (ownerModuleId!=-1)
        CHECK(fprintf(f, " m %d", ownerModuleId));
    if (senderModuleId!=-1)
        CHECK(fprintf(f, " sm %d", senderModuleId));
    if (senderGateId!=-1)
        CHECK(fprintf(f, " sg %d", senderGateId));
    if (sendingTime!=-1)
        CHECK(fprintf(f, " st %s", SIMTIME_STR(sendingTime)));
    if (arrivalModuleId!=-1)
        CHECK(fprintf(f, " am %d", arrivalModuleId));
    if (arrivalGateId!=-1)
        CHECK(fprintf(f, " ag %d", arrivalGateId));
    if (arrivalTime!=-1)
        CHECK(fprintf(f, " at %s", SIMTIME_STR(arrivalTime)));
    if (detail!=NULL)
        CHECK(fprintf(f, " d %s", QUOTE(detail)));
    CHECK(fprintf(f, " pe %" PRId64 "\n", previousEventNumber));
}

void EventLogWriter::recordModuleDisplayStringFoundEntry_id_d_e_ei(FILE *f, int moduleId, const char * displayString, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "MDF id %d d %s # %" PRId64 " ei %d\n", moduleId, QUOTE(displayString), lastSeenEventNumber, lastSeenEntryIndex));
}

void EventLogWriter::recordGateDisplayStringFoundEntry_m_g_d_e_ei(FILE *f, int moduleId, int gateId, const char * displayString, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "GDF m %d g %d d %s # %" PRId64 " ei %d\n", moduleId, gateId, QUOTE(displayString), lastSeenEventNumber, lastSeenEntryIndex));
}

void EventLogWriter::recordConnectionDisplayStringFoundEntry_sm_sg_d_e_ei(FILE *f, int sourceModuleId, int sourceGateId, const char * displayString, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "CDF sm %d sg %d d %s # %" PRId64 " ei %d\n", sourceModuleId, sourceGateId, QUOTE(displayString), lastSeenEventNumber, lastSeenEntryIndex));
}

void EventLogWriter::recordMessageDisplayStringFoundEntry_id_d_e_ei(FILE *f, msgid_t messageId, const char * displayString, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "EDF id %" PRId64 " d %s # %" PRId64 " ei %d\n", messageId, QUOTE(displayString), lastSeenEventNumber, lastSeenEntryIndex));
}

void EventLogWriter::recordBubbleEntry_id_txt(FILE *f, int moduleId, const char * text)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "BU id %d txt %s\n", moduleId, QUOTE(text)));
}

void EventLogWriter::recordCustomReferenceEntry_t_k(FILE *f, const char * type, long key)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "abstract t %s k %ld\n", QUOTE(type), key));
}

void EventLogWriter::recordCustomDescriptionEntry_t_k_c(FILE *f, const char * type, long key, const char * content)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "abstract t %s k %ld c %s\n", QUOTE(type), key, QUOTE(content)));
}

void EventLogWriter::recordCustomCreatedEntry_t_k_c(FILE *f, const char * type, long key, const char * content)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "CUC t %s k %ld c %s\n", QUOTE(type), key, QUOTE(content)));
}

void EventLogWriter::recordCustomDeletedEntry_t_k(FILE *f, const char * type, long key)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "CUD t %s k %ld\n", QUOTE(type), key));
}

void EventLogWriter::recordCustomChangedEntry_t_k_c(FILE *f, const char * type, long key, const char * content)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "CUM t %s k %ld c %s\n", QUOTE(type), key, QUOTE(content)));
}

void EventLogWriter::recordCustomFoundEntry_t_k_c_e_ei(FILE *f, const char * type, long key, const char * content, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "CUF t %s k %ld c %s # %" PRId64 " ei %d\n", QUOTE(type), key, QUOTE(content), lastSeenEventNumber, lastSeenEntryIndex));
}

void EventLogWriter::recordCustomEntry_t_k_c(FILE *f, const char * type, long key, const char * content)
{
    ASSERT(f!=nullptr);
    CHECK(fprintf(f, "CU t %s k %ld c %s\n", QUOTE(type), key, QUOTE(content)));
}


} // namespace envir

}  // namespace omnetpp
