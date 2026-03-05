#ifndef DETECTOR_NODE_H
#define DETECTOR_NODE_H

#include "can_bus.h"
#include "security_stats.h"


void detector_process(CAN_Bus *bus, CAN_Bus *filtered_bus, SecurityStats *stats);

#endif