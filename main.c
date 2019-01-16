#include <stdio.h>
#include <stdlib.h>
#include "mj_string.h"
#include "mj_sort.h"

int main(int argc, char const *argv[]) {

  int a1[10] = {0, 37, 28, 1913, -12387, 28, 0, 19, -1, 10};
  int a2[1] = {0};

  merge_sort(a1, 10);
  merge_sort(a2, 1);

  for (int i = 0; i < 10; i++) {
    printf("%d ", a1[i]);
  }
  printf("\n");
  printf("%d ", a2[0]);
  printf("\n");

  return 0;
}
