#include <stdio.h>
extern void ft_strlen(int *a);

int main(void) {
  int a = 0;
  ft_strlen(&a);
  printf("a = %d\n", a);
  return 0;
}
