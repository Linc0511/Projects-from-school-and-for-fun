#-------------------------------------------------------
# This is minimal makefile for the Minesweeper project
#-------------------------------------------------------

CXX      = g++
CXXFLAGS = -Wall -std=c++11
TARGET   = a.out
OBJS     = main.o Minefield.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp Minefield.h Cells.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Minefield.o: Minefield.cpp Minefield.h Cells.h
	$(CXX) $(CXXFLAGS) -c Minefield.cpp

clean:
	rm -f $(OBJS) $(TARGET)
