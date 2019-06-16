#include <fstream>
#include <sstream>
#include <iostream>
#include "interlace.h"

std::vector<std::string> get_file_contents_as_vector_lines(std::string filename, bool ignore_newlines){
    std::vector<std::string> contents;
    std::string line;
    std::ifstream ifile(filename, std::ios::in);

    if (ifile.is_open()){
        while (getline(ifile, line)){
            if (ignore_newlines && line != ""){
                contents.push_back(line);
            }
        }
        ifile.close();
    } else {
        std::cerr << "Error opening file!\n";
    }
    return contents;
}

std::string get_file_contents(std::string filename){
    std::stringstream contents;
    std::string line;
    std::ifstream ifile(filename, std::ios::in);

    if (ifile.is_open()){
        while (getline(ifile, line) && line != ""){
            contents << line;
            contents << "\n";
        }
        ifile.close();
    } else {
        std::cerr << "Error opening file!\n";
    }
    return contents.str();
}

std::string concat(std::vector<std::string> list, std::string seperator){
    std::string result;
    for (int i = 0; i < list.size(); i++){
        result += list.at(i);
        if (i < list.size()-1){
            result += seperator;
        }
    }
    return result;
}

std::string interlace(std::vector<std::string> filenames, std::string file_seperator, std::string line_seperator, bool strip_newlines){
    int max_lines = 0;
    int num_of_lines;
    std::string this_line;
    std::string result = "";
    std::vector<std::vector<std::string>> files_contents;
    for (auto file : filenames){
        std::vector<std::string> file_contents = get_file_contents_as_vector_lines(file);
        files_contents.push_back(file_contents);
    }
    // find largest number of lines
    for (auto file : files_contents){
        num_of_lines = files_contents.size();
        if (num_of_lines > max_lines){
            max_lines = num_of_lines;
        }
    }
    // construct return value
    for (int line_num = 0; line_num < max_lines; line_num++){
        for (auto file_contents : files_contents){
            if (line_num < file_contents.size()){
                this_line = file_contents.at(line_num);
                result += file_contents.at(line_num); 
            } else {
                result += "";
            }
            result += file_seperator;
        }
        result += line_seperator;
    }
    return result;
}
