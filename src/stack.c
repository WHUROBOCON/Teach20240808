
#include "../inc/stack.h"

void stack_init(stack_t *stack, stack_size_t sz) {
  stack->size = sz;/*栈的大小*/
  stack->base = malloc(sz) + sz;/*栈底地址分配内存*/
  stack->top = stack->base;/*栈顶地址等于栈底地址*/
  
}

bool stack_is_empty(stack_t *stack) { return stack->top == stack->base; }/*top地址和base地址一样时即为栈空，返回true*/

bool stack_is_full(stack_t *stack) { return (stack->base - stack->top) == stack->size; }/*base和top地址的差为size大小时判断栈满，返回true (栈分配时是从高地址向低地址分配，栈底地址高于栈顶地址)*/

bool stack_push(stack_t *stack, void *value, stack_size_t sz) {
  if ((stack->base - (stack->top - sz) > stack->size)) return false;/*判断栈是否占满*/
  stack->top -= sz;
  memcpy(stack->top, value, sz);/*由value指向地址为起始地址的连续sz个字节的数据复制到以top指向地址为起始地址的空间内*/
  return true;
}

bool stack_pop(stack_t *stack, void *value, stack_size_t sz) {
  if (stack->top + sz > stack->base) return false;/*判断栈是否为空*/
  memcpy(value, stack->top, sz);/*由top指向地址为起始地址的连续sz个字节的数据复制到以value指向地址为起始地址的空间内*/
  stack->top += sz;
  return true;
}

bool stack_top(stack_t *stack, void *value, stack_size_t sz) {
  if (stack->top + sz > stack->base) return false;
  memcpy(value, stack->top, sz);/*将top为起始地址的sz个数据出到value中，但在栈中不删除这些数据*/
  return true;
}

void stack_delete(stack_t *stack) { free(stack->base - stack->size); }/*释放栈的内存*/

int main(int argc, char const *argv[]) {

  stack_t stack;
  stack_init(&stack, 10);

  float a = 10.f;
  double d = 30.f;
  int b = 20;

  stack_push(&stack, &a, sizeof(float)); // 4个字节 : 剩余6个字节大小的空
  stack_push(&stack, &d, sizeof(double));// 8个字节 : false，压入数据字节大于栈空余
  stack_push(&stack, &b, sizeof(int));   // 4个字节 : 剩余2个字节大小的空

  float a_r;
  double d_r;
  int b_r;

  stack_pop(&stack, &b_r, sizeof(int));   // 4个字节 : 压出4个
  stack_pop(&stack, &d_r, sizeof(double));// 8个字节 : false
  stack_top(&stack, &a_r, sizeof(float)); // 4个字节 : 压出4个

  printf("%f, %d, %lf\n", a_r, b_r, d_r);

  stack_pop(&stack, &a_r, sizeof(float));// 4个字节 : 4

  printf("%f, %d, %lf\n", a_r, b_r, d_r);

  stack_delete(&stack);/*清空栈内存*/
  return 0;
}
