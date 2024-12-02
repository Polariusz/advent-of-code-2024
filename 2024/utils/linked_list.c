#include <stdio.h>
#include <stdlib.h>
struct node {
  int value;
  struct node *next;
};

void push(struct node main, int value) {
  struct node new;
  new.next = malloc(sizeof(struct node));
  new.value = value;

  *main.next = new;
}

int main() {
  struct node main;
  main.value = 0;
  main.next = malloc(sizeof(struct node));

  push(main, 1);
  push(*main.next, 2);
  push(*main.next->next, 3);
  printf("%d\n", main.value);
  printf("%d\n", main.next->value);
  printf("%d\n", main.next->next->value);
  printf("%d\n", main.next->next->next->value);
  return 0;
}
