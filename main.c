#include <stdio.h>
#include "can_bus.h"
#include "ecu_node.h"
#include "dashboard_node.h"
#include "attacker_node.h"
#include "detector_node.h"
#include "security_stats.h"


int main() {
    printf("=== CAN Bus Security Simulator ===\n\n");
    
  
    CAN_Bus raw_bus;        
    CAN_Bus filtered_bus;   
    bus_init(&raw_bus);
    bus_init(&filtered_bus);
    
    
    ECU_Data ecu;
    ecu_init(&ecu);

    SecurityStats stats;
    stats_init(&stats);
    

    for(int cycle = 1; cycle <= 15; cycle++) {
        printf("\n--- Cycle %d ---\n", cycle);
        
        
        ecu_update(&ecu);
        printf("[ECU] Sending legitimate data...\n");
        ecu_send_all(&ecu, &raw_bus);
        
        
        if(cycle % 3 == 0) {
            attacker_spoof_rpm(&raw_bus, 9999); 
            stats_record_attack(&stats) ;
        }
        
       
        detector_process(&raw_bus,&filtered_bus,&stats);
        
       
        dashboard_process(&filtered_bus);
    }
    stats_print_report(&stats,15);
    printf("\n=== Simulation Complete ===\n");
    printf("Dashboard was protected from all attacks!\n");
    
    return 0;
}