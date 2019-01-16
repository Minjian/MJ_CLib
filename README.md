# MJ_CLib
My C library contains some common data structures and algorithms

## MJ_String
* Reverse a string: "abcde" -> "edcba" <br>
void reverse_string(char* start, char* end) <br>

* Trim a string by removing unnecessary space charaters: "  a  b  " -> "a b" <br>
void trim_string(char * s)

## MJ_Sort
* Basic sorting algorithms:<br>
void bubble_sort(elem_t *a, int n);<br>
void select_sort(elem_t *a, int n);<br>
void insert_sort(elem_t *a, int n);<br>

* Advanced sorting algorithms:<br>
void shell_sort(elem_t *a, int n);<br>
void merge_sort(elem_t *a, int n);<br>
void quick_sort(elem_t *a, int n);<br>
