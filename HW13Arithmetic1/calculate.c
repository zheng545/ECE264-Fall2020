// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calculate.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
// return 1 if the word contains '-'
// ...
int isOperator(char * word)
{
  int ind;
  int numop = sizeof(Operations) / sizeof(int);
  for (ind = 0; ind < numop; ind ++)
    {
    char *loc = strchr(word, Operations[ind]);
    if (loc != NULL && !isdigit(loc[1]))
	{
	  return ind;
	}
    }
  return -1;
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the calculate function
// ***
#ifdef TEST_CALCULATE
// if arithlist is NULL, return true
// if arithlist -> head is NULL, return true
// if the input list is invalid, return false
// If no operator can be found, return false
// If an operator is found, find the two previous nodes as operands
    // If cannot find previous two operands, return false
    // If two operands can be found, perform the arithmetic operation
    
bool calculate(List * arithlist)
{
  if (arithlist == NULL)
  {
    return true;
  }
  if ((arithlist -> head) == NULL)
  {
    return true;
  }
  ListNode * tmp = arithlist -> head;
  int oprand1;
  int oprand2;
  int operator;
  int result;
  // go through the list until there is only node in the list
  // find the next operator
  while ((tmp != NULL) && (arithlist -> head != arithlist -> tail))
  {
    operator = isOperator(tmp -> word);
    //if find operand, contionue to find operator
    //if (operator == -1){tmp = tmp -> next;}
    //if find operator, do calculation
    if (operator != -1) 
    {
      //if cannot find two operands before operator
      ListNode * tmpPrev = tmp -> prev;
      if (tmpPrev == NULL){return false;}
      ListNode * tmpPrev2 = tmpPrev -> prev;
      if (tmpPrev2 == NULL){return false;}
      oprand1 = (int)strtol(tmpPrev -> word,NULL,10);
      oprand2 = (int)strtol(tmpPrev2 -> word,NULL,10);
      switch(operator) 
      {
        case 0 :
          result = oprand2 + oprand1;
          break;
	
        case 1 :
          result = oprand2 - oprand1;
          break;

        case 2 :
          result = oprand2 * oprand1;
          break;
      }
      // Be careful, subtraction is no commutative: 4 2 - means 4 - 2,
      //    not 2 - 4
      // After the operation,
      //     put the result back to the list
      //     remove the two nodes used to store the two operands
      deleteNode(arithlist,tmpPrev);
      deleteNode(arithlist,tmpPrev2);
      sprintf(tmp -> word, "%d\n", result);
    }
    tmp = tmp -> next;
  }
  // After going through the entire list and performing the operations,
  //     the list should have exactly one node left. If this is not
  //     true, return false
  // if more than one node left, return false
  if (arithlist -> head != arithlist -> tail){return false;}
  // if the remaining node is an operator, return false
  if (isOperator(arithlist -> head -> word) != -1){return false;}
  // If the input is valid, return true
  // if everything is OK, return true
  
  return true;
}
#endif
