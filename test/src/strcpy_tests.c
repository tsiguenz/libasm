#include "../include/test.h"

char *strcpy_tests() {
  char dest1[6] = "    ";
  const char *src1 = "hello";
  mu_assert("return value of strcpy(dest1, src1)",
            ft_strcpy(dest1, src1) == dest1);
  mu_assert("copy of src1 to dest1", !strcmp(dest1, src1));

  char dest2[500];
  const char *src2 = "libasm is a very good exercise to learn assembly :)";
  mu_assert("return value of strcpy(dest2, src2",
            ft_strcpy(dest2, src2) == dest2);
  mu_assert("copy of src2 to dest2", !strcmp(dest2, src2));

  char dest3[10];
  memset(dest3, 42, 10);
  const char *src3 = "42";
  mu_assert("return value of strcpy(dest3, src3",
            ft_strcpy(dest3, src3) == dest3);
  mu_assert("copy of src3 to dest3", !strcmp(dest3, src3));

  return 0;
}
