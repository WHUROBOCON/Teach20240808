#include "../inc/list.h"//引入头文件



void list_init(list *l){//定义初始化链表
    l->head=malloc(sizeof(list_node));//分配头节点空间
    l->tail=malloc(sizeof(list_node));
    l->size=0;
    l->head->next=l->tail;
};
void list_delete(list *l){//定义删除链表
    list_node *it=l->head->next;
    l->head=NULL;
    l->tail=NULL;
    l->size=0;
    while(it!=NULL){
        list_node *tmp=it;
        it=it->next;
        free(tmp);}
   
};
void list_add(list *l, int i,int data){//定义添加链表节点
    list_node *it=malloc(sizeof(list_node));
    list_node *find=malloc(sizeof(list_node));
    
    find=l->head;
    for(int j=0;j<i-1;j++)find=find->next;
    
    if(find==l->tail) return;
    it->next=find->next;
    it->data=data;
    printf("%d\n",it->data);
    find->next=it;
    l->size++;
};
void list_remove(list *l, int i){//定义删除链表节点
    int data;
    list_node *find=malloc(sizeof(list_node));
    find=l->head;
    for(int j=0;j<i-1;j++) find=find->next;
    
    if(find->next==l->tail) return;
    
    data=find->next->data;
    find->next=find->next->next;
    
    printf("%d\n",data);
    l->size--;
};
bool list_search(list *l, int data){//定义查找链表节点
    int i=1;
    list_node *find=l->head->next;
    find=l->head;
    for(int j=0;j<i-1;j++)find=find->next;
    
    if(find==l->tail) return false;
    if(find->data==data) printf("Found at %d\n",i);
    
};

//测试代码
int main(){
    list l;
    list_init(&l);
    list_add(&l,1,1);
    list_add(&l,2,2);
    list_add(&l,3,3);


    list_remove(&l,2);
    list_remove(&l,1);
    list_remove(&l,1);

    list_delete(&l);
    return 0;
}