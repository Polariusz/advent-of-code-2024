#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(int arr[], int length) {
  char swapped = 1;
  while (swapped == 1) {
    swapped = 0;
    for (int i = 1; i < length; i++) {
      if (arr[i] < arr[i - 1]) {
        swapped = 1;
        int temp = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = temp;
      }
    }
  }
}

int main() {
  FILE *pF = fopen("../input", "r");
  char buffer[255];

  if (pF == NULL) {
    printf("Unable to open file.\n");
    return 1;
  }

  int cnt = 0;
  char *token;
  int first[1000];
  int second[1000];
  while (fgets(buffer, 255, pF) != NULL) {
    char which = 0;
    token = strtok(buffer, " \n");
    while (token != NULL) {
      if (which == 0) {
        first[cnt] = atoi(token);
      } else {
        second[cnt] = atoi(token);
      }
      token = strtok(NULL, " \n");
      which = 1;
    }
    cnt += 1;
  }
  fclose(pF);

  bubble_sort(first, cnt);
  bubble_sort(second, cnt);

  int sum = 0;
  for (int i = 0; i < cnt; i++) {
    if (first[i] > second[i]) {
      sum += first[i] - second[i];
    } else {
      sum += second[i] - first[i];
    }
  }
  printf("%d\n", sum); // Part 1

  int sum_2 = 0;
  for (int first_index = 0; first_index < cnt; first_index++) {
    int count_same_numbers = 0;
    for (int second_index = 0; second_index < cnt; second_index++) {
      if (first[first_index] == second_index[second]) {
        count_same_numbers++;
      } else if (second_index[second] > first[first_index]) {
        break;
      }
    }
    sum_2 += first_index[first] * count_same_numbers;
  }
  printf("%d\n", sum_2); // Part 2

  return 0;
}
