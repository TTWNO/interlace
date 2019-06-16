#include "catch.hpp"
#include "interlace.h"

TEST_CASE("Test that tests work", "[base]"){
	REQUIRE(1 == 1);
}

TEST_CASE("Test that file contents are recieved properly", "[get_file_contents]"){
    REQUIRE(get_file_contents("txt/short_file_test.txt") == "Hi, I wrote this software!\n");
}

TEST_CASE("Test that file contents are recieved properly when in a list", "[get_file_contents_as_vector_lines]"){
    std::vector<std::string> short_file_lines = {"Hi, I wrote this software!"};
    REQUIRE(get_file_contents_as_vector_lines("txt/short_file_test.txt") == short_file_lines);
}

TEST_CASE("Test that the interlace function works with default paramaters, 2 files", "[interlace]"){
    REQUIRE(interlace({"txt/hello.txt", "txt/world.txt"}) == get_file_contents("txt/hello_world.txt"));
} 
