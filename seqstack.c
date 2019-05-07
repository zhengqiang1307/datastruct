#include "seqstack.h"
#include "seqlist.h"

SeqStack* seqstack_create(int capacity)
{
    return seqlist_create(capacity);
}
void seqstack_destroy(SeqStack* stack)
{
    seqlist_destroy(stack);
}
void seqstack_clear(SeqStack* stack)
{
    seqlist_clear(stack);
}
int seqstack_push(SeqStack* stack, SeqStackNode* item)
{
    return seqlist_insert(stack, item, seqlist_length(stack));
}
SeqStackNode* seqstack_pop(SeqStack* stack)
{
    return seqlist_delete(stack, seqlist_length(stack)-1);
}
SeqStackNode* seqstack_top(SeqStack* stack)
{
    return seqlist_get(stack,seqlist_length(stack)-1);
}
int seqstack_size(SeqStack* stack)
{
    return seqlist_length(stack);
}
int seqstack_capacity(SeqStack* stack)
{
    return seqlist_capacity(stack);
}
