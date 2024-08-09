#include "../inc/list.h"
#include <stddef.h>

void list_init(list *l) {
  l->head = (list_node *) malloc(sizeof(list_node));/*分配地址*/
  l->tail = (list_node *) malloc(sizeof(list_node));
  l->head->next = l->tail;/*空链表头尾节点一样，head->next是第0个节点*/
}
void list_insert(list *l, int i, list_node *node) {
  list_node *it = l->head;/*设置当前节点为头节点*/
  while (it->next != l->tail && i-- > 0) { it = it->next; }/*第i个节点为要插入的节点*/
  node->next = it->next;/*node的下一个节点指向第i个节点*/
  it->next = node;/*it的下一个节点指向node*/
  printf("%d\n", node->data);/*显示node的值*/
}
bool list_search(list *l, int val) {
  list_node *it = l->head->next;/*设置当前节点为第0个节点*/
  while (it != l->tail) {
    if (it->data == val) return true;/*找到需要搜索的值并退出循环*/
    it = it->next;/*没找到继续循环*/
  }
  return false;
}
void list_remove(list *l, int i) {
  list_node *it = l->head;
  while (it->next != l->tail && i-- > 0) { it = it->next; }/*找到第i个节点*/
  if (it->next == l->tail) return;/*第i个节点是尾节点时返回*/
  printf("%d\n", it->next->data);/*显示要删除的节点的值*/
  it->next = it->next->next;/*将第i个节点排除在外，it的下一个节点指向it的下一个节点的下一个节点*/
}
void list_delete(list *l) {/*删除链表*/
  free(l->head);
  free(l->tail);
}

int main() {
  list l;

  list_node node1;
  node1.data = 1;
  list_node node2;
  node2.data = 2;
  list_node node3;
  node3.data = 3;/*给3个节点赋值*/

  list_init(&l);/*初始化*/
  list_insert(&l, 0, &node1);
  list_insert(&l, 0, &node2);
  list_insert(&l, 0, &node3);/*三个节点插入后顺序为3，2，1*/

  list_remove(&l, 1);/*移除第1个节点2，顺序为3,1*/
  list_remove(&l, 0);/*移除第0个节点3，顺序为1*/
  list_remove(&l, 0);/*移除第0个节点1*/

  list_delete(&l);
}
