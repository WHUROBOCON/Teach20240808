#include "../inc/doublelist.h"

void list_init(list *l)
{
    l->head = (list_node *)malloc(sizeof(list_node));
    l->tail = (list_node *)malloc(sizeof(list_node));
    l->head->next = l->head->pre = l->tail;
    l->tail->next = l->tail->pre = l->head;
}
void list_insert(list *l, int i, list_node *node)
{
    list_node *it = l->head;
    while (it->next != l->tail && i-- > 0) // 当前节点的下一个节点不是最后节点，说明可以继续移动
    {
        it = it->next;
    } // i>0时说明还没到要插入的位置，it到i-1节点的时候跳出循环
    node->next = it->next;
    it->next->pre = node;
    it->next = node;
    node->pre = it;
    printf("%d\n", it->next->data);
}
bool list_search(list *l, int val)
{
    list_node *it = l->head->next;
    while (it != l->tail)
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
    printf("%d\n", it->next->data);
    it->next->next->pre = it;
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
    list_init(&l);

    list_node node1;
    node1.data = 1;
    list_node node2;
    node2.data = 2;
    list_node node3;
    node3.data = 3;

    list_insert(&l, 0, &node1);
    list_insert(&l, 0, &node2);
    list_insert(&l, 1, &node3);
    // 231
    list_remove(&l, 1); // 21
    list_remove(&l, 0); // 1
    list_remove(&l, 0); //

    list_delete(&l);
}