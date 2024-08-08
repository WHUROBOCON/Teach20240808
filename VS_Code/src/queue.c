#include"inc/queue.h"

void queue_init(queue_t *queue){
    queue->r = queue->w = 0;//初始化队列的头尾指针
}

bool queue_enqueue(queue_t *queue,float value){
    if(queue_is_full(queue)){
        return false;
    }//队列满时，返回false，不进行入队操作
    queue->data[queue->w] = value;//将value赋值给队列的尾指针
    ++queue->w;//尾指针向后移动一个单位
    // queue->w %= QUEUE_MAX_SIZE;
    queue->w %= (QUEUE_MAX_SIZE+1);//取余，防止越界
    return true;
}

bool queue_dequeue(queue_t *queue,float *value){
    if(queue_is_empty(queue)){
        return false;
    }//队列空时，返回false，不进行出队操作
    *value = queue->data[queue->r];//将队列的头指针的值赋给value
    ++queue->r;//头指针向后移动一个单位
    // queue->r %= QUEUE_MAX_SIZE;
    queue->r %= (QUEUE_MAX_SIZE+1);//取余，防止越界
    return true;
}

bool queue_front(queue_t *queue,float *value){
    if(queue_is_empty(queue)){
        return false;
    }//队列空时，返回false，不进行取队头操作
    *value = queue->data[queue->r];//将队列的头指针的值赋给value
    return true;
}

bool queue_is_empty(queue_t *queue){
    return queue->r == queue->w;//头指针等于尾指针时，队列为空
}

bool queue_is_full(queue_t *queue){
    // int sz=queue->w-queue->r;
    // sz=sz>=0?sz:sz + QUEUE_MAX_SIZE;
    // return sz == QUEUE_MAX_SIZE;
    return (queue->w + 1) % (QUEUE_MAX_SIZE+1) == queue->r;//尾指针加1取余等于头指针时，队列满
}

int main(){
    queue_t queue;
    queue_init(&queue);
    for(int i =0;i< QUEUE_MAX_SIZE;i++){
        queue_enqueue(&queue,(float)i);
    }
    for(int i =0;i< QUEUE_MAX_SIZE;i++){
        float value;
        queue_dequeue(&queue,&value);
        printf("%f\n",value);
    }

    return 0;
}