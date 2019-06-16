default: build

interlace.o:
	g++ -O2 -c -o interlace.o interlace.cpp

build:
	g++ -O2 -o il interlace.o main.cpp

catch.o:
	g++ -O2 -c -o catch.o tests_catch.cpp

tests: catch.o interlace.o
	g++ -O2 -o test catch.o interlace.o tests.cpp

clean:
	rm *.o
	rm *.out
	rm il
