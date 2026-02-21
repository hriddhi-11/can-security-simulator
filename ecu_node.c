#include "ecu_node.h"
#include "can_frame.h"

void ecu_init(ECU_Data *ecu) {
    ecu->rpm=800;
    ecu->temperature=70;
    ecu->speed=0;
    ecu->fuel=100;
}

void ecu_update(ECU_Data *ecu) {
    
    ecu->rpm+=100;
    if(ecu->rpm >8000) ecu->rpm=800;
    ecu->temperature=70+(ecu->rpm/200);
    ecu->fuel--;
}

void ecu_send_all(ECU_Data *ecu, CAN_Bus *bus) {
    CAN_Frame rpm_frame=create_rpm_frame(ecu->rpm,0);
    bus_send(bus,rpm_frame);
    CAN_Frame temp_frame=create_temp_frame(ecu->temperature,0);
    bus_send(bus,temp_frame);
    uint8_t speed_data[]={ecu->speed};
    CAN_Frame speed_frame=create_frame(0x300,speed_data,1,0);
    bus_send(bus,speed_frame);
    uint8_t fuel_data[] = {ecu->fuel};
    CAN_Frame fuel_frame = create_frame(0x400, fuel_data, 1,0);
    bus_send(bus, fuel_frame);

}