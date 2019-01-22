#include <stdio.h>
#include <stdlib.h>
#include "mjLinkedList.h"

/* Initialize your data structure here. */
mjLinkedList* mjLinkedListCreate() {
  mjLinkedList * ls = (mjLinkedList *) malloc(sizeof(mjLinkedList));
  ls->head = NULL;
  ls->tail = NULL;
  ls->size = 0;
  return ls;
}

/* Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int mjLinkedListGet(mjLinkedList* obj, int index) {
  if (index < 0 || index >= obj->size) return -1;
  struct node * cur = obj->head;
  for (int i = 0; i < index; i++) {
    cur = cur->next;
  }
  return cur->val;
}

/* Change the value of the index-th node in the linked list. If the index is invalid, return. */
void mjLinkedListChange(mjLinkedList* obj, int index, elem_t val) {
  if (index < 0 || index >= obj->size) return;
  struct node * cur = obj->head;
  for (int i = 0; i < index; i++) {
    cur = cur->next;
  }
  cur->val = val;
}

/* Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void mjLinkedListAddAtHead(mjLinkedList* obj, elem_t val) {
  struct node * newNode = (struct node *) malloc(sizeof(struct node));
  newNode->val = val;
  newNode->next = obj->head;
  obj->head = newNode;
  obj->size++;
  if (obj->size == 1) obj->tail = obj->head;
}

/* Append a node of value val to the last element of the linked list. */
void mjLinkedListAddAtTail(mjLinkedList* obj, elem_t val) {
  if (obj->tail) {
    struct node * newNode = (struct node *) malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = NULL;
    obj->tail->next = newNode;
    obj->tail = newNode;
    obj->size++;
  }
  else {
    mjLinkedListAddAtHead(obj, val);
  }
}

/* Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void mjLinkedListAddAtIndex(mjLinkedList* obj, int index, elem_t val) {
  if (index < 0 || index > obj->size) return;
  else if (index == 0) {
    mjLinkedListAddAtHead(obj, val);
    return;
  }
  else if (index == obj->size) {
    mjLinkedListAddAtTail(obj, val);
    return;
  }
  else {
    struct node * cur = obj->head;
    for (int i = 1; i < index; i++) cur = cur->next;
    struct node * newNode = (struct node *) malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = cur->next;
    cur->next = newNode;
    obj->size++;
  }
}

/* Delete the index-th node in the linked list, if the index is valid. */
void mjLinkedListDeleteAtIndex(mjLinkedList* obj, int index) {
  if (index < 0 || index >= obj->size) return;
  else if (index == 0) {
    struct node * cur = obj->head;
    obj->head = cur->next;
    free(cur);
    obj->size--;
    return;
  }
  else if (index == obj->size-1) {
    struct node * cur = obj->head;
    while (cur->next != obj->tail) cur = cur->next;
    free(cur->next);
    obj->tail = cur;
    obj->size--;
    return;
  }
  else {
    struct node * cur = obj->head;
    for (int i = 1; i < index; i++) cur = cur->next;
    struct node * del = cur->next;
    cur->next = del->next;
    free(del);
    obj->size--;
    return;
  }
}

/* Delete all nodes having val: 1->2->6->3->4->5->6, val = 6; become 1->2->3->4->5 */
void mjDelElements(mjLinkedList* obj, int val) {
  if (obj == NULL || obj->head == NULL) return;
  //remove the head elements if they are the targets
  while (obj->head && obj->head->val == val) {
    struct node* rm = obj->head;
    obj->head = obj->head->next;
    free(rm);
    obj->size--;
  }
  if (obj->head == NULL) return;

  struct node * cur = obj->head;
  while (cur) {
    while (cur->next && cur->next->val == val) {
      struct node * rm = cur->next;
      cur->next = cur->next->next;
      free(rm);
      obj->size--;
    }
    if (cur->next == NULL) obj->tail = cur;
    cur = cur->next;
  }
}

/* Destroy the linked list */
void mjLinkedListFree(mjLinkedList* obj) {
  struct node * pre_node;
  while (obj->head) {
    pre_node = obj->head;
    obj->head = obj->head->next;
    free(pre_node);
  }
  free(obj);
}

/* Reverse the linked list: 1->2->3->4 become 4->3->2->1 */
void mjReverseList(mjLinkedList* obj) {
  if (obj == NULL) return;
  if (obj->head == NULL || obj->head->next == NULL) return;

  struct node * curNode = obj->head;
  while (curNode->next) {
    struct node * nextNode = curNode->next;
    curNode->next = nextNode->next;
    nextNode->next = obj->head;
    obj->head = nextNode;
  }
  obj->tail = curNode;
}

/* Hash Value function used to create a unique key based on first half of the linked list */
static float hashValue(mjLinkedList* obj, int mIndex) {
  if (obj == NULL) return 0;
  float key = 0;
  struct node* cur = obj->head;
  while (mIndex >= 0 && cur) {
    if (mIndex % 2 == 0) key += (cur->val / (mIndex+1.0));
    else key -= (cur->val / (mIndex+1.0));
    cur = cur->next;
    mIndex--;
  }
  return key;
}

/* Check if the linked list is palindrome: 1->2 false; 1->2->2->1 true; empty linked list is true */
bool mjIsPalindromeList(mjLinkedList* obj) {
  if (obj == NULL || obj->head == NULL) return true;
  else if(obj->head->next == NULL) return true;
  else {
    int size = 0;
    struct node* cur = obj->head;
    while (cur) {
      cur = cur->next;
      size++;
    }
    int mIndex = (size % 2 == 0)? (size/2-1) : (size/2);

    //Key1 for original list
    float key1 = hashValue(obj, mIndex);
    //Key2 for reversed list
    mjReverseList(obj);
    float key2 = hashValue(obj, mIndex);
    //Restore the linked list
    mjReverseList(obj);
    return key1 == key2;
  }
}

/* Print out the linked list */
void mjPrintList(mjLinkedList* obj) {
  if (obj == NULL) {
    printf("The linked list hasn't been created\n");
    return;
  }

  struct node * cur = obj->head;
  while (cur) {
    printf("%d ", cur->val);
    cur = cur->next;
  }
  printf("\n");
}
