#include "circlelist.h"
#include <stdlib.h>

typedef struct _tag_CircleListNode {
  struct _tag_CircleListNode *next;
} CircleListNode;

CircleListNode *circlelist_get(CircleList *list, int pos);

typedef struct {
  CircleListNode *next;
  void *user_data;
} CircleListItem;

typedef struct {
  CircleListNode *next;
  CircleListNode *slider;
  int length;
} TagCircleList;

CircleList *circlelist_create() {

  CircleList *ret = malloc(sizeof(TagCircleList));
  if (!ret)
    return NULL;
  TagCircleList *tlist = (TagCircleList *)ret;

  tlist->next = NULL;
  tlist->slider = NULL;
  tlist->length = 0;

  return ret;
}

void circlelist_destroy(CircleList *list) {
  if (list) {
    circlelist_clear(list);
    free(list);
  }
}

void circlelist_clear(CircleList *list) {
  if (!list) {
    return;
  }
  TagCircleList *tlist = (TagCircleList *)list;
  while (tlist->length > 0) {
    circlelist_delete(list, tlist->length - 1);
  }
}
int circlelist_length(CircleList *list) {
  if (!list) {
    return -1;
  }
  TagCircleList *tlist = (TagCircleList *)list;
  return tlist->length;
}

int circlelist_insert(CircleList *list, void *item, int pos) {
  if (!list || !item || pos < 0)
    return -1;
  TagCircleList *tlist = (TagCircleList *)list;

  CircleListNode *current = (CircleListNode *)tlist;
  for (int i = 0; i < pos && (current->next); i++) {
    current = current->next;
  }

  CircleListItem *item_node = (CircleListItem *)malloc(sizeof(CircleListItem));
  item_node->user_data = item;
  item_node->next = current->next;
  current->next = (CircleListNode *)item_node;

  if (tlist->length == 0) {
    item_node->next = (CircleListNode *)item_node;
  }
  tlist->length++;

  if (current->next == tlist->next) {
    CircleListNode *last_node = circlelist_get(list, tlist->length - 1);
    last_node->next = current->next;
  }

  return 0;
}

CircleListNode *circlelist_get(CircleList *list, int pos) {
  if (!list || pos < 0) {
    return NULL;
  }

  TagCircleList *tlist = (TagCircleList *)list;
  if (tlist->length == 0)
    return NULL;

  CircleListNode *current = (CircleListNode *)tlist;

  for (int i = 0; i < pos; i++) {
    current = current->next;
  }

  return current->next;
}

void *circlelist_delete(CircleList *list, int pos) {
  if (!list || pos < 0)
    return NULL;
  TagCircleList *tlist = (TagCircleList *)list;

  if (tlist->length == 0)
    return NULL;

  CircleListNode *current = (CircleListNode *)tlist;

  while (pos >= tlist->length) {
    pos = pos - tlist->length;
  }

  for (int i = 0; i < pos; i++) {
    current = current->next;
  }

  CircleListNode *ret = current->next;
  current->next = ret->next;

  if (ret == tlist->next) {
    CircleListNode *last_node = circlelist_get(list, tlist->length - 1);
    last_node->next = ret->next;
  }

  CircleListItem *item_node = (CircleListItem *)ret;
  void *user_data = item_node->user_data;
  free(item_node);

  tlist->length--;
  if (tlist->length == 0) {
    tlist->next = NULL;
  }
  return user_data;
}

void *circlelist_get_userdata(CircleList *list, int pos) {
  CircleListNode *node = circlelist_get(list, pos);
  CircleListItem *item = (CircleListItem *)node;
  return item->user_data;
}
