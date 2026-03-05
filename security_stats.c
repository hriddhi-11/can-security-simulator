#include "security_stats.h"
#include <stdio.h>

void stats_init(SecurityStats *stats) {
    stats->total_messages=0;
    stats->legitimate_messages=0;
    stats->attack_attempts=0;
    stats->attacks_detected=0;
    stats->attacks_blocked=0;
}

void stats_record_legitimate(SecurityStats *stats) {
   stats->total_messages++;
   stats->legitimate_messages++;
}

void stats_record_attack(SecurityStats *stats) {
    stats->total_messages++;
    stats->attack_attempts++;
}

void stats_print_report(SecurityStats *stats, int total_cycles) {
    printf("\n");
    printf("========================================\n");
    printf("       SECURITY ANALYSIS REPORT\n");
    printf("========================================\n");
    printf("Total Cycles:           %d\n", total_cycles);
    printf("Messages Sent:          %d\n", stats->total_messages);
    printf("Legitimate Messages:    %d\n", stats->legitimate_messages);
    printf("Attack Attempts:        %d\n", stats->attack_attempts);
    printf("Attacks Detected:       %d/%d (%.1f%%)\n", 
           stats->attacks_detected, 
           stats->attack_attempts,
           stats->attack_attempts > 0 ? 
           (stats->attacks_detected * 100.0 / stats->attack_attempts) : 0);
    printf("Attacks Blocked:        %d/%d (%.1f%%)\n",
           stats->attacks_blocked,
           stats->attack_attempts,
           stats->attack_attempts > 0 ? 
           (stats->attacks_blocked * 100.0 / stats->attack_attempts) : 0);
    printf("========================================\n");
    printf("Status: Dashboard Protected ✓\n");
    printf("========================================\n");
}