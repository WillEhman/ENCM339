// ENCM 339 Fall 2016 Lab 3 Exercise E

#include <stdio.h>

void display_array(const char* label, const double* x, size_t n);
// REQUIRES
//    label points to the beginning of a string.
//    Elements x[0], ... x[n-1] exist.
// PROMISES
//    label is printed, followed by values of  x[0], ... x[n-1], all on
//    one line, using %4.2f format for the doubles. If n == 0, the line
//    of output points out that fact. 

void reverse(double* x, size_t n);
// REQUIRES
//     n > 0.
//     Array elements x[0] ... x[n - 1] exist.
// PROMISES
//     Order of elements x[0] ... x[n - 1] has been reversed.
//     (So the new x[0] value is the old x[n - 1] value, and so on.)

int increasing(const double* x, size_t n);
// REQUIRES
//     n > 0.
//     Array elements x[0] ... x[n - 1] exist.
// PROMISES
//     Return value is 1 if n == 1.
//     If n > 1, return value is 1 if all of a[0] < a[1] ... a[n-2] < a[n-1] 
//     are true, otherwise return value is 0.


// In Step 3, add a function prototype and function interface comment
// for min_element here.
double min_element(const double* x, size_t n);
// REQUIRES
//     n > 0.
//     Array elements x[0] ... x[n - 1] exist.
// PROMISES
//     Returns value (double) of minimum element in array x



int main(void)
{
  double test1[ ] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double test2[ ] = {-0.5, -1.0, -1.5, -2.0, -2.5, -3.0};

  printf("Some quick checks of display_array ...\n");
  display_array("  all of test1:", test1, 5);
  display_array("  none of test1:", test1, 0);
  display_array("  last 3 elements of test1:", &test1[2], 3);
  display_array("  all of test2:", test2, 6);

  printf("\nTwo tests of reverse ...\n");
  reverse(test1, 5);
  display_array("  test1 after reversing:", test1, 5);
  reverse(test2, 6);
  display_array("  test2 after reversing:", test2, 6);

  double test3[ ] = {1.5, 1.25, 2.5, 3.5, 4.5, 5.5, 5.25};
  double test4[ ] = {1.0, 2.0, 3.0, 3.0, 4.0, 5.0};
  int inc;
  printf("\nSome tests of increasing ...\n");
  display_array("  for these numbers:", test3, 6);
  inc = increasing(test3, 6);
  printf("  expected return value is 0, actual value is %d\n\n", inc);
  display_array("  for these numbers:", &test3[1], 5);
  inc = increasing(&test3[1], 5);
  printf("  expected return value is 1, actual value is %d\n\n", inc);
  display_array("  for these numbers:", &test3[1], 6);
  inc = increasing(&test3[1], 6);
  printf("  expected return value is 0, actual value is %d\n\n", inc);
  display_array("  for these numbers:", test4, 6);
  inc = increasing(test4, 6);
  printf("  expected return value is 0, actual value is %d\n\n", inc);

  // In Step 3, add some tests for max_element here.
  double test5[ ] = {-1.5, -1.25, -2.5, -2.0, -4.5, -5.5, -5.25};
  double test6[ ] = {1.0, 2.0, 3.0, 3.1, 0.5, 4.5};
  double test7[ ] = {-5.0,-1.0,20.0};
  double test8[ ] = {-5.0,5.0,-20.0};
  double min;
  printf("Four tests of minimum ...\n");
  display_array("  for these numbers:", test5, 7);
  min = min_element(test5,7);
  printf("  expected return value is -5.500000, actual value is %f\n\n", min);
  display_array("  for these numbers:", test6, 6);
  min = min_element(test6,6);
  printf("  expected return value is 0.500000, actual value is %f\n\n", min);
  display_array("  for these numbers:", test7, 3);
  min = min_element(test7,3);
  printf("  expected return value is -5.000000, actual value is %f\n\n", min);
  display_array("  for these numbers:", test8, 3);
  min = min_element(test8,3);
  printf("  expected return value is -20.000000, actual value is %f\n\n", min);


  return 0;
}

void display_array(const char* label, const double * x, size_t n)
{
  size_t i ;
  printf("%s", label);
  if (n == 0)
    printf("  [no contents to print]\n");
  else {
    for(i = 0; i < n ; i++)
      printf(" %4.2f", x[i] );
    printf("\n");
  }
}

void reverse(double* x, size_t n)
{
  double stored[n];
	for (int i=0;i<n;i++)
	{
		stored[i]=x[n-1-i];
	}
	for (int i=0;i<n;i++)
	{
		x[i]=stored[i];
	}
}

int increasing(const double* x, size_t n)
{
	if(n==1)
	{
		return 1;
	}
	int flag[n];
	
	for (int i=1;i<n;i++)
	{
		if (x[i]>x[i-1]) 
		{
		  flag[i-1]=1; 
		}
		else
		{
		  flag[i-1]=0;
		}
		flag[n-1]=1;
		
	}
	
	for (int i=0;i<n;i++)
	{
		if (flag[i] == 0) //if any flag array value is 0, break and return false
		{
			return 0;
		}
		else if (flag[i] == 1 && i == n-1) // if last flag array value is one, return true
		{
			return 1;
		}
	}
    return 0;
}

double min_element(const double* x, size_t n)
{
	double minimum = x[0]; //intialize minimum as first index of array (will change unless first index is minimum)
	for (int i=1;i<n;i++)
	{
		if (x[i] < minimum) //if next element is less than the first
		{
			minimum = x[i]; //replace minimum with this element and move on
		}
	}
	return minimum; //return lowest element
}


//End of code