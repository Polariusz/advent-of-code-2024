/// ty low level for giving me guidance.

#include "linked_list.h"

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
