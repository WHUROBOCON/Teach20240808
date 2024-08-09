#include "../inc/doublelist.h"

void list_init(list *l) {                         /*初始化*/
  l->head = (list_node *) malloc(sizeof(list_node));
  l->tail = (list_node *) malloc(sizeof(list_node));
  l->head->next = l->head->pre = l->tail;
  l->tail->next = l->tail->pre = l->head;/*空链表*/
}
void list_insert(list *l, int i, list_node *node) {
  list_node *it = l->head;
  while (it->next != l->tail && i-- > 0) { it = it->next; }// it:i-1 it->next i
  node->next = it->next;/*node的下一个节点指向it的下一个节点*/
  node->pre = it;/*node的上一个节点指向it*/
  it->next->pre = node;/*it的下一个节点的上一个节点指向node*/
  it->next = node;/*it的下一个节点指向node*/
  printf("%d\n", node->data);
}
bool list_search(list *l, int val) {
  list_node *it = l->head->next;
  while (it != l->tail) {
    if (it->data == val) return true;
    it = it->next;
  }
  return false;
}
void list_remove(list *l, int i) {
  list_node *it = l->head;
  while (it->next != l->tail && i-- > 0) { it = it->next; }// it:i-1 it->next i
  if (it->next == l->tail) return;
  list_node *delete_node = it->next;/*要删除的节点指向第i个节点*/
  delete_node->pre->next = delete_node->next;/*删除节点的上一个节点的下一个节点指向删除节点的下一个节点*/
  delete_node->next->pre = delete_node->pre;/*删除节点的下一个节点的上一个节点指向删除节点的*/
  delete_node->next = NULL;
  delete_node->pre = NULL;/*删除节点不指向任何节点，将其移除*/
  printf("%d\n", delete_node->data);
}
void list_delete(list *l) {
  free(l->head);
  free(l->tail);
}

int main() {
  list l;
  list_init(&l);/*初始化*/

  list_node node1;
  node1.data = 1;
  list_node node2;
  node2.data = 2;
  list_node node3;
  node3.data = 3;

  list_insert(&l, 0, &node1);
  list_insert(&l, 0, &node2);
  list_insert(&l, 1, &node3);/*插入第0,0,1个节点，链表顺序应为231*/

  list_remove(&l, 2);/*移除1，剩余23*/
  list_remove(&l, 0);/*移除2，剩余3*/
  list_remove(&l, 0);/*移除3*/

  list_delete(&l);/*删除链表*/
}
