#ifndef _MJ_QUEUE_H
#define _MJ_QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "mjLinkedList.h"

typedef int elem_t;

/* Use an array to implement queue */
typedef struct {
  int head;
  int tail;
  int size;
  int capacity;
  elem_t * data;
} mjCircularQueue;

/* Use an linked list to implement queue */
typedef struct {
  mjLinkedList * mll;
} mjLinkedListQueue;

/* Initialize queue, circular queue requires a size k. */
mjCircularQueue* mjCircularQueueCreate(int k);
mjLinkedListQueue* mjLinkedListQueueCreate();

/* Insert an element into the queue */
bool mjCircularQueueEnQueue(mjCircularQueue* obj, elem_t value);
void mjLinkedListQueueEnQueue(mjLinkedListQueue* obj, elem_t value);

/* Delete an element from the queue */
bool mjCircularQueueDeQueue(mjCircularQueue* obj, elem_t * value);
void mjLinkedListQueueDeQueue(mjLinkedListQueue* obj, elem_t * value);

/* Get the front item from the queue. */
elem_t mjCircularQueueFront(mjCircularQueue* obj);
elem_t mjLinkedListQueueFront(mjLinkedListQueue* obj);

/* Get the last item from the queue. */
elem_t mjCircularQueueRear(mjCircularQueue* obj);
elem_t mjLinkedListQueueRear(mjLinkedListQueue* obj);

/* Checks whether the queue is empty or not. */
bool mjCircularQueueIsEmpty(mjCircularQueue* obj);
bool mjLinkedListQueueIsEmpty(mjLinkedListQueue* obj);

/* Checks whether the circular queue is full or not. */
bool mjCircularQueueIsFull(mjCircularQueue* obj);

/* Destroy the queue */
void mjCircularQueueFree(mjCircularQueue* obj);
void mjLinkedListQueueFree(mjLinkedListQueue* obj);

/* Print out the circular queue */
void mjPrintCircularQueue(mjCircularQueue* obj);
void mjPrintLinkedListQueue(mjLinkedListQueue* obj);

#endif
