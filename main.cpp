#include <string.h>
#include <iostream>
#include <filesystem>

int main(int argc, char** argv){
    std::cout << "Welcome!" << std::endl;

    for (int argnum = 0; argnum < argc; argnum++){
        std::string arg = argv[argnum];
		if (std::filesystem::exists(arg)){
			std::cout << "{" << argnum << "}: " << arg << std::endl;
		} else {
			std::cout << "[" << argnum << "]: " << arg << std::endl;
		}
    }
}
