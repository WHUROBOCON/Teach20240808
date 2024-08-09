#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
  struct list_node *pre;
  struct list_node *next;
  int data;
} list_node;

typedef struct list {
  list_node *head;
  list_node *tail;
} list;

void list_init(list *l);
void list_insert(list *l, int i, list_node *node);
bool list_search(list *l, int val);
void list_remove(list *l, int i);
void list_delete(list *l);
