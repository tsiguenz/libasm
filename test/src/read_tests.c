#include "../include/test.h"

#define fct ft_read

char *read_tests() {
  char str[1000] = {0};
  ssize_t ret = 0;
  int fd;

  fd = open("src/read_tests.c", O_RDONLY);

  ret = fct(fd, str, 8);
  mu_assert("return value of read(fd, str, 8)", ret == 8);
  mu_assert("str after read(fd, str, 8)", strcmp(str, "#include") == 0);
  mu_assert("errno after read(fd, str, 8)", errno == 0);

  ret = fct(-1, str, 42);
  mu_assert("return value of read(-1, str, 42)", ret == -1);
  mu_assert("errno after read(-1, str, 42)", errno == EBADF);
  mu_assert("str after read(-1, str, 42)", strcmp(str, "#include") == 0);
  errno = 0;

  ret = fct(fd, str, 1000);
  mu_assert("return value of read(fd, str, 1000)", ret <= 1000 && ret != -1);
  mu_assert("errno after read(fd, str, 1000)", errno == 0);

  // TODO(tsiguenz): same as write
  ret = fct(fd, NULL, 42);
  mu_assert("return value of read(fd, NULL, 42)", ret == -1);
  mu_assert("errno after read(fd, NULL, 42)", errno == EFAULT);

  close(fd);
  errno = 0;
  return 0;
}
