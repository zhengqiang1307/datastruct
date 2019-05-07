#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//#include "linkqueue.h"

// int main(void)
//{
//    int i , a[10];
//    LinkQueue* queue = NULL;

//    queue = linkqueue_create();

//    for (i=0; i<10; i++)
//    {
//        a[i] = i + 1;
//        linkqueue_append(queue, &a[i]);
//    }

//    //
//    printf("the length of queue: %d \n", linkqueue_length(queue));
//    printf("the header of queue: %d \n", *( (int *)linkqueue_header(queue) )
//    );

//    while (linkqueue_length(queue) > 0)
//    {
//        printf("%d \n", *((int *)linkqueue_retrieve(queue)) );
//    }

//    linkqueue_destroy(queue);

//    system("pause");
//    return 0;
//}

#include "dlinklist.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int v;
} Value;

int main(int argc, char *argv[]) {
  int i = 0;
  DLinkList *list = dlinklist_create();
  Value *pv = NULL;
  Value v1, v2, v3, v4, v5;

  v1.v = 1;
  v2.v = 2;
  v3.v = 3;
  v4.v = 4;
  v5.v = 5;

  dlinklist_insert(list, &v1, dlinklist_length(list));
  dlinklist_insert(list, &v2, dlinklist_length(list));
  dlinklist_insert(list, &v3, dlinklist_length(list));
  dlinklist_insert(list, &v4, dlinklist_length(list));
  dlinklist_insert(list, &v5, dlinklist_length(list));

  for (i = 0; i < dlinklist_length(list); i++) {
    pv = (Value *)dlinklist_get_userdata(list, i);
    printf("%d\n", pv->v);
  }

  printf("\n");

    dlinklist_delete(list, dlinklist_length(list));
    dlinklist_delete(list, 0);

    for (i = 0; i < dlinklist_length(list); i++) {
      pv = (Value *)dlinklist_get_userdata(list, i);

      printf("%d\n", pv->v);
    }

    printf("\n");

    for (i = 0; i < dlinklist_length(list); i++) {
      pv = (Value *)dlinklist_next(list);
      printf("%d\n", pv->v);
    }

    printf("\n");

      dlinklist_reset(list);
      dlinklist_next(list);

      pv = (Value*)dlinklist_current(list);

      printf("%d\n", pv->v);
      printf("\n");

      dlinklist_delete_userdata(list, pv);

      pv = (Value*)dlinklist_current(list);

      printf("%d\n", pv->v);printf("\n");

      dlinklist_pre(list);

      pv = (Value*)dlinklist_current(list);

      printf("%d\n", pv->v);

      printf("Length: %d\n", dlinklist_length(list));

      dlinklist_destroy(list);
  system("pause");
  return 0;
}
