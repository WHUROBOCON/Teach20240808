#include "inc/linkedlist.h"

// 初始化链表
void linkedlist_init(LinkedList_t *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

bool linkedlist_insert(LinkedList_t *list, void *data, void *place, bool head) // 插入元素,place是插入位置
{
    Node_t *node = (Node_t *)malloc(sizeof(Node_t)); // 为新节点分配内存
    Node_t *temp = NULL;
    if (node == NULL || data == NULL)
    {
        printf("malloc failed\n");
        return false;
    }
    if (place == NULL)
    {
        if (list->size == 0) // 链表为空
        {
            list->head = node;
            list->tail = node;
            node->data = data;
            node->next = NULL;
            list->size++;
            return true;
        }
        else if (head)
        {
            node->data = data;       // 赋值
            node->next = list->head; // 新节点的next指针指向头指针
            list->head = node;       // 头指针指向新节点
            list->size++;
            return true;
        }
        else // 链表不为空,尾插
        {

            node->data = data;       // 赋值
            node->next = NULL;       // 新节点的next指针指向NULL
            list->tail->next = node; // 将新节点插入到链表尾部
            list->tail = node;
            list->size++;
            return true;
        }
    }
    else if (place != NULL)
    {
        Node_t *temp = list->head;
        while (temp != NULL)
        {
            if (temp->data == place)
            {
                node->data = data;       // 赋值
                node->next = temp->next; // 新节点的next指针指向下一个节点
                node->prev = temp;       // 新节点的prev指针指向当前节点
                if (temp->next != NULL)
                {
                    temp->next->prev = node;
                } // 下一个节点的prev指针指向新节点
                temp->next = node; // 当前节点的next指针指向新节点
                if (temp == list->tail)
                {
                    list->tail = node;
                } // 如果插入位置是尾节点，更新尾节点指针
                list->size++;
                return true;
            }
            temp = temp->next; // 找到要插入位置的前一个节点
        }
    }
}
bool linkedlist_delete(LinkedList_t *list, void *data) // 删除元素，data为要删除的元素
{
    Node_t *node = list->head;
    Node_t *prev = NULL;
    while (node != NULL)
    {
        if (node->data == data)
        {
            if (node == list->head)
            {
                list->head = node->next;
            }
            else if (node == list->tail)
            {
                node->prev->next = NULL;
                list->tail = node->prev;

            }
            else
            {
                prev->next = node->next;
                if (node->next != NULL)
                {
                    node->next->prev = prev; // 将删除节点的前一个节点的next指针指向删除节点的下一个节点
                }
            }
            free(node);
            list->size--;
            return true;
        }
        prev = node;
        node = node->next;
    }
    return false;
}
bool linkedlist_clear(LinkedList_t *list) // 清空链表
{
    if (linkedlist_is_empty(list))
    {
        return false;
    }

    Node_t *node = list->head;
    Node_t *temp = NULL;
    while (node != NULL)
    {
        temp = node; // 保存当前节点
        node = node->next;
        free(temp); // 释放当前节点
    }
    return true;
}

bool linkedlist_is_empty(LinkedList_t *list) // 判断链表是否为空
{
    return list->size == 0;
}
bool linkedlist_search(LinkedList_t *list, void *data, int *result) // 查找元素
{
    Node_t *node = list->head;
    while (node != NULL)
    {
        if (node->data == data)
        {
            return true;
        }
        // TODO:
        node = node->next;
        *result++;
    }
    return false; 
}
void linkedlist_destroy(LinkedList_t *list) // 销毁链表
{
    bool linkedlist_clear(LinkedList_t * list);
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
bool linkedlist_get(LinkedList_t *list, void **data, unsigned int index) // 获取指定位置的元素,index是索引
{
    if (index >= list->size)
    {
        printf("Index out of range\n");
        return false;
    }
    Node_t *node = list->head;
    for (unsigned int i = 0; i < index; i++)
    {
        node = node->next;
    }
    *data = node->data; // 获取数据
    return true;
}

int main()
{
    LinkedList_t list;
    linkedlist_init(&list);
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
    printf("地址a=%p,b=%p,c=%p,d=%p,e=%p\n", &a, &b, &c, &d, &e);
    linkedlist_insert(&list, &a, NULL, false);
    linkedlist_insert(&list, &b, NULL, false);
    linkedlist_insert(&list, &c, NULL, false);
    linkedlist_insert(&list, &d, NULL, false);
    linkedlist_insert(&list, &e, &b, false);

    void *data = NULL;
    bool get_result = linkedlist_get(&list, &data, 2);
    printf("\nget result: %d ,the element is %d", get_result, *(int *)data);
    linkedlist_delete(&list, &b);
    linkedlist_clear(&list);
    linkedlist_destroy(&list);
    return 0;
}