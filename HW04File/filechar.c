// ***
// *** You MUST modify this file, only the ssort function
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_COUNTCHAR
bool countChar(char * filename, int * counts, int size)
{
  // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
  // if fopen succeeds, read every character from the file
  // read one character
  
  FILE * fptr = fopen(filename, "r"); 
  if (fptr == NULL) 
  {
    // fopen fail, handle error
    printf("Could not open file %s\n", filename); 
    return false; 
  }
  int ch;
  while ((ch = fgetc(fptr)) != EOF)
  {
    if (ch >= 0 && ch <= size - 1)
    {
      counts[ch]++;
    }
  }
  fclose(fptr);
  // if a character (call it onechar) is between
  // 0 and size - 1 (inclusive), increase
  // counts[onechar] by one
  // You should *NOT* assume that size is 256
  // reemember to call fclose
  // you may assume that counts already initialized to zero
  // size is the size of counts
  // you may assume that counts has enough memory space
  //
  // hint: use fgetc
  // Please read the document of fgetc carefully, in particular
  // when reaching the end of the file
  //
  return true;
}
#endif

#ifdef TEST_PRINTCOUNTS
void printCounts(int * counts, int size)
{
  // print the values in counts in the following format
  // each line has three items:
  // ind, onechar, counts[ind]
  // ind is between 0 and size - 1 (inclusive)
  // onechar is printed if ind is between 'a' and 'z' or
  // 'A' and 'Z'. Otherwise, print space
  // if counts[ind] is zero, do not print
  
  for (int ind = 0; ind <= size - 1;ind++)
  {
    if (counts[ind] != 0)
    {
      // check if onechar is between az to AZ
      if ((ind >= 'a' && ind <= 'z') || (ind >= 'A' && ind <= 'Z'))
      {
        printf("%d, %c, %d\n", ind, ind, counts[ind]);
      }
      // otherwise print space
      else
      {
        printf("%d,  , %d\n", ind, counts[ind]);
      }
    }
  }
}
#endif
