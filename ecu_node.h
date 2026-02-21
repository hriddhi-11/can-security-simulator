#ifndef ECU_NODE_H
#define ECU_NODE_H

#include "can_bus.h"

// ECU data structure
typedef struct {
    uint16_t rpm;        
    uint8_t temperature; 
    uint8_t speed;       
    uint8_t fuel;        
} ECU_Data;

// Function declarations
void ecu_init(ECU_Data *ecu);
void ecu_update(ECU_Data *ecu);
void ecu_send_all(ECU_Data *ecu, CAN_Bus *bus);

#endif