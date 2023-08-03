#include "../include/test.h"

#define fct ft_strdup

char *strdup_tests() {
  char *str = fct("42");
  mu_assert("return string of strcmp(str, \" 42 \")", strcmp(str, "42") == 0);
  errno = 0;
  free(str);
  return 0;
}
