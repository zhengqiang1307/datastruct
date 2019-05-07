#ifndef seqlist
#define seqlist

typedef void SeqList;
typedef void SeqListNode;

SeqList *seqlist_create(int capacity);
void seqlist_destroy(SeqList *list);
void seqlist_clear(SeqList *list);
int seqlist_length(SeqList *list);
int seqlist_capacity(SeqList *list);
int seqlist_insert(SeqList *list, SeqListNode *node, int pos);
SeqListNode *seqlist_get(SeqList *list, int pos);
SeqListNode *seqlist_delete(SeqList *list, int pos);

#endif
