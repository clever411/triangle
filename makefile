all: main

run: main
	main

main: main.cpp
	g++ -o main main.cpp
