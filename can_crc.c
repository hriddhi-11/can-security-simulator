#include "can_crc.h"

// Helper function
void process_bit(uint8_t bit, uint16_t *crc) {
     *crc = (*crc << 1) | bit;
        if (*crc & 0x8000) {
            *crc ^= 0x4599;
        }
        *crc &= 0x7FFF;
}

// CRC calculation
uint16_t calculate_crc15(CAN_Frame *frame) {
       uint16_t crc = 0;

    
    // Process one bit at a time
   
    
    // Add ID bits (11 bits)
    for(int i = 10; i >= 0; i--) {
        process_bit((frame->id >> i) & 1, &crc);
    }
    
    // Add RTR bit
    process_bit(frame->rtr,&crc);
    
    // Add IDE bit (0 for standard)
    process_bit(0, &crc);
    
    // Add reserved bit (0)
     process_bit(0, &crc);
    
    // Add DLC bits (4 bits)
    for(int i = 3; i >= 0; i--) {
        process_bit((frame->dlc>>i)&1, &crc);
    }
    
    // Add data bits
    for(int i = 0; i < frame->dlc; i++) {
        for(int j = 7; j >= 0; j--) {
            process_bit((frame->data[i]>>j)&1, &crc);
        }
    }
    
    return crc;
}