
#include "inc/stack.h"

void stack_init(stack_t *stack, stack_size_t sz) {
  stack->base = (char *) malloc(sz) + sz;
  stack->top = stack->base;
  stack->size = sz;
}

bool stack_is_empty(stack_t *stack) { return stack->top == stack->base; }

bool stack_is_full(stack_t *stack) { return (stack->base - stack->top) == stack->size; }

bool stack_push(stack_t *stack, void *value, stack_size_t sz) {
  if ((stack->base - (stack->top - sz) > stack->size)) return false;
  stack->top -= sz;
  memcpy(stack->top, value, sz);
  return true;
}

bool stack_pop(stack_t *stack, void *value, stack_size_t sz) {
  if (stack->top + sz > stack->base) return false;
  memcpy(value, stack->top, sz);
  stack->top += sz;
  return true;
}

bool stack_top(stack_t *stack, void *value, stack_size_t sz) {
  if (stack->top + sz > stack->base) return false;
  memcpy(value, stack->top, sz);
  return true;
}

void stack_delete(stack_t *stack) { free(stack->base - stack->size); }

int main(int argc, char const *argv[]) {

  stack_t stack;
  stack_init(&stack, 10);

  float a = 10.f;
  double d = 30.f;
  int b = 20;

  stack_push(&stack, &a, sizeof(float)); // 4 : 6
  stack_push(&stack, &d, sizeof(double));// 8 : false
  stack_push(&stack, &b, sizeof(int));   // 4 : 2

  float a_r;
  double d_r;
  int b_r;

  stack_pop(&stack, &b_r, sizeof(int));   // 4 : 4
  stack_pop(&stack, &d_r, sizeof(double));// 8 : false
  stack_top(&stack, &a_r, sizeof(float)); // 4 : 4

  printf("%f, %d, %lf\n", a_r, b_r, d_r);

  stack_pop(&stack, &a_r, sizeof(float));// 4 : 4

  printf("%f, %d, %lf\n", a_r, b_r, d_r);

  stack_delete(&stack);
  return 0;
}
