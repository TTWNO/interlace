default: build

interlace.o:
	g++ -O2 -c -o interlace.o interlace.cpp

build: interlace.o
	g++ -std=c++17 -O2 -o il interlace.o main.cpp -lstdc++fs

catch.l:
	g++ -O2 -c -o catch.l tests_catch.cpp

tests: catch.l interlace.o
	g++ -O2 -o test catch.l interlace.o tests.cpp

clean:
	rm *.o
	rm il
	rm test

distclean: clean
	rm catch.l
