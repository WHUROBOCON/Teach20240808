#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {/*节点，存下一个节点的指针和本节点的数据*/
  struct list_node *next;
  int data;
} list_node;

typedef struct list {/*存放链表的头和尾*/
  struct list_node *head;
  struct list_node *tail;/*head和tail是没有用的节点，管理整条链*/
  int sz;/*链表大小*/
} list;

void list_init(list *l);/*链表初始化*/
void list_insert(list *l, int i, list_node *node);/*插入节点*/
bool list_search(list *l, int val);/*寻找值*/
void list_remove(list *l, int i);/*移除节点*/
void list_delete(list *l) ;