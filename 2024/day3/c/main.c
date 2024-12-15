#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

void add_char(char *s, char c) {
  while (*s++)
    ;
  *(s - 1) = c;
  *s = '\0';
}

int mul(char *token, int index) {
  char line[strlen(token)];
  strcpy(line, token);
  long sum = 0;

  int first_sta = -1;
  int first_end = -1;
  int second_sta = -1;
  int second_end = -1;

  for (int i = index; i < strlen(token); i++) {
    if (i[line] >= '0' && i[line] <= '9' && first_sta == -1) {
      first_sta = i;
    } else if (i[line] == ',' && first_sta != -1 && first_end == -1) {
      first_end = i;
    } else if (i[line] >= '0' && i[line] <= '9' && first_sta != -1 &&
               first_end != -1 && second_sta == -1) {
      second_sta = i;
    } else if (i[line] == ')' && first_sta != -1 && first_end != -1 &&
               second_sta != -1 && second_end == -1) {
      second_end = i;
    } else if (first_sta != -1 && line[i] >= '0' && line[i] <= '9' &&
               first_end == -1) {
      continue;
    } else if (second_sta != -1 && line[i] >= '0' && line[i] <= '9' &&
               second_end == -1) {
      continue;
    } else {
      printf(" f ");
      break;
    }
    if (first_sta != -1 && first_end != -1 && second_sta != -1 &&
        second_end != -1) {
      printf(" mul(%d-%d,%d-%d) ", first_sta, first_end, second_sta,
             second_end);
      char *first_string = malloc(1 + first_end - first_sta);
      for (int first = first_sta; first < first_end; first++) {
        add_char(first_string, first[line]);
      }

      char *second_string = malloc(1 + second_end - second_sta);
      for (int second = second_sta; second < second_end; second++) {
        add_char(second_string, second[line]);
      }

      printf(" mul(%s,%s) ", first_string, second_string);
      int first_number = atoi(first_string);
      int second_number = atoi(second_string);

      sum += first_number * second_number;

      break;
    }
  }

  return sum;
}

long process2(char *line) {
  char token_arr[strlen(line)];
  strcpy(token_arr, line);

  printf("[[%s]]: ", token_arr);
  long sum = 0;
  int open_braces = -1;
  for (int i = 3; i < strlen(line); i++) {
    if (token_arr[i - 3] == 'm' && token_arr[i - 2] == 'u' &&
        token_arr[i - 1] == 'l' && token_arr[i] == '(') {
      sum += mul(token_arr, i + 1);
      open_braces = i;
      i += 3;
    }
  }
  printf("\n");

  return sum;
}

int main() {
  FILE *pF = fopen("../input", "r");
  char buffer[1024];

  if (pF == NULL) {
    printf("Unable to open file.\n");
    return 1;
  }

  long sum = 0;
  char *token;
  while (fgets(buffer, 1024, pF) != NULL) {
    token = strtok(buffer, "\n");
    while (token != NULL) {
      sum += process2(token);

      token = strtok(NULL, "\n");
    }
  }
  printf("sum: %ld\n", sum);
  fclose(pF);
}
