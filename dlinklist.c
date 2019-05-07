#include "dlinklist.h"
#include <stdlib.h>

// typedef void DLinkList;

// typedef struct _tag_DLinkListNode {
//  struct _tag_DLinkListNode *next;
//  struct _tag_DLinkListNode *pre;
//} DLinkListNode;

typedef struct _tag_DLinkList {
  DLinkListNode header;
  DLinkListNode *slider;
  int length;
} TDLinkList;

typedef struct {
  DLinkListNode node;
  void *item;
} DLinkListItem;

DLinkListNode *dlinklist_get(DLinkList *list, int pos);

DLinkList *dlinklist_create() {
  void *ret = malloc(sizeof(TDLinkList));
  if (!ret)
    return NULL;
  TDLinkList *tlist = (TDLinkList *)ret;
  tlist->header.next = NULL;
  tlist->header.pre = NULL;
  tlist->slider = NULL;
  tlist->length = 0;
  return tlist;
}

void dlinklist_destroy(DLinkList *list) {
  dlinklist_clear(list);
  if (list) {
    free(list);
  }
}

void dlinklist_clear(DLinkList *list) {
  if (list) {
    TDLinkList *tlist = (TDLinkList *)list;
    int length = tlist->length;
    for (int i = 0; i < length; i++) {
      dlinklist_delete(list, 0);
    }
    tlist->header.next = NULL;
    tlist->header.pre = NULL;
    tlist->slider = NULL;
    tlist->length = 0;
  }
}

int dlinklist_length(DLinkList *list) {
  if (list) {
    TDLinkList *tlist = (TDLinkList *)list;
    return tlist->length;
  }
  return -1;
}

int dlinklist_insert(DLinkList *list, void *item, int pos) {
  if (!list || !item) {
    return -1;
  }
  TDLinkList *tlist = (TDLinkList *)list;
  if (pos < 0 || pos > tlist->length) {
    return -2;
  }

  DLinkListNode *current = &tlist->header;
  DLinkListNode *next = NULL;

  DLinkListItem *item_node = (DLinkListItem *)malloc(sizeof(DLinkListItem));
  item_node->item = item;
  for (int i = 0; i < pos; i++) {
    current = current->next;
  }

  next = current->next;

  item_node->node.next = current->next;
  current->next = &item_node->node;

  item_node->node.pre = current;

  if (next) {
    next->pre = &item_node->node;
  }

  if (pos == 0) {
    item_node->node.pre = NULL;
    tlist->slider = &item_node->node;
  }

  tlist->length++;
  return 0;
}

DLinkListNode *dlinklist_get(DLinkList *list, int pos) {
  if (!list) {
    return NULL;
  }
  TDLinkList *tlist = (TDLinkList *)list;
  if (pos < 0 || pos >= tlist->length) {
    return NULL;
  }

  DLinkListNode *current = &tlist->header;

  for (int i = 0; i < pos; i++) {
    current = current->next;
  }
  return current->next;
}

void *dlinklist_get_userdata(DLinkList *list, int pos) {
  DLinkListNode *node = dlinklist_get(list, pos);
  DLinkListItem *item_node = (DLinkListItem *)node;
  return item_node->item;
}

void *dlinklist_delete(DLinkList *list, int pos) {
  if (!list) {
    return NULL;
  }
  TDLinkList *tlist = (TDLinkList *)list;
  if (pos < 0 || pos >= tlist->length) {
    return NULL;
  }

  DLinkListNode *current = &tlist->header;
  DLinkListNode *ret = NULL;
  DLinkListNode *next = NULL;

  for (int i = 0; i < pos; i++) {
    current = current->next;
  }

  ret = current->next;
  next = ret->next;

  current->next = next;

  if (next) {
    next->pre = current;
    if (pos == 0) {
      next->pre = NULL;
    }
  }

  if (ret == tlist->slider) {
    tlist->slider = next;
  }

  DLinkListItem *item_node = (DLinkListItem *)ret;
  void *user_data = item_node->item;
  free(item_node);

  tlist->length--;
  return user_data;
}

void *dlinklist_delete_userdata(DLinkList *list, void *item) {
  if (!list || !item) {
    return NULL;
  }
  TDLinkList *tlist = (TDLinkList *)list;
  DLinkListNode *ret = NULL;
  int i = 0;
  for (; i <= tlist->length; i++) {
    ret = dlinklist_get_userdata(list, i);
    if (ret == item)
      break;
  }
  return dlinklist_delete(list, i);
}
DLinkListNode *dlinklist_reset(DLinkList *list) {
  if (!list)
    return NULL;
  TDLinkList *tlist = (TDLinkList *)list;
  tlist->slider = tlist->header.next;
  return tlist->slider;
}
void *dlinklist_current(DLinkList *list) {
  if (!list)
    return NULL;
  TDLinkList *tlist = (TDLinkList *)list;
  DLinkListNode *ret = tlist->slider;
  DLinkListItem *item_node = (DLinkListItem *)ret;
  return item_node->item;
}
void *dlinklist_next(DLinkList *list) {

  TDLinkList *tlist = (TDLinkList *)list;
  if (!list || !tlist->slider)
    return NULL;
  DLinkListNode *ret = tlist->slider;
  tlist->slider = ret->next;
  DLinkListItem *item_node = (DLinkListItem *)ret;
  return item_node->item;
}

void *dlinklist_pre(DLinkList *list) {
  TDLinkList *tlist = (TDLinkList *)list;
  if (!list || !tlist->slider)
    return NULL;
  DLinkListNode *ret = tlist->slider;
  tlist->slider = ret->pre;
  DLinkListItem *item_node = (DLinkListItem *)ret;
  return item_node->item;
}
