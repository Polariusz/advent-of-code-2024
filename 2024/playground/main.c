#include <stddef.h>
#include <stdio.h>

#include <string.h>

char *delete_char_at(char *string, int char_at) {
  int i, j;
  int len = strlen(string);
  for (i = j = 0; i < len; i++) {
    if (i != char_at) {
      string[j++] = string[i];
    }
  }
  string[j] = '\0';
  return string;
}

char *delete_chars(char *string, int range[2]) {
  int i, j;
  int len = strlen(string);
  for (i = j = 0; i < len; i++) {
    if (i < range[0] || i > range[1]) {
      string[j++] = string[i];
    }
  }
  string[j] = '\0';
  return string;
}

int main() {
  printf("delete_char_at:\n");
  // from for example reading a file
  char *foo = "hello";

  // » output: 5 «
  printf("strlen(foo) = %ld\n", strlen(foo));

  // strlen(foo) because we know the len
  char stack_foo[strlen(foo)];

  // yes
  memcpy(stack_foo, foo, 6);

  // ladies and gentelman, we got 'em » output: hello «
  printf("%s\n", stack_foo);

  // stack_foo[3] = '\0'; // doing this will cut the stack_foo; it will be:
  // "hel"

  // deleting the fourth character
  delete_char_at(stack_foo, 3);

  // » output: helo «
  printf("%s\n", stack_foo);

  printf("delete_chars:\n");
  char text[] = "Just MonYuriika";
  int range[2] = {8, 11};
  delete_chars(text, range);
  printf("%s\n", text);
  return 0;
}
