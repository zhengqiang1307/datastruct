#include "linklist.h"
#include <stdlib.h>

typedef struct _tag_LinkList {
  LinkListNode header;
  int length;
} TLinkList;

typedef struct {
  LinkListNode node;
  void *item;
} LinkListItem;

LinkList *linklist_create() {
  TLinkList *tlist = (TLinkList *)malloc(sizeof(TLinkList));
  if (tlist == NULL)
    return NULL;
  tlist->length = 0;
  tlist->header.next = NULL;
  return tlist;
}

void linklist_destroy(LinkList *list) {
  linklist_clear(list);
  if (list) {
    free(list);
  }
}

void linklist_clear(LinkList *list) {
  if (list) {
    TLinkList *tlist = (TLinkList *)list;
    int length = tlist->length;
    for (int i = 0; i < length; i++) {
      linklist_delete(tlist, 0);
    }
    tlist->header.next = NULL;
    tlist->length = 0;
  }
}

int linklist_length(LinkList *list) {
  if (list) {
    TLinkList *tlist = (TLinkList *)list;
    return tlist->length;
  }
  return -1;
}

int linklist_insert(LinkList *list, void *item, int pos) {
  if (!list || !item) {
    return -1;
  }
  TLinkList *tlist = (TLinkList *)list;
  if (pos < 0) {
    return -2;
  }
  if (pos > tlist->length) {
    pos = tlist->length;
  }
  LinkListNode *current = &(tlist->header);

  LinkListItem *item_node = (LinkListItem *)malloc(sizeof(LinkListItem));
  item_node->node.next = NULL;
  item_node->item = item;

  for (int i = 0; i < pos; i++) {
    current = current->next;
  }
  item_node->node.next = current->next;
  current->next = &item_node->node;
  tlist->length++;
  return 0;
}

void *linklist_get(LinkList *list, int pos) {
  if (!list) {
    return NULL;
  }
  TLinkList *tlist = (TLinkList *)list;
  if (pos < 0 || pos >= tlist->length) {
    return NULL;
  }
  LinkListNode *current = tlist->header.next;
  for (int i = 0; i < pos; i++) {
    current = current->next;
  }
  LinkListItem *item_node = (LinkListItem *)current;
  return item_node->item;
}

void *linklist_delete(LinkList *list, int pos) {
  if (!list) {
    return NULL;
  }
  TLinkList *tlist = (TLinkList *)list;
  if (pos < 0 || pos >= tlist->length) {
    return NULL;
  }
  LinkListNode *current = &tlist->header;
  for (int i = 0; i < pos; i++) {
    current = current->next;
  }
  LinkListNode *ret = current->next;
  current->next = ret->next;
  tlist->length--;

  LinkListItem *item_node = (LinkListItem *)ret;
  void *myitem = item_node->item;
  free(item_node);
  return myitem;
}
