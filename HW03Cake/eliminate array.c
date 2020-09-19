// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }

  // initialize all elements
  // array: array_index,count_num
  int array[] = {};
  for (int i = 0;i < n;i++)
  {
    array[i][0] = i;
    array[i][1] = 0;
  }
  for (int x = 0;x < n;x++)  
    for (int y = 0;y < n;y++)  
    {
        printf("%d",array[x][y]);
    }
  while (sizeof(array) != 1)
  {
    assignCountNum(array,n,k);
    removeElement(array,n,k);
  }
  //printf("enter the element of an array \n");
  //for (j = 0; j < n+1; i++)
  //  scanf("%d", &array[i]);

  // release the memory of the array
  free (arr);
}
void assignCountNum(int* array, int n, int k)
{

  int last_count = array[(n-1)][1];
  int current_count = last_count + 1;
  array[0][0] = current_count;
  for (int q = 0;q < n;q++)
  {
    if (current_count <= k)
      array[q][1] = current_count;
    else
    {
      array[q][1] = 1;
    }
      
  }
  return;
}

void removeElement(int* array, int n, int k)
{
  for (int j = 0;j < n;j++)
  {
    if (array[j][1] == k)
      array[j][1] = array[j+1][1];
  }
  return;
}
#endif

