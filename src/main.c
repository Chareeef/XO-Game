#include <stdio.h>
#include "XO.h"

int main() {
  char board[SIZE][SIZE];
  char player = 'X';
  int move_success;
  int game_over = 0;

  init_board(board);

  while (!game_over) {
    print_board(board);
    move_success = 0;
    while (!move_success) {
      move_success = get_move(board, player);
    }

    if (check_win(board, player)) {
      printf("Le joueur %c a gagné!\n", player);
      game_over = 1;
    } else {
      if (player == 'X') {
        player = 'O';
      } else {
        player = 'X';
      }
    }
  }

  return 0;
}
