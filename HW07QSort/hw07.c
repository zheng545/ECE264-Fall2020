// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  FILE * fptr = fopen(filename,"r");
  if (fptr == NULL) 
  {
    // fopen fail, handle error
    // Do NOT fclose }
    printf("Could not open file %s\n", filename); 
    return -1;  
  }
  int val;
  int sum = 0;
  while (fscanf(fptr, "%d", & val) == 1)
  {
    sum ++;
  }
  fclose(fptr);
  return sum;
  // count the number of integers in the file
  // Please notice that if a file contains
  // 124 378 -56
  // There are three integers: 124, 378, -56
  // DO NOT count individual character '1', '2', '4' ...
  //
  // If fopen fails, return -1
  // remember to fclose if fopen succeeds
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  FILE * fptr = fopen(filename,"r");
  if (fptr == NULL) 
  {
    // if fopen fails, return false
    // Do NOT fclose }
    printf("Could not open file %s\n", filename); 
    return false;  
  }
  int count = countInt(filename);
  // read integers from the file.
  // 
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  
  int inte;
  int num = 0;
  int ind = 0;
  
  while (fscanf(fptr,"%d",&inte) == 1)
  {
    num ++;
    intArr[ind] = inte;
    ind ++;
  }
  if (num != count)
  {
    return false;
  }
  // if everything is fine, fclose and return true
  fclose(fptr);
  return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  // needed by qsort
  //
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.
  const int * ptr1 = (const int *) p1;
  const int * ptr2 = (const int *) p2;
  int val1 = * ptr1;
  int val2 = * ptr2;
  if (val1 < val2) {return -1;}
  if (val1 == val2) {return 0;}
  return 1;
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  FILE * fptr = fopen(filename,"w");
  // if fopen fails, return false
  if (fptr == NULL) 
  {
    // fopen fail, handle error
    // Do NOT fclose }
    printf("Could not open file %s\n", filename); 
    return false;  
  }
  // write integers to the file.
  // one integer per line
  for (int x = 0;x < size;x++)
  {
    fprintf(fptr,"%d\n",intArr[x]);
  }
  // fclose and return true
  fclose(fptr);
  return true;
}
#endif
