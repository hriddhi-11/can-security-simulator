#ifndef ATTACKER_NODE_H
#define ATTACKER_NODE_H

#include "can_bus.h"


void attacker_spoof_rpm(CAN_Bus *bus, uint16_t fake_rpm);

#endif