// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw09.h"

// DO NOT MODIFY --->>>> From Here
// Do not modify this function. It is used for grading.
void printInput(char * msg, int * arr, int l, int m, int r)
{
  printf("%s(%6d, %6d, %6d)", msg, l, m, r);
  int ind;
  for (ind = l; ind <= r; ind ++)
    {
      printf("%d\n", arr[ind]);
    }
}
// DO NOT MODIFY <<<<--- Until Here

#ifdef TEST_READDATA
// the input file is binary, storing integers
//
// arr stores the address of a pointer for storing the
// address of the allocated memory
//
// size stores the address keeping the size of the array
bool readData(char * filename, int * * arr, int * size)
{
  // use fopen to open the file for read
  // return false if fopen fails
  FILE * fptr = fopen(filename,"r");
  if (fptr == NULL) 
  {
    // fopen fail, handle error
    // Do NOT fclose }
    return false;  
  }
  // use fseek to go to the end of the file
  // check whether fseek fails
  // if fseek fails, fclose and return false
  int check = fseek(fptr, 0, SEEK_END);
  if (check != 0)
  {
    fclose(fptr);
    return false;
  }
  // use ftell to determine the size of the file
  int numSize = ftell(fptr);
  // use fseek to go back to the beginning of the file
  // check whether fseek fails
  // if fseek fails, fclose and return false
  check = fseek(fptr, 0, SEEK_SET);
  if (check != 0)
  {
    fclose(fptr);
    return false;
  }
  // the number of integers is the file's size divided by
  // size of int  
  int arrSize = numSize / sizeof(int);
  // allocate memory for the array
  // if malloc fails, fclose and return false
  int *intArr = malloc((arrSize) * sizeof(*intArr));
  if (intArr == NULL) 
  {
    fclose(fptr);
    return false;
  }
  // use fread to read the number of integers in the file
  int numRead = 0;
  numRead = fread(& intArr[0], sizeof(int), arrSize, fptr);
  if (numRead != arrSize)
  {
    // if fread does not read the correct number
    // release allocated memory
    // fclose
    // return false
    free(intArr);
    fclose(fptr);
    return false;
  }
  // if fread succeeds
  // close the file
  fclose(fptr);
  // if everything is fine, fclose and return true
  // update the argument for the array address
  *arr = intArr;
  // update the size of the array
  *size = arrSize;
  return true;
}
#endif


#ifdef TEST_WRITEDATA
// the output file is binary, storing sorted integers
// write the array of integers to a file
// must use fwrite. must not use fprintf
bool writeData(char * filename, const int * arr, int size)
{
  // fopen for write
  // if fopen fails, return false
  FILE * fptr = fopen(filename,"w");
  if (fptr == NULL) 
  {
    return false;  
  }
  // use fwrite to write the entire array to a file
  int check = fwrite(arr, sizeof(int), size, fptr);
  // check whether all elements of the array have been written
  // if not all elements have been written, return false  
  if (check != size)
    {
      return false;
    }
  // if all elements have been written, return true
  fclose(fptr);
  return true;
}
#endif


#ifdef TEST_MERGE
// input: arr is an array and its two parts arr[l..m] and arr[m+1..r]
// are already sorted
//
// output: arr is an array and all elements in arr[l..r] are sorted
//
// l, m, r mean left, middle, and right respectively
//
// You can assume that l <= m <= r.
//
// Do not worry about the elements in arr[0..l-1] or arr[r+1..]
static void merge(int * arr, int l, int m, int r)
// a static function can be called within this file only
// a static function is invisible to other files
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge in", arr, l, m, r);
#endif
  if (l > m){return;}
  if (m > r){return;}
  int *tmpArr = malloc(sizeof(*tmpArr)*(r-l+1));
  if (tmpArr == NULL){return;}
  int ind1 = l;
  int ind2 = m + 1;
  int ind3 = 0;
// if one or both of the arrays are empty, do nothing
// Hint: you may consider to allocate memory here.
// Allocating additiional memory makes this function easier to write
// index of three arrays
// merge the two parts (each part is already sorted) of the array
// into one sorted array
  while ((ind1 <= m) && (ind2 <=r))
  {
    if (arr[ind1] >= arr[ind2]) 
    {
      tmpArr[ind3] = arr[ind2]; 
      ind2 ++; 
      ind3 ++;
    }
    else if (arr[ind1] < arr[ind2]) 
    {
      tmpArr[ind3] = arr[ind1]; 
      ind1 ++; 
      ind3 ++;
    }
  }
  while (ind1 <= m){tmpArr[ind3++] = arr[ind1]; ind1++;}
  while (ind2 <= r){tmpArr[ind3++] = arr[ind2]; ind2++;}
  int z = r-l;
  for (int i = 0;i <= z;i++){arr[l] = tmpArr[i];l++;}
  free(tmpArr);
  // the following should be at the bottom of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge out", arr, l, m, r);
#endif
}
#endif

// merge sort has the following steps:

// 1. if the input array has one or no element, it is already sorted
// 2. break the input array into two arrays. Their sizes are the same,
//    or differ by one
// 3. send each array to the mergeSort function until the input array
//    is small enough (one or no element)
// 4. sort the two arrays 
#ifdef TEST_MERGESSORT
void mergeSort(int arr[], int l, int r) 
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("mergeSort", arr, l, r, -1);
#endif
  // if the array has no or one element, do nothing
  if (l > r) { return; } // empty array, nothing to do
  if (l == r) { return; } // only one element, already sorted
  int m = (l + r) / 2;
  mergeSort(arr, l, m);
  mergeSort(arr, m+1, r); // notice + 1
  merge(arr, l, m, r); 
  // divide the array into two arrays
  // call mergeSort with each array
  // merge the two arrays into one
} 
#endif
