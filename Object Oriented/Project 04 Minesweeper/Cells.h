//-------------------------------------------------------------------------------
// Programmer--Lincoln Keele
// Course------CS3123-01
// Project-----Program 04 Minesweeper
// Due---------April 1, 2026
//
// Header file for the Cell base class, CoveredCell derived class, and
// UncoveredCell derived class. Cell defines the common interface for all
// minefield cells. CoveredCell represents a hidden cell that cycles through
// unmarked, flagged, and unknown mark states. UncoveredCell represents a
// revealed cell that displays a mine, an adjacent mine count, or a blank.
//-------------------------------------------------------------------------------

#ifndef CELLS_H
#define CELLS_H

class Cell {
public:
    virtual ~Cell() {}
    virtual char getDisplay() const = 0;
    virtual bool isMine() const = 0;
    virtual bool isUncovered() const = 0;
    virtual bool isFlagged() const = 0;
};

class CoveredCell : public Cell {
public:
    enum MarkState { UNMARKED, FLAGGED, UNKNOWN };
    CoveredCell(bool hasMine) : mine_(hasMine), markState_(UNMARKED) {}

    char getDisplay() const override {
        switch (markState_) {
            case FLAGGED:  return 'F';
            case UNKNOWN:  return '?';
            default:       return '.';
        }
    }

    bool isMine() const override { return mine_; }
    bool isUncovered() const override { return false; }
    bool isFlagged() const override { return markState_ == FLAGGED; }

    void cycleMarkState() {
        switch (markState_) {
            case UNMARKED: markState_ = FLAGGED;  break;
            case FLAGGED:  markState_ = UNKNOWN;  break;
            case UNKNOWN:  markState_ = UNMARKED; break;
        }
    }

    MarkState getMarkState() const { return markState_; }

private:
    bool      mine_;
    MarkState markState_;
};

class UncoveredCell : public Cell {
public:
    UncoveredCell(bool hasMine, int adjacentMines)
        : mine_(hasMine), 
          adjacentMines_(adjacentMines) {}

    char getDisplay() const override {
        if (mine_)
        {               
            return 'M';
        }
        if (adjacentMines_ == 0) 
        {
            return ' ';
        }
        return '0' + adjacentMines_;
    }

    bool isMine() const override { return mine_; }
    bool isUncovered() const override { return true; }
    bool isFlagged() const override { return false; }
    int getAdjacentMines() const { return adjacentMines_; }

private:
    bool mine_;
    int  adjacentMines_;
};

#endif
