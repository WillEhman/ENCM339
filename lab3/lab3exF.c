// ENCM 339 Fall 2016 Lab 3 Exercise F

#include <stdio.h>

int main(void)
{
  char buffer[80];   // enough space for a string of length <= 79

  // THIS IS A GOOD WAY TO LEARN SOMETHING ABOUT C STRINGS, BUT IT'S
  // NOT A GOOD EXAMPLE OF READABLE OR PRACTICAL CODE! 

  // Put characters into the string using ASCII codes.
  buffer[0] = 40;
  buffer[1] = 52;
  buffer[2] = 50;
  buffer[3] = 32;
  buffer[4] = 124;
  buffer[5] = 124;
  buffer[6] = 32;
  buffer[7] = 48;
  buffer[8] = 41;
  buffer[9] = 32;
  buffer[10] = 38;
  buffer[11] = 38;
  buffer[12] = 32;
  buffer[13] = 45;
  buffer[14] = 51;
  buffer[15] = 32;
  buffer[16] = 104;
  buffer[17] = 97;
  buffer[18] = 115;
  buffer[19] = 32;
  buffer[20] = 97;
  buffer[21] = 32;
  buffer[22] = 118;
  buffer[23] = 97;
  buffer[24] = 108;
  buffer[25] = 117;
  buffer[26] = 101;
  buffer[27] = 32;
  buffer[28] = 111;
  buffer[29] = 102;
  buffer[30] = 32;
  buffer[31] = 49;
  buffer[32] = 46;

  // Put the end-of-string character at the end of the string.
  buffer[33] = 0;

  printf("The string in buffer is \"%s\"\n", buffer);
  return 0;
}
