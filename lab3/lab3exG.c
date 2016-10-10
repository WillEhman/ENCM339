// ENCM 339 Fall 2016 Lab 3 Exercise G

#include <stdio.h>
#include <string.h>

int safecat(char *dest, const char* src, size_t dest_size);
// REQUIRES
//    Array elements dest[0] ... dest[dest_size-1] exist.
//    dest points to the beginning of a C string.
//    src points to the beginning of a C string.
// PROMISES
//    If the sum of the length of the two strings are less than
//    dest_size, the string in the dest array is the concatenation
//    of the original string in dest and the string from src, and
//    the return value is the length of the new string.
//
//    If not, the string in dest is the concatenation of the original
//    string in dest and as many characters from src as possible,
//    while leaving room for '\0' in dest[dest_size-1], and the return
//    value is -1.

int main(void)
{
  int rv;
  char buf[10];

  buf[0] = '\0';
  rv = safecat(buf, "", 10);
  printf("buf contains \"%s\" and rv is %d (expect \"\" and 0).\n",buf, rv);
  rv = safecat(buf, "abcde", 10);
  printf("buf contains \"%s\" and rv is %d (expect \"abcde\" and 5).\n", buf, rv);
  rv = safecat(buf, "fghi", 10);
  printf("buf contains \"%s\" and rv is %d (expect \"abcdefghi\" and 9).\n", buf, rv);  // Note correction in above line.
  
  buf[0] = '\0';
  rv = safecat(buf, "jkl", 10);
  printf("buf contains \"%s\" and rv is %d (expect \"jkl\" and 3).\n",buf, rv);
  rv = safecat(buf, "mnopqrs", 10);
  printf("buf contains \"%s\" and rv is %d (expect \"jklmnopqr\" and -1).\n", buf, rv);
  
  buf[0] = '\0';
  rv = safecat(buf, "01", 10);
  printf("buf contains \"%s\" and rv is %d (expect \"01\" and 2).\n",buf, rv);  // Note correction in above line.
  rv = safecat(buf, "2345", 10);
  printf("buf contains \"%s\" and rv is %d (expect \"012345\" and 6).\n",buf, rv);
  rv = safecat(buf, "6789ABCDEF", 10);
  printf("buf contains \"%s\" and rv is %d (expect \"012345678\" and -1).\n", buf, rv);
  
  return 0;
}

int safecat(char *dest, const char* src, size_t dest_size)
{
    int destlen = strlen(dest);
	int i = strlen(dest);
	for (int j = 0;/*src[j] != '\0' || */i<dest_size-1;++j, ++i)
	{
		dest[i]=src[j];
	}

   dest[i]='\0';
   
   //Return values work as intended
   if (dest_size < strlen(src)+destlen)
   {
	   return -1;
   }
   else if (dest_size >= strlen(src)+destlen)
   {
	   return strlen(dest);
   }
   return 0;
}
