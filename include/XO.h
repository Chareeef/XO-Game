#ifndef XO_H
#define XO_H

#define SIZE 3

void init_board(char board[SIZE][SIZE]);
void print_board(char board[SIZE][SIZE]);
int get_move(char board[SIZE][SIZE], char player);
int check_win(char board[SIZE][SIZE], char player);

#endif
