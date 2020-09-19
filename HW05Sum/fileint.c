// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_ADDFILE
bool addFile(char * filename, int * sum)
{
  // You cannot assume * sum is zero. Thus, * sum needs to be set 0
  * sum = 0;
  
  // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
  // if fopen succeeds, read integers using fscan (do not use fgetc)
  
  FILE * fptr = fopen(filename, "r"); 
  if (fptr == NULL) 
  {
    // fopen fail, handle error
    // Do NOT fclose }
    printf("Could not open file %s\n", filename); 
    return false;  
  }
  int val;
  while (fscanf(fptr, "%d", & val) == 1)
  {
    (* sum) += val;
  }
  fclose(fptr);
  // * sum stores the result of adding all numbers from the file
  // When no more numbers can be read, fclose, return true
  //
  return true;
}
#endif

#ifdef TEST_WRITESUM
bool writeSum(char * filename, int sum)
{
  // open a file whose name is filename for writing
  // if fopen succeeds, write sum as an integer using fprintf
  // fprintf should use one newline '\n'
  // fclose, return true
  FILE * fptr = fopen(filename, "w"); 
  if (fptr == NULL) 
  {
    // fopen fail, handle error
    // Do NOT fclose }
    printf("Could not open file %s\n", filename); 
    return false;  
  }
  fprintf(fptr,"%d",sum);
  fclose(fptr);
  return true;
}
#endif
