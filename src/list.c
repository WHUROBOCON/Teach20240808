#include "../inc/list.h"
#include <stddef.h>

void list_init(list *l) {
  l->head = (list_node *) malloc(sizeof(list_node));
  l->tail = (list_node *) malloc(sizeof(list_node));
  l->head->next = l->tail;
}
void list_insert(list *l, int i, list_node *node) {
  list_node *it = l->head;
  while (it->next != l->tail && i-- > 0) { it = it->next; }
  node->next = it->next;
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
  while (it->next != l->tail && i-- > 0) { it = it->next; }
  if (it->next == l->tail) return;
  printf("%d\n", it->next->data);
  it->next = it->next->next;
}
void list_delete(list *l) {
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
  node3.data = 3;

  list_init(&l);
  list_insert(&l, 0, &node1);
  list_insert(&l, 0, &node2);
  list_insert(&l, 0, &node3);

  // 3 2 1
  list_remove(&l, 1);// 2 : 3 1
  list_remove(&l, 0);// 3 : 1
  list_remove(&l, 0);// 1

  list_delete(&l);
}
