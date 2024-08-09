#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node_t
{
    void *data;
    struct Node_t *next;
    struct Node_t *prev;
} Node_t;// 链表节点, data为数据域, next为指针域, 指向下一个节点, 为NULL时表示链表尾部, data为NULL时表示链表头部, 即头指针, 也可以理解为链表的头结点

typedef struct LinkedList_t
{
    Node_t *head;
    Node_t *tail;
    unsigned int size;

} LinkedList_t;// 链表结构, head为头指针, tail为尾指针, size为链表大小

void linkedlist_init(LinkedList_t *list); // 初始化链表
bool linkedlist_insert(LinkedList_t *list, void *data, void *place, bool head); // 插入元素
bool linkedlist_delete(LinkedList_t *list, void *data); // 删除元素
bool linkedlist_clear(LinkedList_t *list); // 清空链表
bool linkedlist_is_empty(LinkedList_t *list); // 判断链表是否为空
bool linkedlist_search(LinkedList_t *list, void *data,int *result); // 查找元素
void linkedlist_destroy(LinkedList_t *list); // 销毁链表
bool linkedlist_get(LinkedList_t *list, void **data, unsigned int index); // 获取指定位置的元素
