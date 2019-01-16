# MJ_CLib
My C library contains some common data structures and algorithms

## MJ_String
Reverse a string: "abcde" -> "edcba"  
```c
void reverse_string(char* start, char* end)
```

Trim a string by removing unnecessary space charaters: "  a  b  " -> "a b"  
```c
void trim_string(char * s)
```

## MJ_Sort
Basic sorting algorithms: 
```c
void bubble_sort(elem_t *a, int n); 
```
```c
void select_sort(elem_t *a, int n); 
```
```c
void insert_sort(elem_t *a, int n);  
```

Advanced sorting algorithms:  
```c
void shell_sort(elem_t *a, int n); 
```
```c
void merge_sort(elem_t *a, int n); 
```
```c
void quick_sort(elem_t *a, int n);  
```
