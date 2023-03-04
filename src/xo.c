#include <stdio.h>
#include "XO.h"

void init_board(char board[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

void print_board(char board[SIZE][SIZE]) {
  printf("    0   1   2\n");
  for (int i = 0; i < SIZE; i++) {
    printf("  %d ", i);
    for (int j = 0; j < SIZE; j++) {
      printf(" %c |", board[i][j]);
    }
    printf("\n  ---------\n");
  }
}


int get_move(char board[SIZE][SIZE], char player) {
  int row, col;
  printf("Joueur %c, entrez une ligne (0, 1, 2) : ", player);
  scanf("%d", &row);
  printf("Joueur %c, entrez une colonne (0, 1, 2) : ", player);
  scanf("%d", &col);

  if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
    board[row][col] = player;
    return 1;
  } else {
    printf("Mouvement non valide, veuillez réessayer.\n");
    return 0;
  }
}

int check_win(char board[SIZE][SIZE], char player) {
  // Vérifie les lignes
  for (int i = 0; i < SIZE; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return 1;
    }
  }

  // Vérifie les colonnes
  for (int i = 0; i < SIZE; i++) {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return 1;
    }
  }

  // Vérifie les diagonales
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return 1;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return 1;
  }

  return 0;
}
