#ifndef _MJ_SORT_H
#define _MJ_SORT_H

typedef int elem_t;

//Basic sorting algorithms
void bubbleSort(elem_t *a, int n);
void selectSort(elem_t *a, int n);
void insertSort(elem_t *a, int n);

//Advanced sorting algorithms
void shellSort(elem_t *a, int n);
void mergeSort(elem_t *a, int n);
void quickSort(elem_t *a, int n);

//Unimplemented sorting algorithms
void heapSort(elem_t *a, int n);
void countingSort(elem_t *a, int n);
void bucketSort(elem_t *a, int n);
void radixSort(elem_t *a, int n);

#endif
