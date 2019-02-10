#include <stdio.h>
#include <stdlib.h>
#include "mjQueue.h"

/*
Types of Test Cases:
.Expected Input
.Empty Input
.Malformed Input
.Large Input
.Null Input
.Other Edge Cases
*/

int main(int argc, char const *argv[]) {
  int ret = 0;
  mjLinkedListQueue* obj = mjLinkedListQueueCreate();
  printf("%d\n", (int) mjLinkedListQueueIsEmpty(obj));
  mjLinkedListQueueEnQueue(obj, 12);
  mjLinkedListQueueEnQueue(obj, 13);
  printf("%d\n", (int) mjLinkedListQueueIsEmpty(obj));
  mjLinkedListQueueEnQueue(obj, 120);
  mjLinkedListQueueEnQueue(obj, 112);
  mjLinkedListQueueEnQueue(obj, 92);
  mjLinkedListQueueDeQueue(obj, &ret);
  mjLinkedListQueueDeQueue(obj, &ret);
  mjLinkedListQueueEnQueue(obj, 2);
  mjLinkedListQueueEnQueue(obj, 9);
  printf("%d\n", (int) mjLinkedListQueueIsEmpty(obj));
  mjLinkedListQueueDeQueue(obj, &ret);
  printf("%d\n", ret);
  mjLinkedListQueueDeQueue(obj, &ret);
  printf("%d\n", ret);
  mjLinkedListQueueDeQueue(obj, &ret);
  printf("%d\n", ret);
  mjLinkedListQueueDeQueue(obj, &ret);
  printf("%d\n", ret);
  mjLinkedListQueueDeQueue(obj, &ret);
  printf("%d\n", ret);
  mjLinkedListQueueDeQueue(obj, &ret);
  printf("%d\n", ret);
  mjLinkedListQueueEnQueue(obj, 3);
  mjLinkedListQueueEnQueue(obj, 120);
  mjLinkedListQueueEnQueue(obj, 112);
  mjLinkedListQueueEnQueue(obj, 92);
  printf("%d\n", (int) mjLinkedListQueueIsEmpty(obj));
  mjPrintLinkedListQueue(obj);
  mjLinkedListQueueFree(obj);
  return 0;
}
