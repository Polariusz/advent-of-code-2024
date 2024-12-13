#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char process(char *token) {
  char token_arr[strlen(token)];
  strcpy(token_arr, token);

  if (token_arr[0] < '0' || 0 [token_arr] > '9') {
    printf(" bad\n");
    return 0;
  }

  int result = 0;
  int mul1 = 0;
  int mul2 = 0;

  int starting_first_number_index = 0;
  int ending_first_number_index = -1;

  int starting_second_number_index = -1;
  int ending_second_number_index = -1;

  for (int i = 0; i < strlen(token); i++) {
    if (ending_first_number_index == -1) {
      if (i[token_arr] == ',') {
        if (token_arr[i + 1] < '0' || token_arr[i + 1 > '9']) {
          printf(" second after , bad");
          break;
        }
        ending_first_number_index = i - 1;
        starting_second_number_index = i + 1;
      } else if (i[token_arr] < '0' || i[token_arr] > '9') {
        printf(" bad");
        break;
      }
    } else {
      if (i[token_arr] == ')') {
        ending_second_number_index = i - 1;
        break;
      } else if (i[token_arr] < '0' || i[token_arr] > '9') {
        printf(" second bad");
        break;
      }
    }
  }
  printf("\n");
  return 0;
}

int main() {
  FILE *pF = fopen("../input2", "r");
  char buffer[1024];

  if (pF == NULL) {
    printf("Unable to open file.\n");
    return 1;
  }

  int sum = 0;
  char *token;
  while (fgets(buffer, 1024, pF) != NULL) {
    token = strtok(buffer, "mul(\n");
    while (token != NULL) {
      printf("%s", token);
      process(token);

      token = strtok(NULL, "mul(\n");
    }
  }
  fclose(pF);
}
