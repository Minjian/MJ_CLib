#ifndef _MJ_CIRCULAR_QUEUE_H
#define _MJ_CIRCULAR_QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int elem_t;

/* Use an array to implement queue */
typedef struct {
  int head;
  int tail;
  int size;
  int capacity;
  elem_t * data;
} mjCircularQueue;

/* Initialize your data structure here. Set the size of the queue to be k. */
mjCircularQueue* mjCircularQueueCreate(int k);

/* Insert an element into the circular queue. Return true if the operation is successful. */
bool mjCircularQueueEnQueue(mjCircularQueue* obj, elem_t value);

/* Delete an element from the circular queue and return as value. Return true if the operation is successful. */
bool mjCircularQueueDeQueue(mjCircularQueue* obj, elem_t * value);

/* Get the front item from the queue. */
elem_t mjCircularQueueFront(mjCircularQueue* obj);

/* Get the last item from the queue. */
elem_t mjCircularQueueRear(mjCircularQueue* obj);

/* Checks whether the circular queue is empty or not. */
bool mjCircularQueueIsEmpty(mjCircularQueue* obj);

/* Checks whether the circular queue is full or not. */
bool mjCircularQueueIsFull(mjCircularQueue* obj);

/* Destroy the circular queue */
void mjCircularQueueFree(mjCircularQueue* obj);

/* Print out the circular queue */
void mjPrintCircularQueue(mjCircularQueue* obj);

#endif
