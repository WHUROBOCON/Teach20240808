#pragma once

#include<stdbool.h>

//用结构体定义节点
typedef struct list_node{
    struct list_node *next;//存储指向下一个节点的指针
    int data;//存储自己的数据
}list_node;

//定义链表
typedef struct list
{
    struct list_node *head;//定义链表头部
    struct list_node *tail;//定义尾部指针
    int sz;//链表的元素个数
}list;

void list_init(list *l);//链表初始化
void list_insert(list *l,int i,list_node *node);//插入元素,位置与数值
bool list_search(list *l,int val);//寻找某个值
void list_remove(list *l,int i);//移除哪一个节点
