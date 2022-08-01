#ifndef CAN_H_
#define CAN_H_

#include <stdint.h>
#include <iomanip>

#define CAN_MAX_DLEN        8       // Max data length for CAN Message

/*
 * Controller Area Network Identifier structure
 *
 * bit 0-28 : CAN identifier (11/29 bit)
 * bit 29   : error message frame flag (0 = data frame, 1 = error message)
 * bit 30   : remote transmission request flag (1 = rtr frame)
 * bit 31   : frame format flag (0 = standard 11 bit, 1 = extended 29 bit)
 */
typedef uint32_t canid_t;           // 32-bit unsigned value
typedef uint8_t __u8;               // 8-bit unsigned value

struct can_frame {
    canid_t   can_id;                 // 32-bit CAN ID
    __u8      can_dlc;                // data payload length [0, CAN_MAX_DLEN]
    __u8      data[CAN_MAX_DLEN];     // data bytes
};


// Function prototypes
// void printData(const uint8_t* data);


// Function definitions
void printData(const uint8_t* data){
    std::cout << "| ";
    for (int i = 0; i < CAN_MAX_DLEN; ++i)
        std::cout << std::hex << std::setw(2) << std::uppercase << (unsigned int) data[i] << std::dec << " ";
    std::cout << "|" << std::endl;
    return;
}

void printFrame(const can_frame* frame){
    std::cout << "CAN ID: 0x" << std::hex << std::setw(16) << std::setfill('0') << std::uppercase << (unsigned int) frame->can_id << std::endl;
    std::cout << "CAN DLC: " << (unsigned int) frame->can_dlc << std::endl;
    std::cout << "CAN data: ";
    printData(frame->data);
    return;
}

#endif // CAN_H_