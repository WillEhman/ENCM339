// ENCM 339 Fall 2016 Lab 3 Exercise B

// IMPORTANT REMARK
//
//   For the most part in ENCM 339 we'll avoid using array syntax
//   to declare function parameters, because doing so is misleading
//   about types.  In other words, this is preferred ...
//
//       void foo(int *a, int n);
//
//   ... and this is not recommended ...
//
//       void foo(int a[], int n);
//
//   But in this exercise we'll use array syntax, just to emphasize
//   the fact that with a function parameter, asking for an array
//   type gets you a pointer type.

#include <stdio.h>

void fail2copy(double dest[], double src[]);

void copy(double dest[], const double src[], size_t n);

double bad_sum(const double x[4]);

int main(void)
{
  double mars[3];
  double saturn[3] = { 0.25, 0.75, 1.25 };
  double sum_mars;
  size_t size_mars;

  size_mars = sizeof(mars);
  printf("The number of elements in the array mars is %zu.\n",
	 size_mars / sizeof(double));

  // point one

  fail2copy(mars, saturn); 
  copy(mars, saturn, 3);
  sum_mars = bad_sum(mars);
  printf("This program thinks that the sum of the "
	 "elements in mars is %f.\n", sum_mars);
  return 0;
} 

void fail2copy(double dest[], double src[])
{
  // If you don't know C well, you might think this
  // function copies an array.  IT DOES NOT!

  dest = src;

  // point two

  return;
}

void copy(double dest[], const double src[], size_t n)
{
  size_t i;
  for (i = 0; i < n; i++)
    dest[i] = src[i];

  // point three

  return;
}

double bad_sum(const double x[3])
{
  // ATTENTION: Putting 3 between the square brackets beside arg does
  // NOTHING to change the type of x--the type of arg is
  // pointer-to-const-double.  This style is even worse than declaring
  // a function parameter with empty square brackets!

  size_t size_x, element_count, i;
  double sum = 0.0;

  // DEFECTIVE attempt to find the number of array elements ...
  size_x = sizeof(x);
  element_count = size_x / sizeof(double);

  for (i = 0; i < element_count; i++)
    sum += x[i];

  // point four

  return sum;
}
