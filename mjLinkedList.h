#ifndef _MJ_LINKEDLIST_H
#define _MJ_LINKEDLIST_H

typedef int elem_t;

typedef struct {
  struct node *head;
  struct node *tail;
  int size;
} mjLinkedList;

struct node {
  elem_t val;
  struct node *next;
};

/* Initialize your data structure here. */
mjLinkedList* mjLinkedListCreate();

/* Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int mjLinkedListGet(mjLinkedList* obj, int index);

/* Change the value of the index-th node in the linked list. If the index is invalid, return. */
void mjLinkedListChange(mjLinkedList* obj, int index, elem_t val);

/* Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void mjLinkedListAddAtHead(mjLinkedList* obj, elem_t val);

/* Append a node of value val to the last element of the linked list. */
void mjLinkedListAddAtTail(mjLinkedList* obj, elem_t val);

/* Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void mjLinkedListAddAtIndex(mjLinkedList* obj, int index, elem_t val);

/* Delete the index-th node in the linked list, if the index is valid. */
void mjLinkedListDeleteAtIndex(mjLinkedList* obj, int index);

/* Destroy the linked list */
void mjLinkedListFree(mjLinkedList* obj);

#endif
