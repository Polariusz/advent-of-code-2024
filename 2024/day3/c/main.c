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
      break;
    }
    if (first_sta != -1 && first_end != -1 && second_sta != -1 &&
        second_end != -1) {
      // printf(" mul(%d-%d,%d-%d) ", first_sta, first_end, second_sta,
      // second_end);
      char *first_string = malloc(1 + first_end - first_sta);
      for (int first = first_sta; first < first_end; first++) {
        add_char(first_string, first[line]);
      }

      char *second_string = malloc(1 + second_end - second_sta);
      for (int second = second_sta; second < second_end; second++) {
        add_char(second_string, second[line]);
      }

      // printf(" mul(%s,%s) ", first_string, second_string);
      int first_number = atoi(first_string);
      int second_number = atoi(second_string);

      sum += first_number * second_number;

      break;
    }
  }

  return sum;
}

int main() {
  FILE *pF = fopen("../input", "r");
  char buffer[8192];

  if (pF == NULL) {
    printf("Unable to open file.\n");
    return 1;
  }

  long sum = 0;
  char *token;
  char do_it = 1;

  while (fgets(buffer, 8192, pF) != NULL) {
    token = strtok(buffer, "\n");
    while (token != NULL) {

      int open_braces = -1;

      for (int i = 3; i < strlen(token); i++) {
        if (token[i - 3] == 'd' && token[i - 2] == 'o' && token[i - 1] == '(' &&
            token[i] == ')') {
          do_it = 1;
        }

        if (i > 6 && token[i - 6] == 'd' && token[i - 5] == 'o' &&
            token[i - 4] == 'n' && token[i - 3] == '\'' &&
            token[i - 2] == 't' && token[i - 1] == '(' && token[i] == ')') {
          do_it = 0;
        }

        if (do_it == 1 && token[i - 3] == 'm' && token[i - 2] == 'u' &&
            token[i - 1] == 'l' && token[i] == '(') {
          sum += mul(token, i + 1);
          open_braces = i;
          i += 3;
        }
      }

      token = strtok(NULL, "\n");
    }
  }
  printf("sum: %ld\n", sum);
  fclose(pF);
}
