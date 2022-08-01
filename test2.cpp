#include <iostream>
using namespace std;

// struct __attribute__((packed)) s{
struct s{
    unsigned char a = 1;
    unsigned short b = 2;
    unsigned char c = 3;
};

int main(){
    s p;
    char* ptr = (char*) &p;
    printf("%d\n", sizeof(s));
    std::cout << "Size of struct p: " << sizeof(p) << " bytes\n";
    for (int i = 0; i < sizeof(p); ++i){
        printf("Byte number: %d\nHex: 0x%X\nDec: %d\n", i, ptr[i], ptr[i]);
    }
}