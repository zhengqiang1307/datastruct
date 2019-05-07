#include "seqqueue.h"
#include "seqlist.h"
// typedef void SeqQueue;

SeqQueue *seqqueue_create(int capacity) { return seqlist_create(capacity); }
void seqqueue_destroy(SeqQueue *queue) { seqlist_destroy(queue); }
void seqqueue_clear(SeqQueue *queue) { seqlist_clear(queue); }
int seqqueue_append(SeqQueue *queue, void *item) {
  return seqlist_insert(queue, item, seqlist_length(queue));
}
void *seqqueue_retrieve(SeqQueue *queue) { return seqlist_delete(queue, 0); }
void *seqqueue_header(SeqQueue *queue) { return seqlist_get(queue, 0); }
int seqqueue_length(SeqQueue *queue) { return seqlist_length(queue); }
int seqqueue_capacity(SeqQueue *queue) { return seqlist_capacity(queue); }
