#include "../inc/doublelist.h"

void list_init(list *l) {
  l->head = (list_node *) malloc(sizeof(list_node));
  l->tail = (list_node *) malloc(sizeof(list_node));
  l->head->next = l->head->pre = l->tail;
  l->tail->next = l->tail->pre = l->head;
}
void list_insert(list *l, int i, list_node *node) {
  list_node *it = l->head;
  while (it->next != l->tail && i-- > 0) { it = it->next; }// it:i-1 it->next i
  node->next = it->next;
  node->pre = it;
  it->next->pre = node;
  it->next = node;
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
  list_node *delete_node = it->next;
  delete_node->pre->next = delete_node->next;
  delete_node->next->pre = delete_node->pre;
  delete_node->next = NULL;
  delete_node->pre = NULL;
  printf("%d\n", delete_node->data);
}
void list_delete(list *l) {
  free(l->head);
  free(l->tail);
}

int main() {
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

  // 2 3 1
  list_remove(&l, 2);// 1 : 2 3
  list_remove(&l, 0);// 2 : 3
  list_remove(&l, 0);// 3

  list_delete(&l);
}
