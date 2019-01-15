#include <ctype.h>
#include "mj_string.h"

/* Reverse a string: "abcde" -> "edcba" */
inline void reverse_string(char* start, char* end) {
  while(end>start) {
    char tmp = *end;
    *end = *start;
    *start=tmp;
    end--;
    start++;
  }
}

/* Trim a string by removing unnecessary space charaters: "  a  b  " -> "a b" */
inline void trim_string(char * s) {
  char * runner;
  char * chaser;
  for (runner = s, chaser = s; *runner != '\0'; runner++) {
    if (isspace(*runner)) {
      // trim the middle spaces & ending spaces
      while (isspace(*(runner+1)) && (*(runner+1) != '\0')) runner++;
      //reach the last char
      if (*(runner+1) == '\0') break;
      // trim the starting spaces
      if (chaser == s) continue;
    }
    //move the non-space char to the chaser position
    if (runner != chaser) {
      char tmp = *runner; *runner = *chaser; *chaser=tmp;
    }
    chaser++;
  }
  // add the string ending
  *chaser = '\0';
}
