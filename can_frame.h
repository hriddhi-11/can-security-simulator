#ifndef CAN_FRAME_H    
#define CAN_FRAME_H    
#include <stdint.h>

typedef struct {
    uint16_t id;
    uint8_t dlc;
    uint8_t data[8];
    uint8_t rtr;
    uint16_t crc;
    uint8_t source;
} CAN_Frame;


CAN_Frame create_rpm_frame(uint16_t rpm,uint8_t source);
CAN_Frame create_temp_frame(uint8_t temperature,uint8_t source);
CAN_Frame create_frame(uint16_t id,uint8_t *data,uint8_t dlc,uint8_t source);
void print_can_frame(CAN_Frame *frame);

#endif  