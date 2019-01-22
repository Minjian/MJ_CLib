#include <stdio.h>
#include <stdlib.h>
#include "mjString.h"
#include "mjSort.h"
#include "mjLinkedList.h"

int main(int argc, char const *argv[]) {
  mjLinkedList* obj = mjLinkedListCreate();
  mjLinkedListAddAtHead(obj, 5);
  mjLinkedListAddAtHead(obj, 2);
  mjLinkedListDeleteAtIndex(obj, 1);
  mjLinkedListAddAtIndex(obj, 1, 9);
  mjLinkedListAddAtHead(obj, 4);
  mjLinkedListAddAtHead(obj, 9);
  mjLinkedListAddAtHead(obj, 8);
  int param_1 = mjLinkedListGet(obj, 3);
  mjLinkedListAddAtTail(obj, 1);
  mjLinkedListAddAtIndex(obj, 3, 6);
  mjLinkedListAddAtHead(obj, 3);

  mjLinkedListChange(obj, 3, 8);
  mjPrintList(obj);

  mjReverseList(obj);
  mjPrintList(obj);

  printf("%d\n", (int)mjIsPalindromeList(obj));
  mjPrintList(obj);


  return 0;
}
