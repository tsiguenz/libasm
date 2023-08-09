#include "../include/test.h"

#define fct ft_strdup

char *strdup_tests() {
  char *str = NULL;

  str = fct("42");
  mu_assert("strcmp ft_strdup(\"42\")", strcmp(str, "42") == 0);
  free(str);

  str = fct("");
  mu_assert("strcmp ft_strdup(\"\")", strcmp(str, "") == 0);
  free(str);

  mu_assert("check errno after ft_strdup", errno == 0);

  errno = 0;
  return 0;
}
