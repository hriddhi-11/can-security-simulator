#include "detector_node.h"
#include <stdio.h>
void detector_process(CAN_Bus *bus,CAN_Bus *filtered_bus){
    int malicious_count=0;
    int legitimate_count=0;
    while(bus_available(bus)){
            CAN_Frame frame=bus_receive(bus);
            if(frame.source==0){
                bus_send(filtered_bus,frame);
                legitimate_count++;
            }else if(frame.source == 1) { 
            printf("[DETECTOR] 🚨 ATTACK DETECTED! ");
            printf("Blocking malicious frame (ID:0x%03X, Source:%d)\n", 
                   frame.id, frame.source);
            malicious_count++;
        }
    }
    if(malicious_count > 0) {
        printf("[DETECTOR] Security Report: %d legitimate, %d blocked\n", 
               legitimate_count, malicious_count);
    }
} 


