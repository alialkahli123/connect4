/* file: Connect4.cpp 
   An introductory/review assignment for CIS25
   */

#include <iostream>
#include <string>
#include "Connect4.h"
#include "constants.h"

using namespace std;



void initializeBoard (char board[][COLUMNS]){
	for(int i = 0; i < ROWS; i++){

        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = EMPTY_SQUARE;
        }

	}

}

bool placePiece(Player player, int column, char board[][COLUMNS]){

    if (column >= 1 && column <= COLUMNS && board[ROWS-ROWS][column-1] == EMPTY_SQUARE)
        return true;

    else
        return false;


}

void playGame(char board[][COLUMNS]) {
    int choice = 0, n =1, pieces = 0;
    int rowCounter[ROWS];
    bool invalid = true;
    bool win = false;

    for (int i = 0; i < ROWS; i++) {
        rowCounter[i] = ROWS-1;
    }

    while (!isDraw(pieces) && !win){

        while (invalid) {
            cout << "Player " << n << " Choose a column between 1-" << COLUMNS << endl;
            cin >> choice;
            invalid = false;
            if (choice < 1 || choice > COLUMNS){
                cout << BAD_COLUMN_MESSAGE << " Try Again" << endl;
                invalid =true;

            }
            else if (n == 1 && placePiece(PLAYER_ONE, choice, board) == false){
                cout << BAD_COLUMN_MESSAGE << " Try Again" << endl;
                invalid =true;
            }
            else if (n == 2 && placePiece(PLAYER_TWO, choice, board) == false) {
                cout << BAD_COLUMN_MESSAGE << " Try Again" << endl;
                invalid =true;
            }

        }

        if(n == 1 && placePiece(PLAYER_ONE, choice, board)){
                board[rowCounter[choice-1]][choice - 1] = PLAYER_ONE_PIECE;

                if (isWin(PLAYER_ONE, board)){
                    cout << PLAYER_ONE_WIN_MESSAGE << endl;
                    win = true;
                }
                rowCounter[choice-1] = rowCounter[choice-1] - 1;
                n++;
                pieces++;
                invalid = true;


        }
        else if(n == 2 && placePiece(PLAYER_TWO, choice, board)){
            board[rowCounter[choice-1]][choice - 1] = PLAYER_TWO_PIECE;
            if (isWin(PLAYER_TWO, board)) {
                cout << PLAYER_TWO_WIN_MESSAGE << endl;
                win = true;
            }

            rowCounter[choice-1] = rowCounter[choice-1] - 1;
            n--;
            pieces++;
            invalid = true;
        }




            boardToString(board);


    }




}

string boardToString(char board[][COLUMNS]){

     for(int i = 0; i < ROWS; i++){

        for (int j = 0; j < COLUMNS; j++) {
            cout << "  " << board[i][j] << "  " ;

        }
        cout << endl;

    }
    cout << endl;
     return "";


}

bool isDraw(int piecesPlayed){
	if (piecesPlayed == ROWS * COLUMNS) {
        return true;
    }
	return false;
}

bool isWin(Player player, char board[][COLUMNS]) {
    char piece;
    int counter = 0;
    if (player == PLAYER_ONE)
        piece = PLAYER_ONE_PIECE;
    else if (player == PLAYER_TWO)
        piece = PLAYER_TWO_PIECE;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            //checking vertical wins
            if (board[i][j] == piece) {

                for (int k = 0; k < PIECES_TO_WIN; k++) {

                    if (i + k < ROWS && board[i + k][j] == piece)
                        counter++;

                }
                if (counter == PIECES_TO_WIN) {
                    return true;
                }

                //checking horizontal
                counter = 0;
                for (int l = 0; l < PIECES_TO_WIN; l++) {

                    if (j+l < COLUMNS && board[i][j + l] == piece)
                        counter++;
                    if (board[i][j + l] != piece) {
                        l = 4;
                    }


                }
                if (counter == PIECES_TO_WIN) {
                    return true;
                }
                counter = 0;


                //checking diagonally
                for (int a = 0; a < PIECES_TO_WIN; a++) {
                    if (i + a >= 0 && j - a < COLUMNS && board[i + a][j - a] == piece) {
                        counter++;
                    }
                    if (board[i+a][j-a] != piece) {
                        a = 4;
                    }
                }
                if (counter == PIECES_TO_WIN) {
                    return true;
                }
                counter = 0;

                for (int c = 0; c < PIECES_TO_WIN; c++) {
                    // i+c and j+c are equal so it is unnecessary to write j+c < Columns
                    if (i+c < ROWS && board[i+c][i+c] == piece)
                        counter++;

                if (board[i+c][i+c])
                    c = 4;

                }

                if (counter == PIECES_TO_WIN) {
                    return true;
                }


        }



        }
    }
    return false;

}

