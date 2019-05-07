#include "linkstack.h"
#include "linklist.h"
#include <stdlib.h>

LinkStack *linkstack_create() { return linklist_create(); }
void linkstack_destroy(LinkStack *stack) { linklist_destroy(stack); }
void linkstack_clear(LinkStack *stack) { linklist_clear(stack); }
int linkstack_push(LinkStack *stack, void *item) {
  return linklist_insert(stack, item, 0);
}
void *linkstack_pop(LinkStack *stack) { return linklist_delete(stack, 0); }
void *linkstack_top(LinkStack *stack) { return linklist_get(stack, 0); }
int linkstack_size(LinkStack *stack) { return linklist_length(stack); }
