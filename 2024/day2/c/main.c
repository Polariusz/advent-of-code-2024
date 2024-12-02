#include <alloca.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int part_two() {
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
  }
  printf("Amount of safes: %d\n", count_safe);
  fclose(pF);
  return 0;
}

struct El {
  struct El *next;
  int val;
};

void add(struct El master, struct El next) { master.next = &next; }

int main() {
  struct El master;
  master.val = 0;
  master.next = NULL;
  if (master.next == NULL) {
    struct El new;
    new.val = 1;
    new.next = NULL;
    add(master, new);
  }
  printf("%d\n", master.val);
  printf("%d\n", (*master.next).val);
  return 0;
}
