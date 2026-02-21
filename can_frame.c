#include "can_frame.h"
#include "can_crc.h"     
#include <stdio.h>

CAN_Frame create_rpm_frame(uint16_t rpm,uint8_t source) {
    CAN_Frame frame;
    frame.id = 0x100;
    frame.dlc = 2;
    frame.data[0] = (rpm >> 8) & 0xFF;
    frame.data[1] = rpm & 0xFF;
    frame.rtr = 0;
    frame.crc = calculate_crc15(&frame);
    frame.source=source;
    return frame;
}

CAN_Frame create_temp_frame(uint8_t temperature,uint8_t source) {
    CAN_Frame frame;
    frame.id = 0x200;
    frame.dlc = 1;
    frame.data[0] = temperature;
    frame.rtr = 0;
    frame.crc = calculate_crc15(&frame);
    return frame;
}
CAN_Frame create_frame(uint16_t id,uint8_t *data,uint8_t dlc,uint8_t source){
    CAN_Frame frame;
    frame.id=id;
    frame.dlc=dlc;
    for(int i=0;i<dlc;i++){
        frame.data[i]=data[i];
    }
    frame.rtr=0;
    frame.crc=calculate_crc15(&frame);
    frame.source=source;
    return frame;

}

void print_can_frame(CAN_Frame *frame) {
    printf("========================================\n");
    printf("CAN Frame\n");
    printf("========================================\n");
    printf("ID:        0x%03X (%d)\n", frame->id, frame->id);
    printf("DLC:       %d bytes\n", frame->dlc);
    printf("Data:      ");
    for(int i = 0; i < frame->dlc; i++) {
        printf("[0x%02X] ", frame->data[i]);
    }
    printf("\n");
    printf("RTR:       %d (%s)\n", frame->rtr, frame->rtr ? "Remote" : "Data Frame");
    printf("CRC:       0x%04X\n", frame->crc);
    printf("========================================\n");
}