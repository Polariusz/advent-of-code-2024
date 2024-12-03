// ty low level
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

/// NOT IMPLEMENTED YET
void pop(int pos) {
  printf("Not implemented yet");
  return;

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

int main() {
  node *new = add(0);
  new = add(1);
  new = add(2);
  new = add(3);
  new = add(4);
  new = add(5);
  new = add(6);
  new = add(7);
  new = add(8);
  new = add(9);
  insert(11, 0);
  print_list();
  return 0;
}
