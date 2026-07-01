//-------------------------------------------------------------------------------
// Programmer--Lincoln Keele
// Course------CS3123-01
// Project-----Program 04 Minesweeper
// Due---------April 1, 2026
//
// Implements the Minefield class. Builds the 8x48 grid of Cell pointers,
// places mines, and handles all game logic and actions.
//-------------------------------------------------------------------------------

#include <iostream>
#include "Minefield.h"

using namespace std;

//-------------------------------------------------------------------------------
// Minefield()
//
// Allocates the grid and populates it with CoveredCell objects, placing
// mines at the hard-coded locations defined inside the constructor.
//-------------------------------------------------------------------------------
Minefield::Minefield() 
{
    const int mineList[][2] = 
    {
        {0,4}, {0,47},
        {1,30},
        {2,0}, {2,2}, {2,4},
        {3,30},
        {4,30},
        {5,30}, {5,31},
        {7,31}, {7,47}
    };
    const int mineCount = sizeof(mineList) / sizeof(mineList[0]);

    bool mineMap[ROWS][COLS] = {};
    for (int i = 0; i < mineCount; ++i)
    {
        mineMap[mineList[i][0]][mineList[i][1]] = true;
    }
    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            grid_[r][c] = new CoveredCell(mineMap[r][c]);
        }
    }
}

//-------------------------------------------------------------------------------
// ~Minefield()
//
// Deallocates every Cell object in the grid.
//-------------------------------------------------------------------------------
Minefield::~Minefield() 
{
    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            delete grid_[r][c];
        }
    }
}

//-------------------------------------------------------------------------------
// display()
//
// Prints the current minefield to the console.
//-------------------------------------------------------------------------------
void Minefield::display() const {
    cout << "               1         2         3         4\n";
    cout << "     012345678901234567890123456789012345678901234567\n";
    cout << "   +==================================================+\n";
    for (int r = 0; r < ROWS; ++r) 
    {
        cout << r << "  | ";
        for (int c = 0; c < COLS; ++c)
        {
            cout << grid_[r][c]->getDisplay();
        }
        cout << " |\n";
    }
    cout << "   +==================================================+\n";
}

//-------------------------------------------------------------------------------
// step()
//
// Steps on the cell at (row, col). It can uncover a new tile and reveal all 
// other tiles until a number tile is revealed. It can end the game if a mine 
// is stepped on.
//-------------------------------------------------------------------------------
bool Minefield::step(int row, int col) 
{
    if (!inBounds(row, col)) 
    {
        return true;
    }
    Cell* cell = grid_[row][col];
    if (cell->isUncovered() || cell->isFlagged()) 
    {
        return true;
    }
    bool hasMine = cell->isMine();
    int  adj     = countAdjacentMines(row, col);

    delete grid_[row][col];
    grid_[row][col] = new UncoveredCell(hasMine, adj);

    if (hasMine) 
    {
        revealAll();
        return false;
    }

    if (adj == 0)
    {
        floodFill(row, col);
    }
    return true;
}

//-------------------------------------------------------------------------------
// mark()
//
// Cycles the mark state of the covered cell at (row, col) through
// UNMARKED -> FLAGGED -> UNKNOWN -> UNMARKED. Has no effect on uncovered
// cells.
//-------------------------------------------------------------------------------
void Minefield::mark(int row, int col) 
{
    if (!inBounds(row, col)) 
    {
        return;
    }
    if (grid_[row][col]->isUncovered()) 
    {
        return;
    }
    CoveredCell* cc = static_cast<CoveredCell*>(grid_[row][col]);
    cc->cycleMarkState();
}

//-------------------------------------------------------------------------------
// isWon()
//
// Returns true when every non-mine cell in the grid has been uncovered,
// indicating the player has won the game.
//-------------------------------------------------------------------------------
bool Minefield::isWon() const 
{
    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            if (!grid_[r][c]->isMine() && !grid_[r][c]->isUncovered())
            {
                return false;
            }
        }
    }    
    return true;
}

//-------------------------------------------------------------------------------
// revealAll()
//
// Uncovers all remaining hidden mine cells by replacing them with
// UncoveredCell objects. Called when the player steps on a mine.
//-------------------------------------------------------------------------------
void Minefield::revealAll() 
{
    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            if (!grid_[r][c]->isUncovered() && grid_[r][c]->isMine()) 
            {
                delete grid_[r][c];
                grid_[r][c] = new UncoveredCell(true, 0);
            }
        }
    }
}

//-------------------------------------------------------------------------------
// countAdjacentMines()
//
// Counts and returns the number of mines in the up-to-8 neighboring cells
// surrounding (row, col).
//-------------------------------------------------------------------------------
int Minefield::countAdjacentMines(int row, int col) const {
    int count = 0;
    for (int dr = -1; dr <= 1; ++dr)
        for (int dc = -1; dc <= 1; ++dc) 
        {
            if (dr == 0 && dc == 0) 
            {
                continue;
            }
            int nr = row + dr, nc = col + dc;
            if (inBounds(nr, nc) && grid_[nr][nc]->isMine())
            {
                ++count;
            }   
        }
    return count;
}

//-------------------------------------------------------------------------------
// floodFill()
//
// Recursively uncovers all neighboring covered, non-mine, non-flagged
// cells starting from (row, col). Propagation continues through cells
// with zero adjacent mines and stops at numbered cells.
//-------------------------------------------------------------------------------
void Minefield::floodFill(int row, int col) 
{
    for (int dr = -1; dr <= 1; ++dr)
    {
        for (int dc = -1; dc <= 1; ++dc) 
        {
            if (dr == 0 && dc == 0) continue;
            int nr = row + dr, nc = col + dc;
            if (!inBounds(nr, nc)) continue;

            Cell* neighbor = grid_[nr][nc];
            if (neighbor->isUncovered() || neighbor->isFlagged()) 
            {
                continue;
            }
            if (neighbor->isMine()) 
            {
                continue;
            }

            int adj = countAdjacentMines(nr, nc);
            delete grid_[nr][nc];
            grid_[nr][nc] = new UncoveredCell(false, adj);

            if (adj == 0)
            {
                floodFill(nr, nc);
            }
        }
    }
}

//-------------------------------------------------------------------------------
// inBounds()
//
// Returns true if (row, col) falls within the valid grid boundaries.
//-------------------------------------------------------------------------------
bool Minefield::inBounds(int row, int col) const 
{
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}