#include "dashboard_node.h"
#include <stdio.h>

void dashboard_process(CAN_Bus *bus) {
    
    while(bus_available(bus)) {
        CAN_Frame frame = bus_receive(bus);
        
     
        if(frame.id == 0x100) {
            
            uint16_t rpm = (frame.data[0]<<8)|frame.data[1];
            printf("[DASHBOARD] RPM: %d\n", rpm);
            if(rpm > 7000) {
                printf("  RED ZONE WARNING!\n");
            }
        }
        else if(frame.id == 0x200) {
           
            uint8_t temp = frame.data[0];
            printf("[DASHBOARD] Temperature: %d°C\n", temp);
            if(temp>100) {
                printf(" ENGINE OVERHEATING!\n");
            }
        }
        else if(frame.id == 0x300) {
            uint8_t speed=frame.data[0];
            printf("[DASHBOARD] Speed: %d km/h\n", speed);
            if(speed>200){
                printf(" SPEED WARNING!\n");
            }
        }

        
        else if(frame.id == 0x400) {
            uint8_t fuel = frame.data[0];
    printf("[DASHBOARD] Fuel: %d%%\n", fuel);
    if(fuel < 10) {
        printf(" LOW FUEL WARNING!\n");
        }
    }
}
}