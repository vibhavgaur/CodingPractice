#include <iostream>
#include <bitset>
#include <iomanip>

#define BINARY_CHUNK_SZ 4

struct can_frame{
    unsigned short canID;           // 11-bits of info in 16 bits of memory (standard ID)
    unsigned char rtr_ide_r0_dlc;   // 7 bits of info
    unsigned long long data;        // 64 bits of data
    unsigned short crc;             // 15 + 1 bits of info
    unsigned char ack;//:2;         // 2 bits of info (could be a bit field?)
    unsigned char eof;              // 7 bits of eof (all 1s)
} __attribute__((packed));

void printFrame (can_frame* frame){
    std::cout << "ID bytes: 11 bits of info in 16 bits of memory\n";
    std::cout << "decimal: " << std::dec << std::setw(4) <<  frame->canID 
                << "   hex: " << std::hex << std::setw(4) << "0x" << frame->canID 
                << "   bits: ";
    for (int i = 0; i < sizeof(frame->canID)*8 / BINARY_CHUNK_SZ; ++i)
        std::cout << std::bitset<sizeof(frame->canID)*8>(frame->canID).to_string().substr(i*BINARY_CHUNK_SZ, BINARY_CHUNK_SZ) << ' ';
    std::cout << "\n\n";

    std::cout << "RTR _ IDE _ r0 _ DLC bytes: 7 bits of info in 8 bits of memory\n";
    std::cout << "decimal: " << std::dec << std::setw(4) << (unsigned int) frame->rtr_ide_r0_dlc 
                << "   hex: " << std::hex << std::setw(4) << "0x" << (unsigned int) frame->rtr_ide_r0_dlc 
                << "   bits: ";
    for (int i = 0; i < sizeof(frame->rtr_ide_r0_dlc)*8 / BINARY_CHUNK_SZ; ++i)
        std::cout << std::bitset<sizeof(frame->rtr_ide_r0_dlc)*8>(frame->rtr_ide_r0_dlc).to_string().substr(i*BINARY_CHUNK_SZ, BINARY_CHUNK_SZ) << ' ';
    std::cout << "\n\n";
    
    std::cout << "Data bytes: 64 bits of info\n";
    std::cout << "decimal: " << std::dec << std::setw(4) << frame->data 
                << "    hex: " << std::hex << std::setw(4) << "0x" << frame->data 
                << "   bits: ";
    for (int i = 0; i < sizeof(frame->data)*8 / BINARY_CHUNK_SZ; ++i)
        std::cout << std::bitset<sizeof(frame->data)*8>(frame->data).to_string().substr(i*BINARY_CHUNK_SZ, BINARY_CHUNK_SZ) << ' ';
    std::cout << "\n\n";

    std::cout << "CRC: 15 bits of info + 1 bit delimiter\n";
    std::cout << "decimal: " << std::dec << std::setw(4) <<  frame->crc 
                << "   hex: " << std::hex << std::setw(4) << "0x" << frame->crc 
                << "   bits: ";
    for (int i = 0; i < sizeof(frame->crc)*8 / BINARY_CHUNK_SZ; ++i)
        std::cout << std::bitset<sizeof(frame->crc)*8>(frame->crc).to_string().substr(i*BINARY_CHUNK_SZ, BINARY_CHUNK_SZ) << ' ';
    std::cout << "\n\n";
    
    std::cout << "Ack: 1 bit of info + 1 bit delimiter\n";
    std::cout << "decimal: " << std::dec << std::setw(4) <<  (unsigned int) frame->ack 
                << "   hex: " << std::hex << std::setw(4) << "0x" << (unsigned int) frame->ack 
                << "   bits: ";
    for (int i = 0; i < sizeof(frame->ack)*8 / BINARY_CHUNK_SZ; ++i)
        std::cout << std::bitset<sizeof(frame->ack)*8>(frame->ack).to_string().substr(i*BINARY_CHUNK_SZ, BINARY_CHUNK_SZ) << ' ';
    std::cout << "\n\n";
    
    std::cout << "EOF: 7 bits all set to 1 in 8 bits of memory\n";
    std::cout << "decimal: " << std::dec << std::setw(4) <<  (unsigned int) frame->eof 
                << "   hex: " << std::hex << std::setw(4) << "0x" << (unsigned int) frame->eof 
                << "   bits: ";
    for (int i = 0; i < sizeof(frame->eof)*8 / BINARY_CHUNK_SZ; ++i)
        std::cout << std::bitset<sizeof(frame->eof)*8>(frame->eof).to_string().substr(i*BINARY_CHUNK_SZ, BINARY_CHUNK_SZ) << ' ';
    std::cout << "\n\n";    
}

void canToBits(can_frame* frame){
    // obtain a bitstream for the full CAN message
    std::cout << "Full CAN message bits: \n";
    std::cout << "Frame pointer: " << frame << '\n';
    char* byteArray = (char*) frame;
    std::cout << "Pointer to bytes: " << (void*) byteArray << '\n';
    for (int i = 0; i < sizeof(can_frame); ++i){
        std::cout << "Address pointed to : " << (void*) (byteArray + i) << " | Data: ";
        printf("0x%X\n", *(byteArray + i));
    }
    printf("\n");
    return;
}

void stuffBits(can_frame* frame){
    // stuff bits in case there are runs of 5 or more identical bit values
    std::cout << "Full CAN message after bit stuffing: \n";
    return;
}

int main(){
    can_frame f1;   // CAN message example obtained from https://en.wikipedia.org/wiki/CAN_bus#/media/File:CAN-bus-frame-with-stuff-bit-and-correct-CRC.png
    f1.canID = 0b00000010100;
    f1.rtr_ide_r0_dlc = 0b0000001;
    f1.data = 0b1;
    f1.crc = 0b1110111010100111;
    f1.ack = 0b01;
    f1.eof = 0b1111111;
    
    printFrame(&f1);
    std::cout << "Size of can_frame: " << sizeof(can_frame) << '\n';

    can_frame* f1_ptr = &f1;
    std::cout << "Pointer to f1: " << f1_ptr << '\n';
    printf("Thing pointed to by f1_ptr: %d\n", *((unsigned short *) f1_ptr));

    std::bitset<sizeof(f1.canID)*8> id_bits = f1.canID << 11;//*((unsigned short *) f1_ptr);
    std::cout << id_bits.to_string() << '\n';

    canToBits(&f1);
    stuffBits(&f1);
    return 0;
}