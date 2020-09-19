// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 
#define UNDEFINED -1 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements to arr and count
  int * arr = malloc(sizeof(* arr) * n);
  int * count = malloc(sizeof(* count) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }

  // initialize the elements
  for (int i = 0; i < n; i++)
    {
      arr[i] = i;
      count[i] = 0;
    }
  int count_num = 0;		// number count from 1 to k
  int valid_num = n;		// number of valid arr index left


  // eliminate the numbers counting k
  while (valid_num != 1)
  {
      int j = 0;                    // array index process tracking
      while (j < n)
	    {
	      if (arr[j] != UNDEFINED)
	      {
	        count_num += 1;
	        count[j] = count_num;
	      }
	      if (count[j] == k)
	      {
	        count_num = 0;      // restart counting
	        count[j] = 0;       // restart counting number in array
	        arr[j] = UNDEFINED; // use number -1 to mark eliminated number  
	        valid_num -= 1;     // reduce the numbers left in the array
	        printf ("%d\n", j); // printout the eliminated index
	      }
	    j++;
	    }
  }

  // printout the only index left
  for (int z = 0;z < n;z++)
  {
    if (arr[z] != UNDEFINED)
      printf("%d\n",arr[z]);
  }
  // release the memory of the arr
  free (arr);
  free (count);
}
#endif
