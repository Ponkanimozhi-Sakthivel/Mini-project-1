#include <stdio.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the board
void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to display the board
void displayBoard() {
    printf("Tic Tac Toe\n");
    printf("-------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("-------------\n");
}

// Function to check if the board is full
int isBoardFull() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '-') {
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}

// Function to check if there is a winner
char checkWinner() {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return board[i][0];
        }
    }
    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '-') {
            return board[0][j];
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
        return board[0][2];
    }
    return ' '; // No winner yet
}

// Fun
