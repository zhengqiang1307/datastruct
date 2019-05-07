#ifndef SEQSTACK_H
#define SEQSTACK_H

typedef void SeqStack;
typedef void SeqStackNode;

SeqStack* seqstack_create(int capacity);
void seqstack_destroy(SeqStack* stack);
void seqstack_clear(SeqStack* stack);
int seqstack_push(SeqStack* stack, SeqStackNode* item);
SeqStackNode* seqstack_pop(SeqStack* stack);
SeqStackNode* seqstack_top(SeqStack* stack);
int seqstack_size(SeqStack* stack);
int seqstack_capacity(SeqStack* stack);



#endif // SEQSTACK_H
