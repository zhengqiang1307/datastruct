#ifndef SEQQUEUE_H
#define SEQQUEUE_H

typedef void SeqQueue;

SeqQueue *seqqueue_create(int capacity);
void seqqueue_destroy(SeqQueue *queue);
void seqqueue_clear(SeqQueue *queue);
int seqqueue_append(SeqQueue *queue, void* item);
void *seqqueue_retrieve(SeqQueue *queue);
void *seqqueue_header(SeqQueue *queue);
int seqqueue_length(SeqQueue *queue);
int seqqueue_capacity(SeqQueue *queue);

#endif // SEQQUEUE_H
