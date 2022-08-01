#include <iostream>

struct {
    int number;
    bool someTruth;
} CANMsg_globalscope;

struct Something {
    int x;
    int y {};
    int z {2};
};

class MyClass {
    public:
        int numClass;
        bool truthClass;
};

int main(){
    std::cout << "Global Scope CAN Msg: " << std::endl;
    std::cout << CANMsg_globalscope.number << std::endl;
    std::cout << CANMsg_globalscope.someTruth << std::endl;

    struct {
        int number;
        bool someTruth;
    } CANMsg_localscope;

    std::cout << "CAN Msg defined in main(): " << std::endl;
    std::cout << CANMsg_localscope.number << std::endl;
    std::cout << CANMsg_localscope.someTruth << std::endl;

    int x;
    std::cout << "Value of local int x: " << x << std::endl;

    Something s1;
    std::cout << "s1.x = " << s1.x << std::endl;
    std::cout << "s1.y = " << s1.y << std::endl;
    std::cout << "s1.z = " << s1.z << std::endl;
    
    Something s2 {69, 420, 'A'};
    std::cout << "s2.x = " << s2.x << std::endl;
    std::cout << "s2.y = " << s2.y << std::endl;
    std::cout << "s2.z = " << s2.z << std::endl;

    MyClass class1;
    std::cout << "class1.numClass = " << class1.numClass << std::endl;
    std::cout << "class1.truthClass = " << class1.truthClass << std::endl;

    
    return 0;
}