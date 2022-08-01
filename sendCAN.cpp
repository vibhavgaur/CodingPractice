#include <iostream>
#include "CAN.h"
#include <assert.h>
#include <bitset>


int main(){
    can_frame frame;
    frame.can_dlc = 8;
    uint8_t data [CAN_MAX_DLEN] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xFF};
    memcpy(frame.data, data, sizeof(data));
    
    canid_t ID = 0b1111 << 2;
    std::cout << std::bitset<sizeof(canid_t) * 8>(ID) << std::endl;
    printf("Size of ID: %d, ID = %X\n", sizeof(ID), ID);
    frame.can_id = (1) ? ID : 0;
    // assert(sizeof(frame.can_id) == 32);

    printFrame(&frame);
}