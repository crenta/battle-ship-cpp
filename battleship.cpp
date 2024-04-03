#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void battle_ship_placement(char ships[4][4])
{
    //initialize random number generator
    srand(time(NULL));

    //initialize ships placed to 0
    int ships_placed = 0;
    //we will drop 4 ships on the map
    while(ships_placed < 4)
    {    
        //rand() % 4 generates a random number in the range [0, 3] 
        //because the remainder when dividing any number by 4 can be 0, 1, 2, or 3.
        //Adding 1 to the result of rand() % 4 shifts this range to [1, 4]
        int row = rand() % 4;
        int column = rand() % 4;

        if (ships[row][column] != 'O')
        {
            ships[row][column] = 'O';
            ++ships_placed;
        }
    }
}

void printBoard(char ships[4][4]) {
    cout << "\n*********************************************"<< endl;
    cout << "       Welcome to the Battle Ship Game!" << endl;
    cout << "*********************************************\n"<< endl;

    cout << "*********************************************"<< endl;
    cout << "      As soon as this game started," << endl;
    cout << "we generated a 4x4 random board just for you!" << endl;
    cout << "*********************************************\n"<< endl;

    cout << "*********************************************"<< endl;
    cout << "       You will have a board similar to: " << endl;
    cout << "     columns:    0, 1, 2, 3         " << endl;
    for(int i = 0; i < 4; i++) {
        cout << "               { ";
        for(int j = 0; j < 4; j++) {
            switch(ships[i][j]) {
                case 'O':
                    cout << "O, "; // Ship
                    break;
                case 'X':
                    cout << "X, "; // Hit
                    break;
                default:
                    cout << "., "; // Empty
            }
        }
        cout << "}  row " << i << endl;
    }
    cout << "*********************************************\n"<< endl;
}

int main()
{
    //initialize the 4x4 vector in our main function
    char ships[4][4] = {{'.'}}; // Initialize all elements with '.'

    //this will load the board up with random booleans using our function
    battle_ship_placement(ships);
    printBoard(ships);

    cout << "*********************************************"<< endl;
    cout << "              **INSTRUCTIONS**" << endl;
    cout << " You have ONLY 4 tries to enter the correct" <<endl;
    cout << "coordinates to the position of the battleship!\n" << endl;
    cout << "   First, enter a row number: 0 - 3" << endl;
    cout << "   then, enter a column number: 0 - 3"<< endl;
    cout << "*********************************************\n"<< endl;

    int tries = 0;
    bool guessed_correctly = false; // Indicates if a correct guess has been made

    while (tries < 4) {
        int guess_row;
        int guess_column;
        cout << "Enter your row guess '0', '1', '2', or '3': ";
        cin >> guess_row;
        cout << "Enter your column guess '0', '1', '2', or '3': ";
        cin >> guess_column;

        if (ships[guess_row][guess_column] == 'O') {
            cout << "Congratulations, you hit a ship!" << endl;
            ships[guess_row][guess_column] = 'X'; // Mark hit on the board
            printBoard(ships);
            guessed_correctly = true; // Set to true to allow another guess
        } else {
            cout << "Missed, try again!" << endl;
            tries++;
        }

        if (guessed_correctly && tries < 4) {
            cout << "You can guess again!" << endl;
            guessed_correctly = false; // Reset the flag
        }
    }

    if (tries == 4) {
        cout << "Sorry, you've run out of tries. Game over!" << endl;
    }

    return 0;
}