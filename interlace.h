#include <string>
#include <vector>

std::vector<std::string> get_file_contents_as_vector_lines(std::string filename, bool ignore_newline=true);
std::string get_file_contents(std::string filename);
std::vector<std::string> interlace_vectors(std::vector<std::vector<std::string>> vectors_to_combine);
std::string interlace(std::vector<std::string> filenames, std::string file_seperator="\n", std::string line_seperator="\n", bool strip_newlines=true);
