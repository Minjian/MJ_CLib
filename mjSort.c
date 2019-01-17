#include "mjSort.h"

static inline void swap(elem_t *a, elem_t *b) {
  elem_t tmp = *a;
  *a = *b;
  *b = tmp;
}

/*
bubbleSort: bubble up the smaller value, put the larger value at the end.
(Each round, the largest value is put at the end)
Time Complexity: O(N^2); Space Complexity: O(1); Stability: Yes
*/
void bubbleSort(elem_t *a, int n) {
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-1-i; j++) {
      if (a[j] > a[j+1]) {
        swap(a+j, a+j+1);
      }
    }
  }
}

/*
selectSort: each round finds the min value of the current index,
then put the value into the correct position.
Time Complexity: O(N^2); Space Complexity: O(1); Stability: Yes
*/
void selectSort(elem_t *a, int n) {
  int i, j, minIndex;
  for (i = 0; i < n-1; i++) {
    for (minIndex = i, j = i+1; j < n; j++) {
      if (a[j] < a[minIndex]) minIndex = j;
    }

    if (i != minIndex) swap(a+i, a+minIndex);
  }
}

/*
insertSort: each round marks the current value, compare the curValue with its
previous values, if previuos value > curValue, then switch, compare the next previous value.
Time Complexity: O(N^2); Space Complexity: O(1); Stability: Yes
*/
void insertSort(elem_t *a, int n) {
  int i, j, curValue;
  for (i = 1; i < n; i++) {
    for (curValue = a[i], j = i-1; j >= 0 && a[j] > curValue; j--)
      a[j+1] = a[j];
    a[j+1] = curValue;
  }
}

/*
shellSort: a various version of insertSort, like insertSort, but introduce k for step size.
Time Complexity: O(N^2); Space Complexity: O(1); Stability: No
*/
void shellSort(elem_t *a, int n) {
  int i, j, curValue;
  for (int k = n/2; k > 0; k = k/2) {
    for (i = k; i < n; i++) {
      for (curValue = a[i], j = i-k; j >= 0 && a[j] > curValue; j = j-k)
        a[j+k] = a[j];
      a[j+k] = curValue;
    }
  }
}

/*
mergeSort: recursively seperate the array into two parts, for each part, the left side
is smaller than the middle value, right side is larger than the middle value.
Time Complexity: O(N * logN); Space Complexity: O(N); Stability: Yes
*/
void mergeSort(elem_t *a, int n) {
  int m = n/2;
  int left = 0, right = left+m;
  if (m > 0) {
    mergeSort(a, m);
    mergeSort(a+right, n-m);
  }

  //need extra space to store sorted values
  elem_t b[n];
  int i = 0;
  while ((left < m) && (right < n)) {
    if (a[left] <= a[right]) {
      b[i] = a[left];
      i++; left++;
    }
    else {
      b[i] = a[right];
      i++; right++;
    }
  }
  //add the rest left elements to b
  while (left < m) {
    b[i] = a[left];
    i++; left++;
  }
  //add the rest right elements to b
  while (right < n) {
    b[i] = a[right];
    i++; right++;
  }

  //copy sorted b to a
  for (i = 0; i < n; i++) a[i] = b[i];
}

/*
quickSort: choose the middle value first, then make its left side are all small value,
its right side are all large value, then recurse both sides.
Time Complexity: O(N * logN); Space Complexity: O(1); Stability: No
*/
void quickSort(elem_t *a, int n) {
  if (n <= 1) return;

  elem_t *ptLeft = a;
  elem_t *ptRight = a+n-1;
  elem_t *ptMiddle = a+n/2;
  elem_t curValue = *ptMiddle;

  //find first larger value on the left side, move ptLeft first
  while ((ptLeft < ptMiddle) && (*ptLeft <= *ptMiddle)) ptLeft++;
  if (ptLeft < ptMiddle) *ptMiddle = *ptLeft;

  /*
  keep increase ptLeft & decrease ptRight, to make values on the left side
  are less than curValue, values on the right side are more than curValue
  */
  while (1) {
    //move right side small value to the left side
    while ((ptLeft < ptRight) && (*ptRight >= curValue)) ptRight--;
    if (ptLeft < ptRight) {
      *ptLeft = *ptRight;
      ptLeft++;
    }
    else {
      break;
    }

    //move left side larger value to the right side
    while ((ptLeft < ptRight) && (*ptLeft <= curValue)) ptLeft++;
    if (ptLeft < ptRight) {
      *ptRight = *ptLeft;
      ptRight--;
    }
    else {
      break;
    }
  }
  *ptLeft = curValue;

  //recurse the left side and the right side
  quickSort(a, ptLeft-a);
  quickSort(ptLeft+1, n-1-(ptLeft-a));
}

/*
heapSort: change the array to binary tree to get values
Time Complexity: O(N * logN); Space Complexity: O(1); Stability: No
*/
void heapSort(elem_t *a, int n){}

/*
countingSort: put each value into corresponding counterArray, get values out of the counterArray
from smallest to largest.
Time Complexity: O(N); Space Complexity: O(N); Stability: Yes
*/
void countingSort(elem_t *a, int n){}

/*
bucketSort: a various vesion of countingSort, similar to hash map.
Time Complexity: O(N); Space Complexity: O(N); Stability: Yes
*/
void bucketSort(elem_t *a, int n){}

/*
radixSort: 0-9 radix bucket, put values into buckets based on the single digits, then get them out
from smallest to largest, then tenth digits and so forth.
Time Complexity: O(N); Space Complexity: O(N); Stability: Yes
*/
void radixSort(elem_t *a, int n){}
