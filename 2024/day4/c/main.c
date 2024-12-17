#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int XMAS_LEN = 3;

int check_for_xmas(int columns_total, int rows_total,
                   char arr[columns_total][rows_total], int x, int y,
                   char build_arr[columns_total][rows_total]) {
  int count = 0;
  bool up = false;
  bool down = false;
  bool left = false;
  bool right = false;

  if (y - XMAS_LEN >= 0) {
    up = true;
  }

  if (XMAS_LEN + y <= rows_total) {
    down = true;
  }

  if (x - XMAS_LEN >= 0) {
    left = true;
  }

  if (XMAS_LEN + x <= columns_total) {
    right = true;
  }

  if (up) {
    if (arr[x][y - 1] == 'M' && arr[x][y - 2] == 'A' && arr[x][y - 3] == 'S') {
      count += 1;
      printf("UP: %c%c%c%c POS: %d:%d\n", 'X', arr[x][y - 1], arr[x][y - 2],
             arr[x][y - 3], x, y);
      build_arr[x][y] = 'X';
      build_arr[x][y - 1] = 'M';
      build_arr[x][y - 2] = 'A';
      build_arr[x][y - 3] = 'S';
    }
  }

  if (down) {
    if (arr[x][y + 1] == 'M' && arr[x][y + 2] == 'A' && arr[x][y + 3] == 'S') {
      count += 1;
      printf("DOWN: %c%c%c%c POS: %d:%d\n", 'X', arr[x][y + 1], arr[x][y + 2],
             arr[x][y + 3], x, y);
      build_arr[x][y] = 'X';
      build_arr[x][y + 1] = 'M';
      build_arr[x][y + 2] = 'A';
      build_arr[x][y + 3] = 'S';
    }
  }

  if (left) {
    if (arr[x - 1][y] == 'M' && arr[x - 2][y] == 'A' && arr[x - 3][y] == 'S') {
      count += 1;
      printf("LEFT: %c%c%c%c POS: %d:%d\n", 'X', arr[x - 1][y], arr[x - 2][y],
             arr[x - 3][y], x, y);
      build_arr[x][y] = 'X';
      build_arr[x - 1][y] = 'M';
      build_arr[x - 2][y] = 'A';
      build_arr[x - 3][y] = 'S';
    }
  }

  if (right) {
    if (arr[x + 1][y] == 'M' && arr[x + 2][y] == 'A' && arr[x + 3][y] == 'S') {
      count += 1;
      printf("RIGHT: %c%c%c%c POS: %d:%d\n", 'X', arr[x + 1][y], arr[x + 2][y],
             arr[x + 3][y], x, y);
      build_arr[x][y] = 'X';
      build_arr[x + 1][y] = 'M';
      build_arr[x + 2][y] = 'A';
      build_arr[x + 3][y] = 'S';
    }
  }
  if (up && right) {
    if (arr[x + 1][y - 1] == 'M' && arr[x + 2][y - 2] == 'A' &&
        arr[x + 3][y - 3] == 'S') {
      count += 1;
      printf("UP RIGHT: %c%c%c%c POS: %d:%d\n", 'X', arr[x + 1][y - 1],
             arr[x + 2][y - 2], arr[x + 3][y - 3], x, y);
      build_arr[x][y] = 'X';
      build_arr[x + 1][y - 1] = 'M';
      build_arr[x + 2][y - 2] = 'A';
      build_arr[x + 3][y - 3] = 'S';
    }
  }

  if (right && down) {
    if (arr[x + 1][y + 1] == 'M' && arr[x + 2][y + 2] == 'A' &&
        arr[x + 3][y + 3] == 'S') {
      count += 1;
      printf("RIGHT DOWN: %c%c%c%c POS: %d:%d\n", 'X', arr[x + 1][y + 1],
             arr[x + 2][y + 2], arr[x + 3][y + 3], x, y);
      build_arr[x][y] = 'X';
      build_arr[x + 1][y + 1] = 'M';
      build_arr[x + 2][y + 2] = 'A';
      build_arr[x + 3][y + 3] = 'S';
    }
  }

  if (down && left) {
    if (arr[x - 1][y + 1] == 'M' && arr[x - 2][y + 2] == 'A' &&
        arr[x - 3][y + 3] == 'S') {
      count += 1;
      printf("DOWN LEFT: %c%c%c%c POS: %d:%d\n", 'X', arr[x - 1][y + 1],
             arr[x - 2][y + 3], arr[x - 3][y + 3], x, y);
      build_arr[x][y] = 'X';
      build_arr[x - 1][y + 1] = 'M';
      build_arr[x - 2][y + 2] = 'A';
      build_arr[x - 3][y + 3] = 'S';
    }
  }

  if (left && up) {
    if (arr[x - 1][y - 1] == 'M' && arr[x - 2][y - 2] == 'A' &&
        arr[x - 3][y - 3] == 'S') {
      count += 1;
      printf("LEFT UP: %c%c%c%c POS: %d:%d\n", 'X', arr[x - 1][y - 1],
             arr[x - 2][y - 2], arr[x - 3][y - 3], x, y);
      build_arr[x][y] = 'X';
      build_arr[x - 1][y - 1] = 'M';
      build_arr[x - 2][y - 2] = 'A';
      build_arr[x - 3][y - 3] = 'S';
    }
  }
  return count;
}

int check_for_two_mas(int columns_total, int rows_total,
                      char arr[columns_total][rows_total], int x, int y,
                      char build_arr[columns_total][rows_total]) {
  int count = 0;
  bool up = false;
  bool down = false;
  bool left = false;
  bool right = false;

  bool can_happen = false;

  if (x > 0 && x <= columns_total && y > 0 && y < rows_total) {
    can_happen = true;
  }
  if (y != 0) {
    up = true;
  }

  if (y != rows_total) {
    down = true;
  }

  if (x != 0) {
    left = true;
  }

  if (x != columns_total) {
    right = true;
  }

  bool mas_up_left = false;
  bool mas_up_right = false;
  bool mas_down_right = false;
  bool mas_down_left = false;

  if (can_happen) {
    if (arr[x - 1][y - 1] == 'M' && arr[x + 1][y + 1] == 'S') {
      mas_up_left = true;
    }
    if (arr[x + 1][y - 1] == 'M' && arr[x - 1][y + 1] == 'S') {
      mas_up_right = true;
    }
    if (arr[x + 1][y + 1] == 'M' && arr[x - 1][y - 1] == 'S') {
      mas_down_right = true;
    }
    if (arr[x - 1][y + 1] == 'M' && arr[x + 1][y - 1] == 'S') {
      mas_down_left = true;
    }

    if (x == 2 && y == 1) {
      printf("2:1 %b up_left: %c down_left: %c x: %d y: %d\n", can_happen,
             arr[1][0], arr[x + 1][y + 1], x, y);
    }

    if (mas_up_left && mas_down_left) {
      build_arr[x - 1][y - 1] = 'M';
      build_arr[x + 1][y + 1] = 'S';

      build_arr[x][y] = 'A';

      build_arr[x - 1][y + 1] = 'M';
      build_arr[x + 1][y - 1] = 'S';
      count += 1;
    } else if (mas_up_left && mas_up_right) {
      build_arr[x - 1][y - 1] = 'M';
      build_arr[x + 1][y + 1] = 'S';

      build_arr[x][y] = 'A';

      build_arr[x + 1][y - 1] = 'M';
      build_arr[x - 1][y + 1] = 'S';
      count += 1;
    } else if (mas_down_right && mas_up_right) {
      build_arr[x + 1][y + 1] = 'M';
      build_arr[x - 1][y - 1] = 'S';

      build_arr[x][y] = 'A';

      build_arr[x + 1][y - 1] = 'M';
      build_arr[x - 1][y + 1] = 'S';
      count += 1;
    } else if (mas_down_right && mas_down_left) {
      build_arr[x + 1][y + 1] = 'M';
      build_arr[x - 1][y - 1] = 'S';

      build_arr[x][y] = 'A';

      build_arr[x - 1][y + 1] = 'M';
      build_arr[x + 1][y - 1] = 'S';
      count += 1;
    }
  }

  return count;
}

int count_rows(FILE *file) {
  if (file == NULL) {
    printf("Unable to open file.\n");
    return 0;
  }

  char ch;
  int count = 0;

  while (!feof(file)) {
    ch = fgetc(file);
    if (ch == '\n') {
      count += 1;
    }
  }

  printf("row_count: %d\n", count);
  return count;
}

int count_columns(FILE *file) {
  if (file == NULL) {
    printf("Unable to open file.\n");
    return 0;
  }

  char ch;
  int count = 0;

  while (!feof(file)) {
    ch = fgetc(file);
    if (ch == '\n') {
      break;
    }
    count += 1;
  }

  printf("col_count: %d\n", count);
  return count;
}

int main() {
  char *file_path = "../input";

  FILE *pF = fopen(file_path, "r");
  char buffer[8192];

  if (pF == NULL) {
    printf("Unable to open file.\n");
    return 1;
  }

  int rows = 1 + count_rows(fopen(file_path, "r"));
  int columns = count_columns(fopen(file_path, "r"));

  char arr[columns][rows];
  char build_arr[columns][rows];

  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      build_arr[i][j] = '.';
    }
  }

  char *token;

  char ch;
  int current_line = 0;
  int current_column = 0;
  while (!feof(pF)) {
    ch = fgetc(pF);
    if (ch == '\n') {
      current_line += 1;
      current_column = 0;
    } else {
      arr[current_column][current_line] = ch;
      current_column += 1;
    }
  }
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      printf("%c", arr[j][i]);
    }
    printf("\n");
  }

  int count = 0;
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      // use this for part one
      /*
      if (arr[i][j] == 'X') {
        count += check_for_xmas(columns, rows, arr, i, j, build_arr);
      }
      */
      // use this for part two
      if (arr[i][j] == 'A') {
        count += check_for_two_mas(columns, rows, arr, i, j, build_arr);
      }
    }
  }

  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows - 1; j++) {
      printf("%c", build_arr[j][i]);
    }
    printf("\n");
  }

  printf("Count: %d\n", count);
  return 0;
}
