#include "detector_node.h"
#include <stdio.h>
void detector_process(CAN_Bus *bus, CAN_Bus *filtered_bus, SecurityStats *stats) {
    int malicious_count = 0;
    int legitimate_count = 0;
    int spoofing_detected = 0;  // ← ADD THIS
    
    // Count total messages on bus
    int total_on_bus = bus_available(bus);
    
    // Update peak traffic
    stats_update_max_messages(stats, total_on_bus);
    
    // DoS detection
    int dos_threshold = 20;
    if(total_on_bus > dos_threshold) {
        printf("[DETECTOR] 🚨 DoS ATTACK DETECTED! ");
        printf("Bus flooded with %d messages (normal: 4-5)\n", total_on_bus);
        stats_record_dos(stats);
        stats->attacks_detected++;
        stats->attacks_blocked++;  // ← ADD THIS (block the DoS attack)
    }
    
    // Process all messages
    while(bus_available(bus)) {
        CAN_Frame frame = bus_receive(bus);
        
        if(frame.source == 0) {  // Legitimate ECU
            bus_send(filtered_bus, frame);
            legitimate_count++;
            stats_record_legitimate(stats);
        }
        else if(frame.source == 1) {  // Attacker
            malicious_count++;
            
            // Count spoofing attacks (non-spam messages)
            if(frame.id != 0x7FF) {  // Not spam, it's spoofing
                if(spoofing_detected == 0) {  // Only count once
                    stats->attacks_detected++;  // ← ADD THIS
                    stats->attacks_blocked++;   // ← ADD THIS
                    spoofing_detected = 1;
                }
            }
        }
    }
    
    // Summary
    if(malicious_count > 0) {
        printf("[DETECTOR] Blocked %d malicious messages, forwarded %d legitimate\n", 
               malicious_count, legitimate_count);
    }
}


