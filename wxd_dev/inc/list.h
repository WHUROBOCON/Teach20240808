#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> //引入头文件


typedef struct List_node{//定义链表节点
    int data;//存储节点数据
    struct List_node *next;//指向下一个节点的指针
}list_node;



typedef struct List{//定义链表结构
    list_node *head;//指向头节点的指针
    list_node *tail;//指向尾节点的指针
    int size;//记录链表中节点的个数
}list;


//函数声明
void list_init(list *l);
void list_delete(list *l);
void list_add(list *l, int i,int data);
void list_remove(list *l, int i);
bool list_search(list *l, int data);