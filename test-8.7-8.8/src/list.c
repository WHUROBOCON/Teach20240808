#include "../inc/list.h"
#include <stddef.h>

void list_init(list *l)
{
    l->head = (list_node *)malloc(sizeof(list_node)); // 为 list_node 结构体分配一块内存，并将这块内存的地址（经过类型转换后）赋值给链表 l 的头指针 head。
    l->tail = (list_node *)malloc(sizeof(list_node));
    l->head->next = l->tail; // l->head->next指向的是tail，说明已经到列表的尾部了。
}
void list_insert(list *l, int i, list_node *node)
{ // i循环，到0的时候就要插入数据和指针
    list_node *it = l->head;
    while (it->next != l->tail && i-- > 0) // 当前节点的下一个节点不是最后节点，说明可以继续移动
    {
        it = it->next;
    } // i>0时说明还没到要插入的位置，it到i-1节点的时候跳出循环

    node->next = it->next;      // 将插入节点的下一个节点指向原i节点
    it->next = node;            // 将i-1节点指向node
    printf("%d\n", node->data); // 输出加入的数据
}
bool list_search(list *l, int val)
{
    list_node *it = l->head->next;
    while (it->next != l->tail)
    {
        if (it->data == val)
            return true;
        it = it->next;
    }
    return false;
}
void list_remove(list *l, int i)
{
    list_node *it = l->head;
    while (it->next != l->tail && i-- > 0) // 当前节点的下一个节点不是最后节点，说明可以继续移动
    {
        it = it->next;
    } // i>0时说明还没到要插入的位置，it到i-1节点的时候跳出循环
    if (it->next == l->tail)
        return;
    printf("%d\n", it->next->data); // 输出被删的数据
    it->next = it->next->next;
}
void list_delete(list *l)
{
    free(l->head);
    free(l->tail);
}
int main()
{
    list l;
    list_node node1;
    node1.data = 1;
    list_node node2;
    node2.data = 2;
    list_node node3;
    node3.data = 3;

    list_init(&l);
    list_insert(&l, 0, &node1);
    list_insert(&l, 0, &node2);
    list_insert(&l, 0, &node3);

    list_remove(&l, 1);
    list_remove(&l, 0);
    list_remove(&l, 0);

    list_delete(&l);
}