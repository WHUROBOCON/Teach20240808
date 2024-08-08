#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct DoubleList_Node {//节点结构
    int data;
    struct DoubleList_Node *next;//指向下一个节点
    struct DoubleList_Node *pre;//指向前一个节点
} dlist_node;


typedef struct DoubleList{//双向链表结构
    dlist_node *head;//指向头节点
    dlist_node *tail;//指向尾节点
    int size;
}dlist;

//函数声明
void DoubleList_init(dlist *list);
void DoubleList_destroy(dlist *list);
void DoubleList_add(dlist *list,int i, int data);
void DoubleList_remove(dlist *list, int i);
bool DoubleList_find(dlist *list, int data);
void DoubleList_print(dlist *list);