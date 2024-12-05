#include "linked_list.h"

void print_list(node *head) {
  node *current = head;
  while (current != NULL) {
    printf("%d->", current->value);
    current = current->next;
  }
  printf("NULL\n");
}

void println(char *message) { printf("%s\n", message); }

int main() {
  // Add few numbers
  node *new = add(0);
  new = add(1);
  new = add(4);
  new = add(6);
  new = add(8);
  new = add(9);
  new = add(10);
  new = add(12);
  new = add(14);
  new = add(15);
  new = add(16);
  new = add(18);
  new = add(20);
  println("After adding:");
  print_list(new);
  println("");

  // Make the list nice by filling the missing numbers
  new = insert(2, 11);
  new = insert(3, 11);
  new = insert(5, 10);
  new = insert(7, 9);
  new = insert(11, 6);
  new = insert(13, 5);
  new = insert(17, 2);
  new = insert(19, 1);

  println("After inserting:");
  print_list(new);
  println("");

  // Pop numbers 0, 11, 17, 19 and 20
  println("Popping:");
  printf("Index %d: %d\n", 0, pop(20));
  printf("Index %d: %d\n", 9, pop(9));
  printf("Index %d: %d\n", 3, pop(3));
  printf("Index %d: %d\n", 0, pop(0));
  println("");
  println("After popping:");
  print_list(new);
  return 0;
}
