#include "inc\queue.h"

void queue_init(queue_t *queue) { queue->r = queue->w = 0; }/*初始化队列*/
bool queue_enqueue(queue_t *queue, float value) {
  if (queue_is_full(queue)) return false;/*满了无法添加数据*/
  queue->data[queue->w] = value;/*向队尾添加数据*/
  ++queue->w;/*队尾+1*/
  queue->w %= QUEUE_MAX_SIZE;/*队尾对队列长度的余数，防止溢出*/
  return true;
}
bool queue_dequeue(queue_t *queue, float *value) {
  if (queue_is_empty(queue)) return false;/*空的无法移除数据*/
  *value = queue->data[queue->r];/*队头数据返回给value*/
  ++queue->r;/*移除队头元素*/
  queue->r %= QUEUE_MAX_SIZE;
  return true;
}
bool queue_front(queue_t *queue, float *value) {
  if (queue_is_empty(queue)) return false;
  *value = queue->data[queue->r];
  return true;/*不移除队头元素*/
}
bool queue_is_empty(queue_t *queue) { return queue->r == queue->w; }/*判断队列为空*/
bool queue_is_full(queue_t *queue) {
  int sz = queue->w - queue->r;/*队尾减队头*/
  sz = sz >= 0 ? sz : sz + QUEUE_MAX_SIZE;/*当sz大于0时说明没有溢出*/
  return sz == QUEUE_MAX_SIZE;/*若sz等于队列长度返回true，否则返回false*/
}

int main() {
  queue_t queue;
  queue_init(&queue);/*初始化队列*/

  for (int i = 0; i < 10; ++i) { queue_enqueue(&queue, (float) i); }/*循环给队列添加元素*/
  for (int i = 0; i < 10; ++i) {
    float temp;
    queue_dequeue(&queue, &temp);/*移除队头元素并返回给temp*/
    printf("%f\n", temp);
  }
}