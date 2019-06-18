#include "catch.hpp"
#include "interlace.h"

TEST_CASE("Test that tests work", "[base]"){
	CHECK(1 == 1);
}

TEST_CASE("Test that file contents are recieved properly", "[get_file_contents]"){
    CHECK(get_file_contents("txt/short_file_test.txt") == "Hi, I wrote this software!");
}

TEST_CASE("Test that file contents are recieved properly when in a list", "[get_file_contents_as_vector_lines]"){
    std::vector<std::string> short_file_lines = {"Hi, I wrote this software!"};
	std::vector<std::string> hello_lines = {"hello"};
	std::vector<std::string> world_lines = {"world"};
    CHECK(get_file_contents_as_vector_lines("txt/short_file_test.txt") == short_file_lines);
	CHECK(get_file_contents_as_vector_lines("txt/hello.txt") == hello_lines);
	CHECK(get_file_contents_as_vector_lines("txt/world.txt") == world_lines);
}

TEST_CASE("Test that the interlace_vector function works", "[interlace_vecto]"){
	std::vector<std::string> hello_world_vector = {"hello", "world"};
	std::vector<std::string> hw_short_vector = {"hello", "Hi, I wrote this software!", "world", ""};
	CHECK(interlace_vectors({get_file_contents_as_vector_lines("txt/hello.txt"), get_file_contents_as_vector_lines("txt/world.txt")}) == hello_world_vector);
	CHECK(interlace_vectors({get_file_contents_as_vector_lines("txt/hello_world.txt"), get_file_contents_as_vector_lines("txt/short_file_test.txt")}) == hw_short_vector);
}

TEST_CASE("Test that the interlace function works with default paramaters, 2 files", "[interlace]"){
    CHECK(interlace({"txt/hello_world.txt", "txt/short_file_test.txt"}) == get_file_contents("txt/hw_short.txt"));
    CHECK(interlace({"txt/hello.txt", "txt/world.txt"}) == get_file_contents("txt/hello_world.txt"));
    CHECK(interlace({"txt/1-3.txt", "txt/4-6.txt", "txt/7-9.txt"}) == get_file_contents("txt/1-9.txt"));
    CHECK(interlace({"txt/longer_output.txt", "txt/longer_output_2.txt"}) == get_file_contents("txt/longer_output_ild.txt"));
} 
