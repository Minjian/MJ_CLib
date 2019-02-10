# MJ_CLib
My C library contains some common data structures and algorithms<br>
(still updating, stay tuned!)<br>

## MJ_String
* Reverse a string: "abcde" -> "edcba" <br>
void reverseString(char* start, char* end) <br>

* Trim a string by removing unnecessary space charaters: "  a  b  " -> "a b" <br>
void trimString(char * s)<br>

## MJ_Sort
* Basic sorting algorithms:<br>
void bubbleSort(elem_t *a, int n);<br>
void selectSort(elem_t *a, int n);<br>
void insertSort(elem_t *a, int n);<br>

* Advanced sorting algorithms:<br>
void shellSort(elem_t *a, int n);<br>
void mergeSort(elem_t *a, int n);<br>
void quickSort(elem_t *a, int n);<br>

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

* Delete all nodes having val: 1->2->6->3->4->5->6, val = 6; become 1->2->3->4->5 <br>
void mjDelElements(mjLinkedList* obj, int val);<br>

* Destroy the linked list.<br>
void mjLinkedListFree(mjLinkedList* obj);<br>

* Reverse the linked list: 1->2->3->4 become 4->3->2->1<br>
void mjReverseList(mjLinkedList* obj);<br>

* Check if the linked list is palindrome: 1->2 false; 1->2->2->1 true<br>
bool mjIsPalindromeList(mjLinkedList* obj);<br>

* Print out the linked list<br>
void mjPrintList(mjLinkedList* obj);<br>

## MJ_Queue
Use an Array to implement the circular queue & Use mjLinkedList to implement the linked-list queue <br>

* Initialize queue, circular queue requires a size k<br>
mjCircularQueue* mjCircularQueueCreate(int k);<br>
mjLinkedListQueue* mjLinkedListQueueCreate();<br>

* Insert an element into the queue<br>
bool mjCircularQueueEnQueue(mjCircularQueue* obj, elem_t value);<br>
void mjLinkedListQueueEnQueue(mjLinkedListQueue* obj, elem_t value);<br>

* Delete an element from the queue<br>
bool mjCircularQueueDeQueue(mjCircularQueue* obj, elem_t * value);<br>
void mjLinkedListQueueDeQueue(mjLinkedListQueue* obj, elem_t * value);<br>

* Get the front item from the queue<br>
elem_t mjCircularQueueFront(mjCircularQueue* obj);<br>
elem_t mjLinkedListQueueFront(mjLinkedListQueue* obj);<br>

* Get the last item from the queue. <br>
elem_t mjCircularQueueRear(mjCircularQueue* obj);<br>
elem_t mjLinkedListQueueRear(mjLinkedListQueue* obj);<br>

* Checks whether the queue is empty or not. <br>
bool mjCircularQueueIsEmpty(mjCircularQueue* obj);<br>
bool mjLinkedListQueueIsEmpty(mjLinkedListQueue* obj);<br>

* Checks whether the circular queue is full or not. <br>
bool mjCircularQueueIsFull(mjCircularQueue* obj);<br>

* Destroy the queue <br>
void mjCircularQueueFree(mjCircularQueue* obj);<br>
void mjLinkedListQueueFree(mjLinkedListQueue* obj);<br>

* Print out the circular queue <br>
void mjPrintCircularQueue(mjCircularQueue* obj);<br>
void mjPrintLinkedListQueue(mjLinkedListQueue* obj);
