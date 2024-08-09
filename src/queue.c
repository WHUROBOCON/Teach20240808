#include "../inc/queue.h"//引入头文件







void Queue_Init(queue_t *q){//初始化队列
    q->r = 0;
    q->w = 0;
    q->size = QUEUE_MAX_SIZE;
};
bool Queue_Empty(queue_t *q){return(q->w==q->r);};//判断队列是否为空
bool Queue_Full(queue_t *q){return(q->size==q->w - q->r);};//判断队列是否已满
bool Queue_Put(queue_t *q, double data){//入队
    if(Queue_Full(q))
    return false;
    
    q->data[(q->w++)%q->size]=data;
    return true;
};
bool Queue_Get(queue_t *q, double *data){//出队
    if(Queue_Empty(q))
    return false;

    *data=q->data[(q->r++)%q->size];

};
bool Queue_Head(queue_t *q, double *data){//获取队首元素
    if(Queue_Empty(q))
    return false;

    *data=q->data[q->r%q->size];
};
void Queue_Delete(queue_t *q){//删除队列
    free(q->data);

    q->size=0;
    q->r=0;
    q->w=0;
};


//测试代码
int main(){
    queue_t q;
    Queue_Init(&q);
    double data[QUEUE_MAX_SIZE];
    for(int i=0;i<QUEUE_MAX_SIZE;i++){
        data[i]=i;
        Queue_Put(&q, data[i]);
        printf("%d\n ",q.w);
    }
    

    
    for(int i=0;i<QUEUE_MAX_SIZE;i++){
        double d;
        Queue_Get(&q, &d);
        printf("%d\n ",q.r);
        printf("%d\n ",d);
    }
    Queue_Delete(&q);
    return 0;
}
