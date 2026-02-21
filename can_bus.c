#include "can_bus.h"


void bus_init(CAN_Bus *bus) {
   bus->count=0;
}


void bus_send(CAN_Bus *bus, CAN_Frame frame) {
    bus->frames[bus->count]=frame;
    bus->count++;
}


CAN_Frame bus_receive(CAN_Bus *bus) {
  CAN_Frame first=bus->frames[0];
  for(int i=0;i<bus->count-1;i++){
    bus->frames[i]=bus->frames[i+1];
  }
  bus->count--;
  return first;
}


int bus_available(CAN_Bus *bus) {
    
    return bus->count;
}