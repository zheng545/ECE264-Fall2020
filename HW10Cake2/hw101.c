// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include "hw10.h"

// DO NOT MODIFY this function --->>>
void printListNode(ListNode * head)
{
  ListNode * p = head;
  printf("printListNode: ");
  while (p != NULL)
    {
      printf("%7d ", p -> value);
      p = p -> next;
    }
  printf("\n");
}
// <<<--- until here

// You MUST modify the following functions

#ifdef TEST_CREATELIST
// create a linked list storing values 0, 1, 2, ... valn - 1
// The first node (head) stores 0, the next node stores 1,
// ..., the last node stores valn - 1
// return the head of the linked listn
ListNode * createList(int valn)
{
  ListNode * head = malloc(sizeof(ListNode));
  int order = valn-1;
  head -> value = order;
  head -> next = NULL;
  order--;
  while (order >= 0)
  {
    // create new node
    ListNode * tmp = malloc(sizeof(ListNode));
    // assign value to new node
    // 
    tmp -> value = order;
    tmp -> next = head;
    head = tmp;
    order--;
  }
  return head;
}
#endif

#ifdef TEST_ELIMINATE
// eliminate the nodes in the linked list
// starting from the head, move one node at a time and count to valk.
// eliminate that node, keep counting
//
// when reaching the end of the list, continue from the beginning of
// the list
//
// print the values of the nodes to be deleted
void eliminate(ListNode * head, int valk)
{
  int count = 1;
  if (head == NULL){return;}
  // count from the head of linked list
  ListNode * tracker = head;
  while (head -> next != NULL)
  {
    count = 1;
    while (count != valk)
    {
      ListNode * currentHead = tracker -> next;
      if (tracker != NULL){count++;}
      if (count == valk)
      {
#ifdef DEBUG
  // this #ifdef ... #endif should be inside the condition *BEFORE* a
  // node' value is printed and it is deleted
        ListNode * todelete = tracker;
        printListNode (todelete); 
#endif
        printf("%d\n",todelete -> value);
        deleteNode(head,todelete);
        if (currentHead != NULL){tracker = currentHead;}
        else {tracker = head;}
      }
    }
  }
  printf("%d\n",head -> value);
  free(head);
}
#endif

#ifdef TEST_DELETENODE
// head points to the first node in the linked list
// todelete points  to the node to be deleted
//
// delete the node and return the head of the linked list
// release the memory of the deleted node
//
// should check several conditions:
// 1. If head is NULL, the list is empty and this function returns
//    NULL
// 2. If todelete is NULL, nothing can be deleted, return head
// 3. If todelete is not in the list, keep the list unchanged and
//    return head
// It is possible that todelete is the first node in the list (i.e.,
// the head). If this occurs, return the second node of the list.
ListNode * deleteNode(ListNode * head, ListNode * todelete)
{
  // new variable to start from head, keep head unchanged
  ListNode * p = head; 
  ListNode * q = todelete; 
  if (p == NULL){return NULL;}
  if (q == NULL){return head;}
  // first case: deleted node at beginning of list
  if (q == p)
  {
    p = head -> next;
    free(head);
    return p;
  }
  while ((p != NULL) && (p -> next != todelete))
   {
     p = p -> next;
   }
  if (p != NULL)
    {
      p -> next = q -> next;
      free(q);
    }
  return p;
}
#endif


