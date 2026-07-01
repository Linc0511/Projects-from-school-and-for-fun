#-------------------------------------------------------
# This is a minimal makefile for the SearchTree class
#-------------------------------------------------------
a.out: main.o SearchTree.o
	g++ main.o SearchTree.o -o a.out

main.o: main.cpp SearchTree.h
	g++ -c main.cpp

SearchTree.o: SearchTree.cpp SearchTree.h
	g++ -c SearchTree.cpp

clean:
	rm -f *.o a.out