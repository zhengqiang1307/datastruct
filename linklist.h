#ifndef LinkList_H
#define LinkList_H

typedef void LinkList;

typedef struct _tag_LinkListNode {
  struct _tag_LinkListNode *next;
} LinkListNode;

LinkList *linklist_create();
void linklist_destroy(LinkList *list);
void linklist_clear(LinkList *list);
int linklist_length(LinkList *list);
int linklist_insert(LinkList *list, void *item, int pos);
void *linklist_get(LinkList *list, int pos);
void *linklist_delete(LinkList *list, int pos);

#endif // LinkList_H
