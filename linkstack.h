#ifndef LINKSTACK_H
#define LINKSTACK_H


typedef void LinkStack;
typedef void LinkStackNode;

LinkStack* linkstack_create();
void linkstack_destroy(LinkStack* stack);
void linkstack_clear(LinkStack* stack);
int linkstack_push(LinkStack* stack, void* item);
void* linkstack_pop(LinkStack* stack);
void* linkstack_top(LinkStack* stack);
int linkstack_size(LinkStack* stack);



#endif // LINKSTACK_H
