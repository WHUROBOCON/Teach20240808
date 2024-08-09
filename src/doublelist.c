#include "../inc/doublelist.h"
#define FULL 0

void DoubleList_init(dlist *list){//初始化，让头尾互指
    list->head=malloc(sizeof(dlist_node));
    list->tail=malloc(sizeof(dlist_node));
    list->head->next=list->tail;
    list->head->pre=list->tail;
    list->tail->next=list->head;
    list->tail->pre=list->head;
    list->size=0;
};

void DoubleList_destroy(dlist *list){
    dlist_node *ti;
    dlist_node *tmp;
    list->head->next=ti;
    list->head=NULL;
    list->tail=NULL;
    list->size=0;
    while(ti!=NULL){//利用中间变量tmp，将循环中删除的节点的next指针指向其前节点的next指针，然后释放该节点
        tmp=ti;
        ti=ti->next;
        free(tmp);
    }
};
void DoubleList_add(dlist *list,int i, int data){//i为0表示在头部插入，为1表示在尾部插入
    dlist_node *it=malloc(sizeof(dlist_node));
    if(i==0){
        it->pre=list->head;
        it->next=list->head->next;
        it->pre->next=it;
        it->next->pre=it;
        it->data=data;
    }
    else{
        it->next=list->tail;
        it->pre=list->tail->pre;
        it->pre->next=it;
        it->next->pre=it;
        it->data=data;
    }
    list->size++;
};
void DoubleList_remove(dlist *list, int i){//i为0表示删除头部，为1表示删除尾部
    dlist_node *data=malloc(sizeof(dlist_node));
    if(i==0){
        data=list->head->next;
        list->head->next=data->next;
        data->next->pre=list->head;
        free(data);
    }

    else{
        data=list->tail->pre;
        list->tail->pre=data->pre;
        data->pre->next=list->tail;
        free(data);
    }
    list->size--;
};
bool DoubleList_find(dlist *list, int data){//查找是否存在data
    dlist_node *find=malloc(sizeof(dlist_node));
    find=list->head->next;
    while(find!=list->tail){
        if(find->data==data){
            printf("find %d\n",data);
            return true;
        }
        find=find->next;
    }
    printf("false\n");
    return false;
};
void DoubleList_print(dlist *list){//打印双链表(头部到尾部)
    dlist_node *it=malloc(sizeof(dlist_node));
    it=list->head->next;
    while(it!=list->tail){
        printf("%d\n",it->data);
        it=it->next;
    }
};


//调试
int main(){
    dlist *list;
    DoubleList_init(list);
    DoubleList_add(list,0,10);//10
    DoubleList_add(list,0,20);//20 10
    DoubleList_add(list,1,30);//20 10 30



    DoubleList_print(list);//20 10 30

    DoubleList_remove(list,0);//10 30

    DoubleList_find(list,20);//false

    DoubleList_print(list);
    DoubleList_destroy(list);
    return 0;
}