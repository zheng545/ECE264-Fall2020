// ***
// *** You MUST modify this file, only the ssort function
// ***

#include "sort.h"
#include <stdio.h>
void swap(int*,int*);

// DO NOT MODIFY THIS FUNCTION
bool checkOrder(int * arr, int size)
// This function returns true if the array elements are
// in the ascending order.
// false, otherwise
{
  int ind;
  for (ind = 0; ind < (size - 1); ind ++)
    {
      if (arr[ind] > arr[ind + 1])
	{
	  return false;
	}
    }
  return true;
}


// YOU MUST MODIFY THIS FUNCTION
#ifdef TEST_SORT
void ssort(int * arr, int size)
{
  int i; //in the first level of for to specify which element in array
  int j; //in the second level of for to find the smallest element	
  int min; //the flag minimum value used to compared 
  
  for (i = 0; i < size - 1; i++)
  {
    min = i; 	//set the first element in unsorted array as the flag
    for (j = i + 1; j < size; j++)
    {
      if (arr[j] < arr[min])
          min = j;	//find the smallest element in array
    } 
    if (i != min)	//swap the smallest element to the first place
       swap(&arr[i], &arr[min]);
   } 
   
   return;
}

void swap(int* num1, int* num2) 
{
   int hold;
   hold = *num1; 
   *num1 = *num2; 
   *num2 = hold;

   return; 
}
#endif
