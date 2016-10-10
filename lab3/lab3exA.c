// ENCM 339 Fall 2016 Lab 3 Exercise A

#include <stdio.h>

void copy_str(char *dest, const char *src);
// Like the C library function strcpy, but does not return a value.

int main(void)
{
  char foo[4] = { 'A', 'B', 'C', 'D' };
  char bar[4];
  copy_str(foo, "XY");
  copy_str(bar, foo);
  return 0;
}

void copy_str(char *dest, const char *src)
{
  int k = 0, c;
  do {
    c = src[k];
    dest[k] = c;
    k++;
  } while (c != '\0');

  // point one

  return;
}
