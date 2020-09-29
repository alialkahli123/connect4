/* file: Connect4.h
   Function prototypes & constants for the Connect 4 assignment
   */

#ifndef CONNECT_4_H
#define CONNECT_4_H

#include <string>
#include "constants.h"

// CIS25 note: this line will NOT be allowed in any of the assignments
// after this one.
using namespace std;

void initializeBoard(char board[][COLUMNS]);

// return true if piece placed. presumes there's a place to place it.
bool placePiece(Player player, int column, char board[][COLUMNS]); 

void playGame(char board[][COLUMNS]);

// returns a string representation of the current state of the board.
string boardToString(char board[][COLUMNS]);

bool isWin(Player player, char board[][COLUMNS]);

bool isDraw(int playedPieces);

void checkVert(char board[][COLUMNS], int choice, int row);
/* REMOVE EVERYTHING BELOW HERE FOR STARTER CODE VERSION */

#endif
