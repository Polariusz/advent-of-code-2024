#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  void *next;
  int value;
} node;

node *add(int value);
node *insert(int value, int pos);
int pop(int pos);

#endif
