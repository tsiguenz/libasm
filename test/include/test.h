#ifndef TEST_H
#define TEST_H

// minunit tester: https://jera.com/techinfo/jtns/jtn002
#define mu_assert(message, test)                                               \
  do {                                                                         \
    if (!(test))                                                               \
      return message;                                                          \
  } while (0)

#define mu_run_test(test)                                                      \
  do {                                                                         \
    char *message = test();                                                    \
    tests_run++;                                                               \
    if (message)                                                               \
      return message;                                                          \
  } while (0)

extern int tests_run;

#define DEFAULT "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// libasm functions to test
extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strdup(const char *s);

char *strlen_tests();
char *strcpy_tests();
char *strcmp_tests();
char *write_tests();
char *read_tests();
char *strdup_tests();

#endif // TEST_H
