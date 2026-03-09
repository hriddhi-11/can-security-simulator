#include "attacker_node.h"
#include "can_frame.h"
#include <stdio.h> 

void attacker_spoof_rpm(CAN_Bus *bus, uint16_t fake_rpm) {
    
    CAN_Frame fake_frame = create_rpm_frame(fake_rpm, 1);
    
    
    bus_send(bus, fake_frame);
    
    
    printf("[ATTACKER] 🔴 SPOOFING! Injecting fake RPM=%d (ID:0x100)\n", fake_rpm);
}
void attacker_dos_flood(CAN_Bus *bus,int flood_count){
    printf("[ATTACKER] 💀 DoS ATTACK! Flooding bus with %d messages...\n", flood_count);
    for(int i=0;i<flood_count;i++){
        CAN_Frame spam_frame=create_frame(0x7FF,(uint8_t[]){0xFF, 0xFF},2,1);
        bus_send(bus,spam_frame);
    }
    printf("[ATTACKER] 💀 Sent %d spam messages!\n", flood_count);
}