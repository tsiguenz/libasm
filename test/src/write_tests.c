#include "../include/test.h"

#define fct ft_write

char *write_tests() {
  ssize_t ret = 0;
  ret = fct(1, "Hello world!\n", 13);
  mu_assert("return value of write(1, \"Hello world!\\n\", 13)", ret == 13);
  mu_assert("errno after write(1, \"Hello world!\n\", 13)", errno == 0);

  ret = fct(1, "", 0);
  mu_assert("return value of write(1, \"\", 0)", ret == 0);
  mu_assert("errno after write(1, \"\", 0)", errno == 0);

  ret = fct(1, "422222222222", 2);
  mu_assert("return value of write(1, \"422222222222\", 2)", ret == 2);
  mu_assert("errno after write(1, \"422222222222\", 11)", errno == 0);

  // TODO(tsiguenz): Need to handle that ?
  // ret = fct(1, "Hello world!\n", 100);
  // mu_assert("return value of write(1, \"Hello world!\\n\", 100)", ret ==
  // 100); mu_assert("errno after write(1, \"Hello world!\\n\", 100)", errno ==
  // 0);

  // TODO(tsiguenz): gcc crash here and valgrind not ok, do what ?
  ret = fct(1, NULL, 4);
  mu_assert("return value of write(1, NULL, 4)", ret == -1);
  mu_assert("errno after write(1, NULL, 4)", errno == EFAULT);

  ret = fct(5, "Bad file descriptor!\n", 20);
  mu_assert("return value of write(5, \"Bad file descriptor!\\n\", 20)",
            ret == -1);
  mu_assert("errno after write(5, \"Bad file descriptor!\\n\", 20)",
            errno == EBADF);

  ret = fct(1, "\n", 1);
  mu_assert("return value of write(1, \"\\n\", 1)", ret == 1);
  errno = 0;
  return 0;
}
