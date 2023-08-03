#include "../include/test.h"

char *strlen_tests() {
  const char *str1 = "";
  const char *str2 = "1";
  const char *str3 = "abcdefghijklmnopqrstuvwxyz";
  const char *str4 = "\n";
  const char *str5 = "\0";
  const char *str6 = "		";

  mu_assert("strlen(\"\")", ft_strlen(str1) == strlen(str1));
  mu_assert("strlen(\"1\")", ft_strlen(str2) == strlen(str2));
  mu_assert("strlen(\"abcdefghijklmnopuvwxyz\")",
            ft_strlen(str3) == strlen(str3));
  mu_assert("strlen(\"\\n\")", ft_strlen(str4) == strlen(str4));
  mu_assert("strlen(\"\\0\")", ft_strlen(str5) == strlen(str5));
  mu_assert("strlen(\"\\0\")", ft_strlen(str6) == strlen(str6));
  return 0;
}
