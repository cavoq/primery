run:
	g++ -o main -O3 $(wildcard src/*.cpp main.cpp) && ./main

clean:
	rm -f main