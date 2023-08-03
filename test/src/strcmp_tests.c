#include "../include/test.h"

#define fct ft_strcmp

char *strcmp_tests() {
  mu_assert("strcmp(\"42\", \"42\")", fct("42", "42") == 0);
  mu_assert("strcmp(\"\", \"\")", fct("", "") == 0);
  mu_assert("strcmp(\"42\", \"43\")", fct("42", "43") < 0);
  mu_assert("strcmp(\"42\", \"41\")", fct("42", "41") > 0);
  mu_assert("strcmp(\"42\", \"9\")", fct("42", "9") < 0);
  mu_assert("strcmp(\"42\", \"4\")", fct("42", "4") > 0);
  mu_assert("strcmp(\"42\", \"\")", fct("42", "") > 0);
  mu_assert("strcmp(\"42\", \"421\")", fct("42", "421") < 0);
  return 0;
}
