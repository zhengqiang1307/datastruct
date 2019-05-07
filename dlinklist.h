#ifndef dlinklist
#define dlinklist

typedef void DLinkList;

typedef struct _tag_DLinkListNode {
  struct _tag_DLinkListNode *next;
  struct _tag_DLinkListNode *pre;
} DLinkListNode;

DLinkList *dlinklist_create();

void dlinklist_destroy(DLinkList *list);

void dlinklist_clear(DLinkList *list);

int dlinklist_length(DLinkList *list);
int dlinklist_insert(DLinkList *list, void *item, int pos);

void *dlinklist_get_userdata(DLinkList *list, int pos);
void *dlinklist_delete(DLinkList *list, int pos);

void *dlinklist_delete_userdata(DLinkList *list, void *item);
DLinkListNode *dlinklist_reset(DLinkList *list);
void *dlinklist_current(DLinkList *list);
void *dlinklist_next(DLinkList *list);
void *dlinklist_pre(DLinkList *list);

#endif
