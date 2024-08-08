#include "..\inc\queue.h"
#include<stdio.h>

void queue_inti(queue_t *queue){
    queue->r=queue->w=0; //一开始队列为空，读入位置与读出位置相同
}; //初始化对列
bool queue_enqueue(queue_t *queue,float value){
    if (queue_is_full(queue)) return false; //判断queue是否满了，满了就返回false
    queue->data[queue->w % QUEUE_MAX_SIZE] = value; //取余循环，防止指针值太大
    ++queue->w;
    return true;
}; //写入元素
bool queue_dequeue(queue_t *queue,float *value){
    if (queue_is_empty(queue)) return false; //判断queue是否空了，空了就没东西取
    *value=queue->data[queue->r % QUEUE_MAX_SIZE]; //取余循环，防止指针值太大
    ++queue->r;
    return true;
}; //读出元素
bool queue_front(queue_t *queue,float *value){
    if(queue_is_empty(queue)) return false; //判断queue是否空了,空了就没front取
    *value=queue->data[queue->r]; //先读出的元素为头部元素
    return true;
}; //输出头部元素
bool queue_is_empty(queue_t *queue){
    return (queue->w == queue->r); 
}; // 判断是否空，空了就返回true
bool queue_is_full(queue_t *queue){return (queue->w - QUEUE_MAX_SIZE == queue->r);
}; // 判断是否满，满了就返回true

int main(int argc, char const *argv[])
{
    queue_t queue; //定义结构体
    queue_inti(&queue); //初始化队列
   
    for(int i=0;i<22;i++) {queue_enqueue(&queue,(float)i);}
    
    float temp2;
    queue_front(&queue,&temp2);
    printf("%f\n",temp2);
    
    for(int j=0;j<40;j++) {
        float temp=0;
        queue_dequeue(&queue,&temp);
        printf("%f\n",temp);   
    };

    return 0;
}
