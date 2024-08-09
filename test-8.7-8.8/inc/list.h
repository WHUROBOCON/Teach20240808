#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct list_node
{
    int data;
    struct list_node *next; // struct关键字不能删除。如果你删除了它，编译器会在结构体定义内部找不到list_node这个类型名，因为它还没有被定义为一个别名。
} list_node;

typedef struct list
{
    struct list_node *head; // 通过 head->data 来访问链表第一个节点的数据。
    struct list_node *tail;
    int sz;
} list;

void list_init(list *l); // 初始化链表.list *l是一个指向 list 结构体实例的指针
void list_insert(list *l, int i, list_node *node);
bool list_search(list *l, int val);
void list_remove(list *l, int i);
void list_delete(list *l);