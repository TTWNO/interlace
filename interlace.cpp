#include <fstream>
#include <sstream>
#include <iostream>
#include "interlace.h"


std::vector<std::string> get_file_contents_as_vector_lines(std::string filename, bool ignore_newlines){
    std::vector<std::string> contents = {};
    std::string line = "";
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
	std::string result = "";
    std::string line;
    std::ifstream ifile(filename, std::ios::in);

    if (ifile.is_open()){
        while (getline(ifile, line) && line != ""){
            result += line;
            result += "\n";
        }
        ifile.close();
    } else {
        std::cerr << "Error opening file!\n";
    }
	result[result.length()-1] = '\0';
    return result;
}

std::vector<std::string> interlace_vectors(std::vector<std::vector<std::string>> vectors){
	int max_vector_items = 0;
	std::vector<std::string> result = {};
	// finds longest series in each vector
	for (auto vi : vectors){
		int vi_size = vi.size();
		if (vi_size > max_vector_items){
			max_vector_items = vi_size;
		}
	}
	// interlaces the items the order they appear in the vector on input.
	// e.g. {{"1", "2", "3"}, {"4", "5", "6"}}
	// would be {"1", "4", "2", "5", "3", "6"}
	// if any of the lists are longr than the others, blank strings are stored there.
	for (int vi_index = 0; vi_index < max_vector_items; vi_index++){
		for (auto vi : vectors){
			if (vi_index < vi.size()){
				result.push_back(vi.at(vi_index));
			} else {
				result.push_back("");
			}
		}
	}
	return result;
}

std::string interlace(std::vector<std::string> filenames, std::string file_seperator, std::string line_seperator, bool strip_newlines){
    int max_lines = 0;
    int num_of_lines;
    std::string this_line;
    std::string result = "";
    std::vector<std::vector<std::string>> files_contents = {};
    for (auto file : filenames){
        std::vector<std::string> file_contents = get_file_contents_as_vector_lines(file);
        files_contents.push_back(file_contents);
    }
	std::vector<std::string> lines = interlace_vectors(files_contents);
	for (int i = 0; i < lines.size(); i++){
		result += lines.at(i) + "\n";
	}
	// remove traling newline
	result[result.length()-1] = '\0';
	return result;
}
