#include "mj_sort.h"

static inline void swap(elem_t *a, elem_t *b) {
  elem_t tmp = *a;
  *a = *b;
  *b = tmp;
}

/*
Bubble_sort: bubble up the smaller value, put the larger value at the end.
(Each round, the largest value is put at the end)
Time Complexity: O(N^2); Space Complexity: O(1); Stability: Yes
*/
void bubble_sort(elem_t *a, int n) {
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-1-i; j++) {
      if (a[j] > a[j+1]) {
        swap(a+j, a+j+1);
      }
    }
  }
}

/*
Select_sort: each round finds the min value of the current index,
then put the value into the correct position.
Time Complexity: O(N^2); Space Complexity: O(1); Stability: Yes
*/
void select_sort(elem_t *a, int n) {
  int i, j, min_index;
  for (i = 0; i < n-1; i++) {
    for (min_index = i, j = i+1; j < n; j++) {
      if (a[j] < a[min_index]) min_index = j;
    }

    if (i != min_index) swap(a+i, a+min_index);
  }
}

/*
Insert_sort: each round marks the current value, compare the cur_value with its
previous values, if previuos value > cur_value, then switch, compare the next previous value.
Time Complexity: O(N^2); Space Complexity: O(1); Stability: Yes
*/
void insert_sort(elem_t *a, int n) {
  int i, j, cur_value;
  for (i = 1; i < n; i++) {
    for (cur_value = a[i], j = i-1; j >= 0 && a[j] > cur_value; j--)
      a[j+1] = a[j];
    a[j+1] = cur_value;
  }
}

/*
Shell_sort: a various version of insert_sort, like insert_sort, but introduce k for step size.
Time Complexity: O(N^2); Space Complexity: O(1); Stability: No
*/
void shell_sort(elem_t *a, int n) {
  int i, j, cur_value;
  for (int k = n/2; k > 0; k = k/2) {
    for (i = k; i < n; i++) {
      for (cur_value = a[i], j = i-k; j >= 0 && a[j] > cur_value; j = j-k)
        a[j+k] = a[j];
      a[j+k] = cur_value;
    }
  }
}

/*
Merge_sort: recursively seperate the array into two parts, for each part, the left side
is smaller than the middle value, right side is larger than the middle value.
Time Complexity: O(N * logN); Space Complexity: O(N); Stability: Yes
*/
void merge_sort(elem_t *a, int n) {
  int m = n/2;
  int left = 0, right = left+m;
  if (m > 0) {
    merge_sort(a, m);
    merge_sort(a+right, n-m);
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
Quick_sort: choose the middle value first, then make its left side are all small value,
its right side are all large value, then recurse both sides.
Time Complexity: O(N * logN); Space Complexity: O(1); Stability: No
*/
void quick_sort(elem_t *a, int n) {
  if (n <= 1) return;

  elem_t *pt_left = a;
  elem_t *pt_right = a+n-1;
  elem_t *pt_middle = a+n/2;
  elem_t cur_value = *pt_middle;

  //find first larger value on the left side, move pt_left first
  while ((pt_left < pt_middle) && (*pt_left <= *pt_middle)) pt_left++;
  if (pt_left < pt_middle) *pt_middle = *pt_left;

  /*
  keep increase pt_left & decrease pt_right, to make values on the left side
  are less than cur_value, values on the right side are more than cur_value
  */
  while (1) {
    //move right side small value to the left side
    while ((pt_left < pt_right) && (*pt_right >= cur_value)) pt_right--;
    if (pt_left < pt_right) {
      *pt_left = *pt_right;
      pt_left++;
    }
    else {
      break;
    }

    //move left side larger value to the right side
    while ((pt_left < pt_right) && (*pt_left <= cur_value)) pt_left++;
    if (pt_left < pt_right) {
      *pt_right = *pt_left;
      pt_right--;
    }
    else {
      break;
    }
  }
  *pt_left = cur_value;

  //recurse the left side and the right side
  quick_sort(a, pt_left-a);
  quick_sort(pt_left+1, n-1-(pt_left-a));
}

/*
Heap_sort: change the array to binary tree to get values
Time Complexity: O(N * logN); Space Complexity: O(1); Stability: No
*/
void heap_sort(elem_t *a, int n){}

/*
Counting_sort: put each value into corresponding counter_array, get values out of the counter_array
from smallest to largest.
Time Complexity: O(N); Space Complexity: O(N); Stability: Yes
*/
void counting_sort(elem_t *a, int n){}

/*
Bucket_sort: a various vesion of counting_sort, similar to hash map.
Time Complexity: O(N); Space Complexity: O(N); Stability: Yes
*/
void bucket_sort(elem_t *a, int n){}

/*
Radix_sort: 0-9 radix bucket, put values into buckets based on the single digits, then get them out
from smallest to largest, then tenth digits and so forth.
Time Complexity: O(N); Space Complexity: O(N); Stability: Yes
*/
void radix_sort(elem_t *a, int n){}
