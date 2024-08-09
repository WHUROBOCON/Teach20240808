#include "inc/queue.h"

void queue_init(queue_t *queue) { queue->r = queue->w = 0; }
bool queue_enqueue(queue_t *queue, float value) {
  // if (queue_is_full(queue)) return false;
  // queue->data[queue->w % QUEUE_MAX_SIZE] = value;
  // ++queue->w;
  // return true;
  ///
  if (queue_is_full(queue)) return false;
  queue->data[queue->w] = value;
  ++queue->w;
  queue->w %= QUEUE_MAX_SIZE;
  return true;
}
bool queue_dequeue(queue_t *queue, float *value) {
  // if (queue_is_empty(queue)) return false;
  // *value = queue->data[queue->r % QUEUE_MAX_SIZE];
  // ++queue->r;
  // return true;
  if (queue_is_empty(queue)) return false;
  *value = queue->data[queue->r];
  ++queue->r;
  queue->r %= QUEUE_MAX_SIZE;
  return true;
}
bool queue_front(queue_t *queue, float *value) {
  if (queue_is_empty(queue)) return false;
  *value = queue->data[queue->r];
  return true;
}
bool queue_is_empty(queue_t *queue) { return queue->r == queue->w; }
bool queue_is_full(queue_t *queue) {
  int sz = queue->w - queue->r;
  sz = sz >= 0 ? sz : sz + QUEUE_MAX_SIZE;
  return sz == QUEUE_MAX_SIZE;
}

int main() {
  queue_t queue;
  queue_init(&queue);

  for (int i = 0; i < 10; ++i) { queue_enqueue(&queue, (float) i); }
  for (int i = 0; i < 10; ++i) {
    float temp;
    queue_dequeue(&queue, &temp);
    printf("%f\n", temp);
  }
}
