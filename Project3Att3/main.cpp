#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>



using namespace std;

int board[10][10]; // Holds the randomly Generated Numbers
bool selectedSpace[10][10]; // Holds the boolean values to determine if a number is visable

void setupBoard(); // Set up board
void printBoard(); // Print board
int getRow(); // Player Get row
int getCol(); // Player Get Column
int selectSpace(int row, int col); // Select a space
int scorePoints(int move1, int move2, int move3); // Determine points

int playerMove(); // player makes move
int CPU1Move(); // CPU makes move
int CPU2Move();

int playerTurn(); // player makes turn
int CPU1Turn(); // CPU makes turn
int CPU2Turn();

int main(){

    // Keep This For Randomization
    srand(time(nullptr));



    /// Variable declerations

    // Initial variables for scorekeeping
    int playerPoints = 0;
    int CPU1Points = 0;
    int CPU2Points = 0;
    int spacesRemaining = 100;


    /// Program start


    setupBoard();  //  Generated Board
    printBoard(); // Print initial state



    while(playerPoints < 200 && CPU1Points < 200 && CPU2Points < 200) { // until someone reaches 2-- points


    playerPoints = playerPoints + playerTurn(); // Run functions for player and add points
    spacesRemaining = spacesRemaining - 3;
    CPU1Points = CPU1Points + CPU1Turn(); // Run functions for CPU1 and add points
    spacesRemaining = spacesRemaining - 3;
    CPU2Points = CPU2Points + CPU2Turn(); // Run functions for CPU2 and add points
    spacesRemaining = spacesRemaining - 3;

    cout << "Player Points: " << playerPoints << endl; // Print player Points
    cout << "CPU1 Points: " << CPU1Points << endl; // Print CPU1 Points
    cout << "CPU2 Points: " << CPU2Points << endl; // Print CPU2 Points
    cout << "Spaces Remaining: " << spacesRemaining << endl;
    cout << endl;
    _sleep(4000); // Delay to draw out program
    }

    printBoard(); // Print board at end of the game

    if (playerPoints > CPU1Points && playerPoints > CPU2Points) { // If player Wins
        cout << "Player Wins with: " << playerPoints << " Points." << endl;
    }
    else if (CPU1Points > playerPoints && CPU1Points > CPU2Points) { // if CPU1 Wins
        cout << "Player Wins with: " << playerPoints << " Points." << endl;
    }
    else if (CPU2Points > playerPoints && CPU2Points > CPU1Points) { // If CPU2 Wins
        cout << "Player Wins with: " << playerPoints << " Points." << endl;
    }
    cout << endl;
    // Print out How many Points each had at the end of the game.
    cout << "Player had: " << playerPoints << " Points" << endl;
    cout << "CPU1 had: " << CPU1Points << " Points" << endl;
    cout << "CPU2 had: " << CPU2Points << " Points" << endl;
    return 0;
}


void setupBoard() { //
    for (int i = 0; i < 10; i++) { // For Each row
        for (int j = 0; j < 10; j++) { // For Each column
            board[i][j] = (rand() % 9 + 1); // Set Board to have a random number 1-9
            selectedSpace[i][j] = false; // Make sure each space is not visable
        }
    }

}
void printBoard() {
     for (int i = 0; i < 10; i++) { // For Each row
        for (int j = 0; j < 10; j++) { // For Each column
            if (selectedSpace[i][j] == true) { // Check if space has already been selected
                cout << board[i][j] << " "; // if so, print number
            }
            else {
                cout << "* "; // else print a star
            }
        }
        cout << endl;
    }

}


int getRow() {  // Used for the player to Select a row
    int Row = -1;
    while (true) {
        cout << "Enter target row: ";
        cin >> Row;
        if (Row > 0 && Row < 11) {
            return Row - 1;
        }
        else {
            cout << "Invalid row, Please select a number 1 to 10" << endl;
        }
    }
}

int getCol() { // Used for the player to Select a Column
    int Col = -1;
    while (true) {
        cout << "Enter target Column: ";
        cin >> Col;
        if (Col > 0 && Col < 11) {
            return Col - 1;
        }
        else {
            cout << "Invalid row, Please select a number 1 to 10" << endl;
        }
    }
}

int selectSpace(int row, int col) { // when a player selects a space from getRow() and getCol()
    selectedSpace[row][col] = true; // Make it visable
    return board[row][col]; // Print the value in it

}

int scorePoints(int move1, int move2, int move3) { // take in the values of each selected space
    int roundPoints;
    roundPoints = move1 + move2 + move3; // add them into roundPoints
    if (move1 < move2 && move2 < move3) { // if m1 < m2 < m3
        roundPoints = roundPoints * 2; // double points
        cout << "Ascending Numbers Bonus X2" << endl;
    }
    if (move1 > move2 && move2 > move3) { // if m1 > m2 > m3
        roundPoints = roundPoints * 2; // double points
        cout << "Descending Numbers Bonus X2" << endl;
    }
    if ((move1 == move2) && (move2 == move3) && (move1 == move3)) { // if all are the same
        roundPoints = roundPoints * 3; // triple points
        cout << "Triple Duplicate Bonus" << endl;
    }
    if ((move1 == move2) || (move2 == move3) || (move1 == move3)) { // if there is at least one duplicate
        roundPoints = roundPoints * 2;  // double points
        cout << "Duplicate Bonus X2" << endl;
    }
    cout << roundPoints << " Points this round" << endl; // print result
    return roundPoints; // return result
}

int playerMove() { // Player move, executed 3 times per turn
    while (true) { // Until valid move
        int rowCord;
        int colCord;
        int moveScore;
        rowCord = getRow(); // get row
        colCord = getCol(); // get colums

        if (selectedSpace[rowCord][colCord] == false) { // check that it has not been selected yet
            moveScore = selectSpace(rowCord, colCord); // if not, run selectSpace and return the result.
            cout << "You got: " << moveScore << endl;
            return moveScore;
        }
        else {
            cout << "Space has already been selected" << endl;
            _sleep(1000);
        }
    }
}

int playerTurn() {

    int move1;
    int move2;
    int move3;

    // Player makes their moves here
    move1 = playerMove(); // Move1
    printBoard();
    move2 = playerMove(); // Move2
    printBoard();
    move3 = playerMove(); // Move3
    printBoard();
    cout << "Player got the numbers: " << move1 << " " << move2 << " " << move3 << endl;
    return scorePoints(move1, move2, move3); // Find out final scores and return the result



}

int CPU1Move() { // CPU1 move, executed 3 times per turn
    while (true) {
        int rowCord;
        int colCord;
        rowCord = (rand() % 10); // Pick random Row
        colCord = (rand() % 10); // Pick random Colums

        if (selectedSpace[rowCord][colCord] == false) { // Check if spot has been selected
            _sleep(2000); // Delay to draw out program
            cout << "CPU1 Picked (" << rowCord + 1 << ","<< colCord + 1 << ")" << endl;
            return selectSpace(rowCord, colCord); // Select a space and return result
        }
    }


}

int CPU1Turn() {
    int move1;
    int move2;
    int move3;

    move1 = CPU1Move(); // Move1
    printBoard();
    move2 = CPU1Move(); // Move2
    printBoard();
    move3 = CPU1Move(); // Move3
    printBoard();
    cout << "CPU1 got the numbers: " << move1 << " " << move2 << " " << move3 << endl;

    return scorePoints(move1, move2, move3); // Find out final scores and return the result

}

int CPU2Move() { // CPU2 move, executed 3 times per turn
    while (true) {
        int rowCord;
        int colCord;

        for (int rowCord = 0; rowCord < 10; rowCord++) { // For Each row
            for (int colCord = 0; colCord < 10; colCord++) { // For Each column
                if (selectedSpace[rowCord][colCord] == false) {  // Check if spot has been selected
                    _sleep(2000); // Delay to draw out program
                    cout << "CPU2 Picked (" << rowCord + 1 << ","<< colCord + 1 << ")" << endl;
                    return selectSpace(rowCord, colCord); // Select a space and return result
                }
            }
        }
    }


}

int CPU2Turn() {
    int move1;
    int move2;
    int move3;

    move1 = CPU2Move(); // Move1
        //cout << "TEST OUTPUT: " << move1 << endl;
    printBoard();
    move2 = CPU2Move(); // Move2
        //cout << "TEST OUTPUT: " << move2 << endl;
    printBoard();
    move3 = CPU2Move(); // Move3
        //cout << "TEST OUTPUT: " << move3 << endl;
    printBoard();
    cout << "CPU2 got the numbers: " << move1 << " " << move2 << " " << move3 << endl;

    return scorePoints(move1, move2, move3); // Find out final scores and return the result


}