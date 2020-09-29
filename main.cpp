/* file: main.cpp
   -----------
   The main function for your program. Note: I will be testing this with
   my *own* version of main. For your program to work, all of the
   required functions from the prompt / starter code must work correctly
   -- it won't pass the functionality tests if your program works with
   your main function but not mine. */
#include <iostream>
#include "Connect4.h"

int main() {
char board[ROWS][COLUMNS];

initializeBoard(board);
boardToString(board);
playGame(board);

}