#ifndef _MJ_SORT_H
#define _MJ_SORT_H

typedef int elem_t;

//Basic sorting algorithms
void bubble_sort(elem_t *a, int n);
void select_sort(elem_t *a, int n);
void insert_sort(elem_t *a, int n);

//Advanced sorting algorithms
void shell_sort(elem_t *a, int n);
void merge_sort(elem_t *a, int n);
void quick_sort(elem_t *a, int n);

//Unimplemented sorting algorithms
void heap_sort(elem_t *a, int n);
void counting_sort(elem_t *a, int n);
void bucket_sort(elem_t *a, int n);
void radix_sort(elem_t *a, int n);

#endif
