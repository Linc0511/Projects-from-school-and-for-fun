#-------------------------------------------------------
# This is minimal makefile for the intList and int Stack
#-------------------------------------------------------

CXX      = g++
CXXFLAGS = -Wall -std=c++11
OBJS     = main.o IntListStack.o

a.out: $(OBJS)
	$(CXX) $(CXXFLAGS) -o a.out $(OBJS)

main.o: main.cpp IntListStack.h
	$(CXX) $(CXXFLAGS) -c main.cpp

IntListStack.o: IntListStack.cpp IntListStack.h
	$(CXX) $(CXXFLAGS) -c IntListStack.cpp

clean:
	rm -f $(OBJS) a.out
