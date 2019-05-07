#ifndef linkqueue_H
#define linkqueue_H

typedef void LinkQueue;

LinkQueue *linkqueue_create();
void linkqueue_destroy(LinkQueue *queue);
void linkqueue_clear(LinkQueue *queue);
int linkqueue_append(LinkQueue *queue, void* item);
void *linkqueue_retrieve(LinkQueue *queue);
void *linkqueue_header(LinkQueue *queue);
int linkqueue_length(LinkQueue *queue);


#endif // linkqueue_H
