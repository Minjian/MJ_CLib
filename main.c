#include <stdio.h>
#include <stdlib.h>
#include "mjCircularQueue.h"

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
  mjCircularQueue* obj = mjCircularQueueCreate(5);
  printf("%d\n", (int) mjCircularQueueIsFull(obj));
  printf("%d\n", (int) mjCircularQueueIsEmpty(obj));
  mjCircularQueueEnQueue(obj, 12);
  mjCircularQueueEnQueue(obj, 13);
  printf("%d\n", (int) mjCircularQueueIsFull(obj));
  printf("%d\n", (int) mjCircularQueueIsEmpty(obj));
  mjCircularQueueEnQueue(obj, 120);
  mjCircularQueueEnQueue(obj, 112);
  mjCircularQueueEnQueue(obj, 92);
  mjCircularQueueDeQueue(obj, &ret);
  mjCircularQueueDeQueue(obj, &ret);
  mjCircularQueueEnQueue(obj, 2);
  mjCircularQueueEnQueue(obj, 9);

  printf("%d\n", (int) mjCircularQueueIsFull(obj));
  printf("%d\n", (int) mjCircularQueueIsEmpty(obj));
  mjPrintCircularQueue(obj);

  mjCircularQueueDeQueue(obj, &ret);
  printf("%d\n", ret);
  mjCircularQueueDeQueue(obj, &ret);
  printf("%d\n", ret);
  mjCircularQueueDeQueue(obj, &ret);
  printf("%d\n", ret);
  mjCircularQueueDeQueue(obj, &ret);
  printf("%d\n", ret);
  mjCircularQueueDeQueue(obj, &ret);
  printf("%d\n", ret);
  mjCircularQueueDeQueue(obj, &ret);
  printf("%d\n", ret);
  mjCircularQueueEnQueue(obj, 3);

  printf("%d\n", (int) mjCircularQueueIsFull(obj));
  printf("%d\n", (int) mjCircularQueueIsEmpty(obj));
  mjCircularQueueFree(obj);
  return 0;
}
