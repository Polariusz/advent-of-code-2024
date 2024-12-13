#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *pF = fopen("../input2", "r");
  char buffer[1024];

  if (pF == NULL) {
    printf("Unable to open file.\n");
    return 1;
  }

  regex_t regeex;
  int value = regcomp(&regeex, "[0-9],[0-9]", 0);

  int sum = 0;
  char *token;
  while (fgets(buffer, 1024, pF) != NULL) {
    token = strtok(buffer, "mul\n");
    while (token != NULL) {
      // printf("Bef regex: %s\n", token);
      if (regexec(&regeex, token, 0, NULL, 0) == 0) {
        printf("Aft regex: %s\n", token);
      }
      token = strtok(NULL, "mul\n");
    }
  }
  fclose(pF);
}
