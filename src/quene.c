#include "inc/quene.h"

void quene_init(quene_t *quene, quene_size_t size)
{
    quene_size_t sizemax = size+1;
    quene->front = malloc(size)+size;//malloc返回的是指向堆内存的指针，所以要加上size才能指向队头
    printf("front:%p\n",quene->front);//打印队头指针
    quene->rear = quene->front;
    quene->size = size;
}

bool quene_push(quene_t *quene, void *value ,quene_size_t size) // 入队
{ 
    if(quene_is_full(quene))return false;
    memcpy(quene->rear,value,size);
    //memcpy函数的功能是从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中
    quene->rear --;//队尾指针
    return true;

}
bool quene_pop(quene_t *quene, void *value, quene_size_t size) // 出队
{
    if(quene_is_empty(quene))return false;
    free(quene->front);//释放队头元素
    quene->front --;//队头指针后移
    return true;
} 
bool quene_clear(quene_t *quene)    // 清空队列
{
    if(quene_is_empty(quene))return false;
    while(quene->front != quene->rear)
    {
        free(quene->front);//释放队头元素
        quene->front --;//队头指针后移
    }
    return true;
}                           
bool quene_is_empty(quene_t *quene) // 判断队列是否为空
{
    return quene->front == quene->rear;//队空时front指向队头
}                           
bool quene_is_full(quene_t *quene)                             // 判断队列是否满
{
    int sz = quene-> front - quene->rear;//计算队列元素个数
    sz = sz > 0 ? sz : sz + quene->size;//队列元素个数
    return quene->rear == quene->size;//队满时rear指向队尾
}
void quene_destroy(quene_t *quene)                             // 销毁队列
{
    free(quene->front);
    free(quene->rear);
}

int main()
{
    quene_t quene;
    quene_size_t size = 10;
    quene_init(&quene,size);
    int a = 1;
    quene_push(&quene,&a,sizeof(a));
    printf("front:%p\n",quene.front);
    return 0;
}