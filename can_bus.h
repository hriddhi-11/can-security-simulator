#ifndef CAN_BUS_H
#define CAN_BUS_H

#include "can_frame.h"

#define BUS_SIZE 100

typedef struct {
    CAN_Frame frames[BUS_SIZE];
    int count;
} CAN_Bus;

void bus_init(CAN_Bus *bus);
void bus_send(CAN_Bus *bus, CAN_Frame frame);
CAN_Frame bus_receive(CAN_Bus *bus);
int bus_available(CAN_Bus *bus);

#endif