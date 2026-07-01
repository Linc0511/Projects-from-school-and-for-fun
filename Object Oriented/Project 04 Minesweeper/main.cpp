//-------------------------------------------------------------------------------
// Programmer--Lincoln Keele
// Course------CS3123-01
// Project-----Program 04 Minesweeper
// Due---------April 1, 2026
//
// Main program for the Minesweeper game. Generates a new minefield and allows
// users to enter E, S or M to play the game. 
//-------------------------------------------------------------------------------

#include <iostream>
#include <cctype>
#include "Minefield.h"

using namespace std;

int main() 
{
    Minefield field;

    field.display();

    bool gameOn = true;

    while (gameOn) 
    {
        char action;
        int  row, col;

        cout << "\n\n   Action --- ";
        cin  >> action;
        action = toupper(action);

        if (action == 'E') 
        {
            cout << "Game Closed.\n";
            break;
        }

        cout << "   Row ------ ";
        cin  >> row;
        cout << "   Column --- ";
        cin  >> col;
        cout << "\n\n";

        if (action == 'S') 
        {
            gameOn = field.step(row, col);
            field.display();

            if (!gameOn)
            {
                cout << "Game over.\n";
            }
            else if (field.isWon()) 
            {
                cout << "Congratulations! You Win!\n";
                gameOn = false;
            }
        } 
        else if (action == 'M') 
        {
            field.mark(row, col);
            field.display();
        } 
        else 
        {
            cout << "Unknown action '" << action << "'. Use S, M, or E.\n";
            field.display();
        }
    }

    return 0;
}
