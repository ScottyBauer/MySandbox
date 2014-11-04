#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>


/* Part of this code was taken from John Regehr, during Advanced operating systems */


static void AssertionFailure(char *exp, char *file, int line, const char* format, ... )
{
  printf("Assertion '%s' failed at line %d of file %s\n", exp, line, file);
  printf("Error is %s\n", strerror(errno));
  va_list args;
  va_start(args, format);
  vfprintf(stdout, format, args);
  va_end(args);
  exit(EXIT_FAILURE);
}

#define Assert(exp, format, ...) if (exp) ; else AssertionFailure( #exp, __FILE__,  __LINE__, format, ##__VA_ARGS__ ) 


