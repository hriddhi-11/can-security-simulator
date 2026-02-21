#include "attacker_node.h"
#include "can_frame.h"
#include <stdio.h> 

void attacker_spoof_rpm(CAN_Bus *bus, uint16_t fake_rpm) {
    
    CAN_Frame fake_frame = create_rpm_frame(fake_rpm, 1);
    
    
    bus_send(bus, fake_frame);
    
    
    printf("[ATTACKER] 🔴 SPOOFING! Injecting fake RPM=%d (ID:0x100)\n", fake_rpm);
}