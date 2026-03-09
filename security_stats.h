#ifndef SECURITY_STATS_H
#define SECURITY_STATS_H
#include <stdint.h>
typedef struct{
    int total_messages;
    int legitimate_messages;
    int attack_attempts;
    int attacks_detected;
    int attacks_blocked;
    int spoofing_attacks;
    int dos_attacks;
    int replay_attacks;
    int max_messages_per_cycle;
} SecurityStats;
void  stats_init(SecurityStats* stats);
void stats_record_legitimate(SecurityStats *stats);
void stats_record_attack(SecurityStats *stats);
void stats_record_spoofing(SecurityStats *stats);
void stats_record_dos(SecurityStats *stats);
void stats_record_replay(SecurityStats *stats);
void stats_update_max_messages(SecurityStats *stats,int count);
void stats_print_report(SecurityStats *stats,int total_cycles);

#endif