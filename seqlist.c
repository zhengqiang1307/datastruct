#include "seqlist.h"
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct _tag_SeqList {
  int capacity;
  int length;
  unsigned long *node;
} TSeqList;

SeqList *seqlist_create(int capacity) {
  if (capacity < 0) {
    return NULL;
  }
  void *ret = malloc(sizeof(TSeqList) + sizeof(unsigned long) * capacity);
  if (!ret) {
    return NULL;
  }
  memset(ret, 0, sizeof(TSeqList) + sizeof(unsigned long) * capacity);
  TSeqList *tlist = (TSeqList *)ret;
  tlist->capacity = capacity;
  tlist->length = 0;
  tlist->node = (unsigned long *)(tlist + 1);
  return tlist;
}

void seqlist_destroy(SeqList *list) {
  if (list) {
    free(list);
  }
}

void seqlist_clear(SeqList *list) {
  if (list) {
    TSeqList *tlist = (TSeqList *)list;
    tlist->length = 0;
  }
}

int seqlist_length(SeqList *list) {
  if (list) {
    TSeqList *tlist = (TSeqList *)list;
    return tlist->length;
  }
  return -1;
}

int seqlist_capacity(SeqList *list) {
  if (list) {
    TSeqList *tlist = (TSeqList *)list;
    return tlist->capacity;
  }
  return -1;
}

int seqlist_insert(SeqList *list, SeqListNode *node, int pos) {
  if (list == NULL || node == NULL ) {
    return -1;
  }

  TSeqList *tlist = (TSeqList *)list;
  if(tlist->length >=tlist->capacity)
  {
      return -2;
  }
  if(pos < 0 || pos >= tlist->capacity)
  {
      return -3;
  }

  if (pos >= tlist->length) {
    pos = tlist->length;
  }

  for (int i = tlist->length; i > pos; i--) {
      tlist->node[i] = tlist->node[i-1];
  }
  tlist->node[pos] = (unsigned long)node;
  tlist->length++;
  return 0;
}

SeqListNode *seqlist_get(SeqList *list, int pos) {
    if(!list)
        return NULL;
    TSeqList *tlist = (TSeqList *)list;
    if(pos < 0 || pos >= tlist->length)
    {
        return NULL;
    }
    return (SeqListNode*)tlist->node[pos];
}

SeqListNode *seqlist_delete(SeqList *list, int pos) {
    if (list == NULL) {
      return NULL;
    }

    TSeqList *tlist = (TSeqList *)list;

    if(pos < 0 || pos >= tlist->length)
    {
        return NULL;
    }

    SeqListNode* ret = (SeqListNode*)tlist->node[pos];

    for(int i=pos+1; i<tlist->length;i++)
    {
        tlist->node[i-1] = tlist->node[i];
    }

    tlist->length--;
    return ret;
}
