build:
	@g++ -o prime-generator -O3 $(wildcard main.cpp src/*.cpp)

install:
	build
	
clean:
	@rm -f prime-generator