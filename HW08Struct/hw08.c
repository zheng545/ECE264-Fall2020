// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw08.h"


#ifdef TEST_COUNTVECTOR
int countVector(char * filename)
{
  // For the mode of fopen, you may use "r" without b
  FILE * fptr = fopen(filename,"r");
  if (fptr == NULL) 
  {
    // fopen fail, handle error
    // Do NOT fclose }
    printf("Could not open file %s\n", filename); 
    return -1;  
  }
  // count the number of vectors in the file and return the number
  // The input is a binary file. You must use fread.
  // You must not use fscanf(, "%d", ) 
  fseek(fptr, 0, SEEK_END);
  int numElem = ftell(fptr)/12;
  fclose(fptr);
  return numElem;
}
#endif

#ifdef TEST_READVECTOR
bool readVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  // read Vectors from the file.
  FILE * fptr = fopen(filename,"r");
  if (fptr == NULL) 
  {
    // fopen fail, handle error
    // Do NOT fclose }
    printf("Could not open file %s\n", filename); 
    return -1;  
  }
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  int numRead = 0;
  numRead = fread(& vecArr[0], sizeof(Vector), size, fptr);
  if (numRead != size)
  {
    return false;
  }
  // if everything is fine, fclose and return true
  fclose(fptr);
  return true;
}
#endif

#ifdef TEST_COMPAREVECTOR
int compareVector(const void *p1, const void *p2)
{
  // compare the x attribute first
  // If the first vector's x is less than the second vector's x
  // return -1
  // If the first vector's x is greater than the second vector's x
  // return 1
  // If the two vectors' x is the same, compare the y attribute
  const Vector* ptr1 = (const Vector*) p1;
  const Vector* ptr2 = (const Vector*) p2;
  int val1 = ptr1 -> x;
  int val2 = ptr2 -> x;
  if (val1 < val2) {return -1;}
  if (val1 > val2) {return 1;}
  
  // If the first vector's y is less than the second vector's y
  // return -1
  // If the first vector's y is greater than the second vector's y
  // return 1
  val1 = ptr1 -> y;
  val2 = ptr2 -> y;
  if (val1 < val2) {return -1;}
  if (val1 > val2) {return 1;}
  
  // If the two vectors' y is the same, compare the z attribute
  // If the first vector's z is less than the second vector's z
  // return -1
  // If the first vector's z is greater than the second vector's z
  // return 1
  val1 = ptr1 -> z;
  val2 = ptr2 -> z;
  if (val1 < val2) {return -1;}
  if (val1 > val2) {return 1;}
  return 0;
  // If the two vectors' x, y, z are the same (pairwise), return 0
}
#endif

#ifdef TEST_WRITEVECTOR
bool writeVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  FILE * fptr = fopen(filename,"w");
  if (fptr == NULL) 
  {
    // fopen fail, handle error
    // Do NOT fclose }
    printf("Could not open file %s\n", filename); 
    return -1;  
  }
  // write the array to file using fwrite
  fwrite(vecArr, 12, size, fptr);
  // need to check how many have been written
  int nextByte = fgetc(fptr);
  // if not all are written, fclose and return false
  if (nextByte != EOF)
  {
    fclose(fptr);
    return false;
  }
  fclose(fptr);
  return true;
  // fclose and return true
}
#endif

// This function is provided to you. No need to change
void printVector(Vector * vecArr, int size)
{
  int ind = 0;
  for (ind = 0; ind < size; ind ++)
    {
      printf("%6d %6d %6d\n",
	     vecArr[ind].x, vecArr[ind].y, vecArr[ind].z);
    }
}
