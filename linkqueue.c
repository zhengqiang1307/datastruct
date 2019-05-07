#include "linkqueue.h"
#include "linklist.h"

LinkQueue *linkqueue_create(int capacity) { return linklist_create(capacity); }
void linkqueue_destroy(LinkQueue *queue) {linklist_destroy(queue); }
void linkqueue_clear(LinkQueue *queue) { linklist_clear(queue); }
int linkqueue_append(LinkQueue *queue, void* item){return linklist_insert(queue, item, linklist_length(queue));}
void *linkqueue_retrieve(LinkQueue *queue) { return linklist_delete(queue, 0); }
void *linkqueue_header(LinkQueue *queue) { return linklist_get(queue, 0); }
int linkqueue_length(LinkQueue *queue) { return linklist_length(queue); }

