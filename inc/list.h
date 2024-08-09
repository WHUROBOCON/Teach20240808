#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
  struct list_node *next;
  int data;
} list_node;

typedef struct list {
  struct list_node *head;
  struct list_node *tail;
  int sz;
} list;

void list_init(list *l);
void list_insert(list *l, int i, list_node *node);
bool list_search(list *l, int val);
void list_remove(list *l, int i);
