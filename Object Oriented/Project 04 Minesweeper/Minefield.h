//-------------------------------------------------------------------------------
// Programmer--Lincoln Keele
// Course------CS3123-01
// Project-----Program 04 Minesweeper
// Due---------April 1, 2026
//
// Header file for the Minefield class. Declares methods for initializing the 
// grid, displaying it, stepping on cells, marking cells,
// flood-filling empty regions, and checking win and loss conditions.
// This class manages the board and the pointers.
//-------------------------------------------------------------------------------

#ifndef MINEFIELD_H
#define MINEFIELD_H

#include "Cells.h"

class Minefield 
{
    public:
        static const int ROWS = 8;
        static const int COLS = 48;
        Minefield();
        ~Minefield();
        void display() const;
        bool step(int row, int col);
        void mark(int row, int col);
        bool isWon() const;
        void revealAll();

    private:
        Cell* grid_[ROWS][COLS];
        int countAdjacentMines(int row, int col) const;
        void floodFill(int row, int col);
        bool inBounds(int row, int col) const;
};

#endif