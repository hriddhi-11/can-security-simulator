#ifndef CAN_CRC_H
#define CAN_CRC_H

#include <stdint.h>
#include "can_frame.h"

// Function declaration
uint16_t calculate_crc15(CAN_Frame *frame);

#endif