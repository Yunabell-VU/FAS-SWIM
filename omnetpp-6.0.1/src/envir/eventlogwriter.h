//=========================================================================
// EVENTLOGWRITER.H - part of
//                  OMNeT++/OMNEST
//           Discrete System Simulation in C++
//
//  This is a generated file -- do not modify.
//
//=========================================================================

#ifndef __OMNETPP_ENVIR_EVENTLOGWRITER_H
#define __OMNETPP_ENVIR_EVENTLOGWRITER_H

#include <cstdio>
#include "envirdefs.h"
#include "omnetpp/simtime_t.h"

namespace omnetpp {
namespace envir {

class EventLogWriter
{
  public:
    static void recordLogLine(FILE *f, const char *prefix, const char *line, int lineLength);
    static void recordSimulationBeginEntry_ov_ev_rid(FILE *f, int omnetppVersion, int eventlogVersion, const char * runId);
    static void recordSimulationEndEntry_e_c_m(FILE *f, bool isError, int resultCode, const char * message);
    static void recordEventEntry_e_t_m_ce_msg(FILE *f, eventnumber_t eventNumber, simtime_t simulationTime, int moduleId, eventnumber_t causeEventNumber, msgid_t messageId);
    static void recordEventEntry_e_t_m_ce_msg_f(FILE *f, eventnumber_t eventNumber, simtime_t simulationTime, int moduleId, eventnumber_t causeEventNumber, msgid_t messageId, const char * fingerprints);
    static void recordSnapshotEntry_f_e_t(FILE *f, int64_t fileOffset, eventnumber_t eventNumber, simtime_t simulationTime);
    static void recordIndexEntry_f_i_s_e_t(FILE *f, int64_t fileOffset, int64_t previousIndexFileOffset, int64_t previousSnapshotFileOffset, eventnumber_t eventNumber, simtime_t simulationTime);
    static void recordReferenceEntry_e_b_e(FILE *f, eventnumber_t eventNumber, int beginEntryIndex, int endEntryIndex);
    static void recordReferenceFoundEntry_e_b_e(FILE *f, eventnumber_t eventNumber, int beginEntryIndex, int endEntryIndex);
    static void recordReferenceAddedEntry_e_b_e(FILE *f, eventnumber_t eventNumber, int beginEntryIndex, int endEntryIndex);
    static void recordReferenceRemovedEntry_e_b_e(FILE *f, eventnumber_t eventNumber, int beginEntryIndex, int endEntryIndex);
    static void recordModuleReferenceEntry_id(FILE *f, int moduleId);
    static void recordGateReferenceEntry_m_g(FILE *f, int moduleId, int gateId);
    static void recordConnectionReferenceEntry_sm_sg(FILE *f, int sourceModuleId, int sourceGateId);
    static void recordMessageReferenceEntry_id(FILE *f, msgid_t messageId);
    static void recordModuleDescriptionEntry_id_c_t_n(FILE *f, int moduleId, const char * moduleClassName, const char * nedTypeName, const char * fullName);
    static void recordModuleDescriptionEntry_id_c_t_pid_n_cm(FILE *f, int moduleId, const char * moduleClassName, const char * nedTypeName, int parentModuleId, const char * fullName, bool compoundModule);
    static void recordGateDescriptionEntry_m_g_n_o(FILE *f, int moduleId, int gateId, const char * name, bool isOutput);
    static void recordGateDescriptionEntry_m_g_n_i_o(FILE *f, int moduleId, int gateId, const char * name, int index, bool isOutput);
    static void recordConnectionDescriptionEntry_sm_sg_dm_dg(FILE *f, int sourceModuleId, int sourceGateId, int destModuleId, int destGateId);
    static void recordMessageDescriptionEntry_id_tid_eid_etid_c_n_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber);
    static void recordMessageDescriptionEntry_id_tid_eid_etid_c_n_k_p_l_er_m_sm_sg_st_am_ag_at_d_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64_t messageLength, bool hasBitError, int ownerModuleId, int senderModuleId, int senderGateId, simtime_t sendingTime, int arrivalModuleId, int arrivalGateId, simtime_t arrivalTime, const char * detail, eventnumber_t previousEventNumber);
    static void recordModuleDisplayStringEntry_id_d(FILE *f, int moduleId, const char * displayString);
    static void recordGateDisplayStringEntry_m_g_d(FILE *f, int moduleId, int gateId, const char * displayString);
    static void recordConnectionDisplayStringEntry_sm_sg_d(FILE *f, int sourceModuleId, int sourceGateId, const char * displayString);
    static void recordMessageDisplayStringEntry_id_d(FILE *f, msgid_t messageId, const char * displayString);
    static void recordComponentMethodBeginEntry_sm_tm_m(FILE *f, int sourceComponentId, int targetComponentId, const char * methodName);
    static void recordComponentMethodEndEntry(FILE *f);
    static void recordModuleCreatedEntry_id_c_t_n(FILE *f, int moduleId, const char * moduleClassName, const char * nedTypeName, const char * fullName);
    static void recordModuleCreatedEntry_id_c_t_pid_n_cm(FILE *f, int moduleId, const char * moduleClassName, const char * nedTypeName, int parentModuleId, const char * fullName, bool compoundModule);
    static void recordModuleDeletedEntry_id(FILE *f, int moduleId);
    static void recordGateCreatedEntry_m_g_n_o(FILE *f, int moduleId, int gateId, const char * name, bool isOutput);
    static void recordGateCreatedEntry_m_g_n_i_o(FILE *f, int moduleId, int gateId, const char * name, int index, bool isOutput);
    static void recordGateDeletedEntry_m_g(FILE *f, int moduleId, int gateId);
    static void recordConnectionCreatedEntry_sm_sg_dm_dg(FILE *f, int sourceModuleId, int sourceGateId, int destModuleId, int destGateId);
    static void recordConnectionDeletedEntry_sm_sg(FILE *f, int sourceModuleId, int sourceGateId);
    static void recordModuleDisplayStringChangedEntry_id_d(FILE *f, int moduleId, const char * displayString);
    static void recordGateDisplayStringChangedEntry_m_g_d(FILE *f, int moduleId, int gateId, const char * displayString);
    static void recordConnectionDisplayStringChangedEntry_sm_sg_d(FILE *f, int sourceModuleId, int sourceGateId, const char * displayString);
    static void recordMessageDisplayStringChangedEntry_id_d(FILE *f, msgid_t messageId, const char * displayString);
    static void recordCreateMessageEntry_id_tid_eid_etid_c_n_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber);
    static void recordCreateMessageEntry_id_tid_eid_etid_c_n_k_p_l_er_m_sm_sg_st_am_ag_at_d_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64_t messageLength, bool hasBitError, int ownerModuleId, int senderModuleId, int senderGateId, simtime_t sendingTime, int arrivalModuleId, int arrivalGateId, simtime_t arrivalTime, const char * detail, eventnumber_t previousEventNumber);
    static void recordCloneMessageEntry_id_tid_eid_etid_c_n_pe_cid(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber, msgid_t cloneId);
    static void recordCloneMessageEntry_id_tid_eid_etid_c_n_k_p_l_er_m_sm_sg_st_am_ag_at_d_pe_cid(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64_t messageLength, bool hasBitError, int ownerModuleId, int senderModuleId, int senderGateId, simtime_t sendingTime, int arrivalModuleId, int arrivalGateId, simtime_t arrivalTime, const char * detail, eventnumber_t previousEventNumber, msgid_t cloneId);
    static void recordDeleteMessageEntry_id_tid_eid_etid_c_n_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber);
    static void recordDeleteMessageEntry_id_tid_eid_etid_c_n_k_p_l_er_m_sm_sg_st_am_ag_at_d_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64_t messageLength, bool hasBitError, int ownerModuleId, int senderModuleId, int senderGateId, simtime_t sendingTime, int arrivalModuleId, int arrivalGateId, simtime_t arrivalTime, const char * detail, eventnumber_t previousEventNumber);
    static void recordEncapsulatePacketEntry_id_cid(FILE *f, msgid_t messageId, msgid_t encapsulatedPacketId);
    static void recordDecapsulatePacketEntry_id_cid(FILE *f, msgid_t messageId, msgid_t encapsulatedPacketId);
    static void recordBeginSendEntry_id_tid_eid_etid_c_n_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber);
    static void recordBeginSendEntry_id_tid_eid_etid_c_n_k_p_l_er_m_sm_sg_st_am_ag_at_d_pe_sd_up_tx(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64_t messageLength, bool hasBitError, int ownerModuleId, int senderModuleId, int senderGateId, simtime_t sendingTime, int arrivalModuleId, int arrivalGateId, simtime_t arrivalTime, const char * detail, eventnumber_t previousEventNumber, simtime_t sendDelay, bool isUpdate, txid_t transmissionId);
    static void recordEndSendEntry_id_tid_eid_etid_c_n_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber);
    static void recordEndSendEntry_id_tid_eid_etid_c_n_k_p_l_er_m_sm_sg_st_am_ag_at_d_pe_i(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64_t messageLength, bool hasBitError, int ownerModuleId, int senderModuleId, int senderGateId, simtime_t sendingTime, int arrivalModuleId, int arrivalGateId, simtime_t arrivalTime, const char * detail, eventnumber_t previousEventNumber, bool isDeliveredImmediately);
    static void recordSendDirectEntry_sm_dm_dg(FILE *f, int senderModuleId, int destModuleId, int destGateId);
    static void recordSendDirectEntry_sm_dm_dg_pd_td_rd(FILE *f, int senderModuleId, int destModuleId, int destGateId, simtime_t propagationDelay, simtime_t transmissionDelay, simtime_t remainingDuration);
    static void recordSendHopEntry_sm_sg(FILE *f, int senderModuleId, int senderGateId);
    static void recordSendHopEntry_sm_sg_pd_td_rd_d(FILE *f, int senderModuleId, int senderGateId, simtime_t propagationDelay, simtime_t transmissionDelay, simtime_t remainingDuration, bool discard);
    static void recordCancelEventEntry_id_tid_eid_etid_c_n_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber);
    static void recordCancelEventEntry_id_tid_eid_etid_c_n_k_p_l_er_m_sm_sg_st_am_ag_at_d_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64_t messageLength, bool hasBitError, int ownerModuleId, int senderModuleId, int senderGateId, simtime_t sendingTime, int arrivalModuleId, int arrivalGateId, simtime_t arrivalTime, const char * detail, eventnumber_t previousEventNumber);
    static void recordModuleFoundEntry_id_c_t_n_e_ei(FILE *f, int moduleId, const char * moduleClassName, const char * nedTypeName, const char * fullName, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex);
    static void recordModuleFoundEntry_id_c_t_pid_n_cm_e_ei(FILE *f, int moduleId, const char * moduleClassName, const char * nedTypeName, int parentModuleId, const char * fullName, bool compoundModule, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex);
    static void recordGateFoundEntry_m_g_n_o_e_ei(FILE *f, int moduleId, int gateId, const char * name, bool isOutput, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex);
    static void recordGateFoundEntry_m_g_n_i_o_e_ei(FILE *f, int moduleId, int gateId, const char * name, int index, bool isOutput, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex);
    static void recordConnectionFoundEntry_sm_sg_dm_dg_e_ei(FILE *f, int sourceModuleId, int sourceGateId, int destModuleId, int destGateId, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex);
    static void recordMessageFoundEntry_id_tid_eid_etid_c_n_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, eventnumber_t previousEventNumber);
    static void recordMessageFoundEntry_id_tid_eid_etid_c_n_k_p_l_er_m_sm_sg_st_am_ag_at_d_pe(FILE *f, msgid_t messageId, msgid_t messageTreeId, msgid_t messageEncapsulationId, msgid_t messageEncapsulationTreeId, const char * messageClassName, const char * messageName, short messageKind, short messagePriority, int64_t messageLength, bool hasBitError, int ownerModuleId, int senderModuleId, int senderGateId, simtime_t sendingTime, int arrivalModuleId, int arrivalGateId, simtime_t arrivalTime, const char * detail, eventnumber_t previousEventNumber);
    static void recordModuleDisplayStringFoundEntry_id_d_e_ei(FILE *f, int moduleId, const char * displayString, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex);
    static void recordGateDisplayStringFoundEntry_m_g_d_e_ei(FILE *f, int moduleId, int gateId, const char * displayString, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex);
    static void recordConnectionDisplayStringFoundEntry_sm_sg_d_e_ei(FILE *f, int sourceModuleId, int sourceGateId, const char * displayString, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex);
    static void recordMessageDisplayStringFoundEntry_id_d_e_ei(FILE *f, msgid_t messageId, const char * displayString, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex);
    static void recordBubbleEntry_id_txt(FILE *f, int moduleId, const char * text);
    static void recordCustomReferenceEntry_t_k(FILE *f, const char * type, long key);
    static void recordCustomDescriptionEntry_t_k_c(FILE *f, const char * type, long key, const char * content);
    static void recordCustomCreatedEntry_t_k_c(FILE *f, const char * type, long key, const char * content);
    static void recordCustomDeletedEntry_t_k(FILE *f, const char * type, long key);
    static void recordCustomChangedEntry_t_k_c(FILE *f, const char * type, long key, const char * content);
    static void recordCustomFoundEntry_t_k_c_e_ei(FILE *f, const char * type, long key, const char * content, eventnumber_t lastSeenEventNumber, int lastSeenEntryIndex);
    static void recordCustomEntry_t_k_c(FILE *f, const char * type, long key, const char * content);
};

} // namespace envir
}  // namespace omnetpp

#endif
