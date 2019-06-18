#include <string.h>
#include <iostream>
#include <filesystem>
#include "interlace.h"

int main(int argc, char** argv){

	bool pipeFromStdIn = false;

	std::string result_of_interlace;
	std::vector<std::string> filenames = {};
    //std::cout << "Welcome!" << std::endl;

	// 0th elemnt is the command itself.
	// this causes really weird things when it is detected as a valid file, and then used in the interlacing process.
	// DO NOT set this to 0
    for (int argnum = 1; argnum < argc; argnum++){
        std::string arg = argv[argnum];
		if (std::filesystem::exists(arg)){
			filenames.push_back(arg);
		//	std::cout << "{" << argnum << "}: " << arg << std::endl;
		} else if (arg == "--stdin" | arg == "-p"){
			pipeFromStdIn = true;
		} else {
		//	std::cout << "[" << argnum << "]: " << arg << std::endl;
		}
    }

	// TODO: add code for stdin input option
	if (pipeFromStdIn){
        filenames.insert(filenames.begin(), "/dev/stdin");
	}

	result_of_interlace = interlace(filenames);
	std::cout << result_of_interlace;
	return 0;
}
