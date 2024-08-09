#include "../inc/list.h"

//链表初始化
void list_init(list *l);{
    l->head = (list_node *) malloc(sizeof(list_node));
    l->tail = (list_node *) malloc(sizeof(list_node));
    l->head->next = l->tail;
    }

//插入元素,位置与数值
void list_insert(list *l,int i,list_node *node);{
list_node *it = l->head;
while(it->next != l->tail && i-->0){
    it = it->next;
}
node->next == it->next;
it->next = node;
printf("%d\n",node->data);
}

//寻找某个值
bool list_search(list *l,int val);{
list_node *it = l->head->next;
while(it != l->tail){
    if(it->data == val)return true;
    it = it->next;
}
return false;
}

//移除哪一个节点
void list_remove(list *l,int i);{
list_node *it = l->head;
while(it->next != l->tail && i-->0){
    it = it->next;
}
if(it->next == l->tail) return;
printf("%d\n",it->next->data);
it->next = it->next->next;
}

//链表的释放
void list_delete(list *l){
    free(l->head);
    free(l->tail);
}
//测试函数
int main(){
    list l;
    list_node node1;
    node1.data = 1;
    list_node node2;
    node1.data = 2;
    list_node node3;
    node1.data = 3;

    list_init(&l);
    list_insert(&l,0,&node1);
    list_insert(&l,0,&node2);
    list_insert(&l,0,&node3);

    list_remove(&l,1);
    list_remove(&l,0);
    list_remove(&l,0);

    list_delete(&l);
}