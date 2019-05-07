#ifndef CIRCLELIST_H
#define CIRCLELIST_H

typedef void CircleList;

CircleList *circlelist_create();

void circlelist_destroy(CircleList *list);
void circlelist_clear(CircleList *list);
int circlelist_length(CircleList *list);
int circlelist_insert(CircleList *list, void *item, int pos);

void *circlelist_get_userdata(CircleList *list, int pos) ;
void *circlelist_delete(CircleList *list, int pos);

#endif // CIRCLELIST_H
