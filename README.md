# MJ_CLib
My C library contains some common data structures and algorithms

## MJ_String
* Reverse a string: "abcde" -> "edcba" <br>
void reverseString(char* start, char* end) <br>

* Trim a string by removing unnecessary space charaters: "  a  b  " -> "a b" <br>
void trimString(char * s)

## MJ_Sort
* Basic sorting algorithms:<br>
void bubbleSort(elem_t *a, int n);<br>
void selectSort(elem_t *a, int n);<br>
void insertSort(elem_t *a, int n);<br>

* Advanced sorting algorithms:<br>
void shellSort(elem_t *a, int n);<br>
void mergeSort(elem_t *a, int n);<br>
void quickSort(elem_t *a, int n);

## MJ_Linked_List
* Initialize your data structure here.<br>
mjLinkedList* mjLinkedListCreate();<br>

* Get the value of the index-th node in the linked list.<br>
int mjLinkedListGet(mjLinkedList* obj, int index);<br>

* Change the value of the index-th node in the linked list.<br>
void mjLinkedListChange(mjLinkedList* obj, int index, elem_t val);<br>

* Add node into the linkd list.<br>
void mjLinkedListAddAtHead(mjLinkedList* obj, elem_t val);<br>
void mjLinkedListAddAtTail(mjLinkedList* obj, elem_t val);<br>
void mjLinkedListAddAtIndex(mjLinkedList* obj, int index, elem_t val);<br>

* Delete node from the linked list.<br>
void mjLinkedListDeleteAtIndex(mjLinkedList* obj, int index);<br>

* Destroy the linked list.<br>
void mjLinkedListFree(mjLinkedList* obj);
