default: build

build:
	g++ -O2 -o interlace interlace.cpp

catch.o:
	g++ -O2 -c -o catch.o tests_catch.cpp

tests: catch.o
	g++ -O2 -o tests.out catch.o tests.cpp

clean:
	rm *.o
	rm *.out
	rm interlace
