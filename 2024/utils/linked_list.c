/// ty low level for giving me guidance.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  void *next;
  int value;
} node;

node *head = NULL;

node *add(int value) {
  node *new = NULL;
  if (head == NULL) {
    new = malloc(sizeof(node));
    if (new == NULL) {
      return NULL;
    }
    new->value = value;
    head = new;
    new->next = NULL;
  } else {
    new = malloc(sizeof(node));
    if (new == NULL) {
      return NULL;
    }
    new->value = value;
    new->next = head;
    head = new;
  }
  return new;
}

int pop(int pos) {
  int value;
  if (pos == 0) {
    node *new = malloc(sizeof(node));
    new = head;
    value = new->value;
    new = head->next;
    head = new;
    return value;
  } else {
    node *p_head_prev = malloc(sizeof(node));
    if (head != NULL) {
      p_head_prev = head;
    }
    node *p_head_next = malloc(sizeof(node));
    if (head->next != NULL) {
      p_head_next = head->next;
    }
    if (p_head_next->next == NULL) {
      head->next = NULL;
      return value;
    }

    int cnt = 1;
    while (cnt < pos) {
      p_head_prev = p_head_prev->next;
      p_head_next = p_head_next->next;
      cnt++;
    }
    value = p_head_next->value;
    p_head_prev->next = p_head_next->next;
  }

  return value;
}

node *insert(int value, int pos) {
  node *new = NULL;

  if (pos == 0) {
    new = malloc(sizeof(NULL));
    new->value = value;
    new->next = head;
    head = new;
    return new;
  }

  node *p_head_next = head;
  node *p_head_prev = head;

  int cnt = 0;
  while (cnt < pos && p_head_next->next != NULL) {
    p_head_next = p_head_next->next;
    cnt++;
  }
  cnt = 0;
  while (cnt < pos - 1) {
    p_head_prev = p_head_prev->next;
    cnt++;
  }
  if (p_head_next == p_head_prev) {
    new = malloc(sizeof(node));
    new->value = value;
    p_head_next->next = new;
  } else {
    new = malloc(sizeof(node));
    new->value = value;
    new->next = p_head_next;
    p_head_prev->next = new;
  }
  return new;
}

void print_list() {
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
  print_list();
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
  print_list();
  println("");
  // Pop numbers 0, 11, 17, 19 and 20

  println("Popping:");
  printf("Index %d: %d\n", 0, pop(20));
  printf("Index %d: %d\n", 9, pop(9));
  printf("Index %d: %d\n", 3, pop(3));
  printf("Index %d: %d\n", 0, pop(0));
  println("");
  println("After popping:");
  print_list();
  return 0;
}
