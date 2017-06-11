# all
all: main.o creatures.o
	g++ main.o creatures.o -o main

main.o: main.cpp creatures.h 
	g++ -c -g main.cpp 

creatures.o: creatures.cpp creatures.h
	g++ -c -g creatures.cpp

# clean
clean: rm -f *.o main
