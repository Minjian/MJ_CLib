#include "mjQueue.h"

/* Initialize circular queue. Set the size of the queue to be k. */
mjCircularQueue* mjCircularQueueCreate(int k) {
  elem_t * array = (elem_t *) malloc(sizeof(elem_t) * k);
  mjCircularQueue * mcq = (mjCircularQueue *) malloc(sizeof(mjCircularQueue));
  mcq->head = -1;
  mcq->tail = -1;
  mcq->size = 0;
  mcq->capacity = k;
  mcq->data = array;
  return mcq;
}

/* Initialize linked list queue */
mjLinkedListQueue* mjLinkedListQueueCreate() {
  mjLinkedListQueue * mllq = (mjLinkedListQueue *) malloc(sizeof(mjLinkedListQueue));
  mllq->mll = mjLinkedListCreate();
  return mllq;
}

/* Insert an element into the circular queue. Return true if the operation is successful. */
bool mjCircularQueueEnQueue(mjCircularQueue* obj, elem_t value) {
  if (obj == NULL || obj->size == obj->capacity) return false;
  //EnQueue empty queue
  if (obj->head == -1 && obj->tail == -1) {
    obj->data[0] = value;
    obj->size++;
    obj->head++;
    obj->tail++;
    return true;
  }
  //Tail doesn't reach the end
  else if (obj->tail != obj->capacity - 1) {
    obj->data[obj->tail + 1] = value;
    obj->size++;
    obj->tail++;
    return true;
  }
  // Tail reaches the end
  else {
    obj->data[0] = value;
    obj->size++;
    obj->tail = 0;
    return true;
  }
}

/* Insert an element into the linked list queue. */
void mjLinkedListQueueEnQueue(mjLinkedListQueue* obj, elem_t value) {
  if (obj == NULL) return;
  mjLinkedListAddAtHead(obj->mll, value);
}

/* Delete an element from the circular queue and return as value. Return true if the operation is successful. */
bool mjCircularQueueDeQueue(mjCircularQueue* obj, elem_t * value) {
  if (obj == NULL || obj->size == 0) return false;
  *value = mjCircularQueueFront(obj);
  if (obj->head != obj->capacity - 1) {
    obj->head++;
    obj->size--;
    return true;
  }
  else {
    obj->head = 0;
    obj->size--;
    return true;
  }
}

/* Delete an element from the linked list queue. */
void mjLinkedListQueueDeQueue(mjLinkedListQueue* obj, elem_t * value) {
  if (obj == NULL || obj->mll->size == 0) return;
  *value = obj->mll->tail->val;
  mjLinkedListDeleteAtIndex(obj->mll, obj->mll->size-1);
}

/* Get the front item from the queue. */
elem_t mjCircularQueueFront(mjCircularQueue* obj) {
  if (obj->size == 0) return -1;
  return obj->data[obj->head];
}

/* Get the front item from the queue. */
elem_t mjLinkedListQueueFront(mjLinkedListQueue* obj) {
  if (obj->mll->size == 0) return -1;
  return obj->mll->tail->val;
}

/* Get the last item from the queue. */
elem_t mjCircularQueueRear(mjCircularQueue* obj) {
  if (obj->size == 0) return -1;
  return obj->data[obj->tail];
}

/* Get the last item from the queue. */
elem_t mjLinkedListQueueRear(mjLinkedListQueue* obj) {
  if (obj->mll->size == 0) return -1;
  return obj->mll->head->val;
}

/* Checks whether the circular queue is empty or not. */
bool mjCircularQueueIsEmpty(mjCircularQueue* obj) {
  return (obj->size == 0);
}

/* Checks whether the circular queue is empty or not. */
bool mjLinkedListQueueIsEmpty(mjLinkedListQueue* obj) {
  return (obj->mll->size == 0);
}

/* Checks whether the circular queue is full or not. */
bool mjCircularQueueIsFull(mjCircularQueue* obj) {
  return (obj->size == obj->capacity);
}

/* Destroy the circular queue */
void mjCircularQueueFree(mjCircularQueue* obj) {
  free(obj->data);
  free(obj);
}

/* Destroy the circular queue */
void mjLinkedListQueueFree(mjLinkedListQueue* obj) {
  mjLinkedListFree(obj->mll);
  free(obj);
}

/* Print out the linked list */
void mjPrintCircularQueue(mjCircularQueue* obj) {
  if (obj == NULL) {
    printf("The circular queue hasn't been created\n");
    return;
  }
  if (mjCircularQueueIsEmpty(obj)) {
    printf("The circular queue is empty\n");
    return;
  }

  int cur = obj->head;
  while (cur != obj->tail) {
    printf("%d ", obj->data[cur]);
    cur++;
    if (cur == obj->capacity) cur = 0;
  }
  printf("%d\n", obj->data[cur]);
}

/* Print out the linked list */
void mjPrintLinkedListQueue(mjLinkedListQueue* obj) {
  if (obj == NULL) {
    printf("The circular queue hasn't been created\n");
    return;
  }
  if (mjLinkedListQueueIsEmpty(obj)) {
    printf("The circular queue is empty\n");
    return;
  }
  mjPrintList(obj->mll);
}
