run:
	g++ -o main -O3 $(wildcard main.cpp src/*.cpp) && ./main

clean:
	rm -f main