all: main

main:
	g++ main.o -o simulator -lsfml-graphics -lsfml-window -lsfml-system

build:
	cmake -B build
	cmake --build build

clean:
	rm -f *.o
	rm -f simulator
	rm -rf build