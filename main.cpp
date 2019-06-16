#include <string.h>
#include <iostream>

int main(int argc, char** argv){
    std::cout << "Welcome!" << std::endl;

    for (int argnum = 0; argnum < argc; argnum++){
        std::string arg = argv[argnum];
        std::cout << "[" << argnum << "]: " << arg << std::endl;
    }
}
