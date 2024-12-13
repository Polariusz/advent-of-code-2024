#include <alloca.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *delete_int_at(int int_array[], int len, int char_at) {
  int i, j;
  for (i = j = 0; i < len; i++) {
    if (i != char_at) {
      int_array[j++] = int_array[i];
    }
  }
  int_array[j] = '\0';
  return int_array;
}

int part_one() {
  FILE *pF = fopen("../input", "r");
  char buffer[255];
  if (pF == NULL) {
    printf("Unable to open file.\n");
    return 1;
  }

  char *token;
  int count_safe = 0;
  while (fgets(buffer, 255, pF) != NULL) {
    token = strtok(buffer, " \n");
    int arr[16];
    int cnt = 0;
    char is_safe = 1;

    while (token != NULL) {
      if (cnt > 15) {
        return 1;
      }
      arr[cnt] = atoi(token);
      cnt += 1;
      token = strtok(NULL, " \n");
    }

    char asc_desc = 0;
    if (arr[0] > arr[1]) {
      asc_desc = 1;
    } else if (arr[1] > arr[0]) {
      asc_desc = 2;
    }
    for (int i = 1; i < cnt && asc_desc != 0; i++) {
      if (arr[i] == arr[i - 1]) {
        is_safe = 0;
        break;
      }
      if (asc_desc == 1) {
        if (!(arr[i - 1] > arr[i])) {
          is_safe = 0;
          break;
        }
        if (arr[i - 1] - arr[i] > 3) {
          is_safe = 0;
          break;
        }
      } else if (asc_desc == 2) {
        if (!(arr[i] > arr[i - 1])) {
          is_safe = 0;
          break;
        }
        if (arr[i] - arr[i - 1] > 3) {
          is_safe = 0;
          break;
        }
      }
    }
    if (asc_desc == 0) {
      is_safe = 0;
    }
    if (is_safe == 1) {
      count_safe += 1;
    }
  }
  printf("Amount of safes: %d\n", count_safe);
  fclose(pF);
  return 0;
}

int len_without_spaces(char *token) {
  int true_len = 1;
  for (; *token; token++) {
    if (*token == ' ') {
      true_len += 1;
    }
  }
  return true_len;
}

char process(char *token) {
  int arr[len_without_spaces(token)];

  char *foo = strtok(token, " ");

  int cnt = 0;
  while (foo != NULL) {
    arr[cnt] = atoi(foo);

    foo = strtok(NULL, " ");
    cnt += 1;
  }

  char is_ascending = 0;

  char tolerance = 0;
  for (int i = 1; i < sizeof(arr) / sizeof(int); i++) {
    // here we need to check the thing
    if (arr[i - 1] == arr[i]) {
      printf(" equ ");
      if (tolerance != 0) {
        return 1;
      }
      tolerance += 1;
    } else if (arr[i - 1] < arr[i]) { // asc
      printf(" asc ");
      if (is_ascending == 0) {
        is_ascending = 1;
      } else if (is_ascending == 2) {
        if (tolerance != 0) {
          return 1;
        }
        tolerance += 1;
      }
    } else { // desc
      printf(" des ");
      if (is_ascending == 0) {
        is_ascending = 2;
      } else if (is_ascending == 1) {
        if (tolerance != 0) {
          return 1;
        }
        tolerance += 1;
      }
    }

    if (is_ascending == 1) {
      if (arr[i] - arr[i - 1] > 3) {
        if (arr[i + 1] - arr[i - 1] > 3) {
          return 1;
        }
      }
    } else if (is_ascending == 2) {
      if (arr[i - 1] - arr[i] > 3) {
        if (arr[i - 1] - arr[i + 1] > 3) {
          return 1;
        }
      }
    }
  }

  printf(" tol: %d ", tolerance);
  return 0;
}

int part_two() {
  FILE *pF = fopen("../input", "r");
  if (pF == NULL) {
    printf("Unable to open file.\n");
    return 1;
  }
  char buffer[255];

  char *token;
  int count_safe = 0;
  while (fgets(buffer, 255, pF) != NULL) {
    token = strtok(buffer, "\n");
    printf("%s ", token);
    if (process(token) == 0) {
      printf(" safe\n");
      count_safe += 1;
    } else {
      printf(" unsafe\n");
    }
    token = strtok(NULL, "\n");
  }
  printf("Amount of safes: %d\n", count_safe);
  fclose(pF);
  return 0;
}

int main() {
  part_two();
  return 0;
}
