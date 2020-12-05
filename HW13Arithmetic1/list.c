// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#ifdef TEST_READLIST
// read line by line from the input file
// each line shorter than WORDLENGTH (including '\n' and '\0')
// arithlist should have memory to store head and tail
// If arithlist is NULL, return false
// If fopen fails, return false
// If a line is too long,
//    free memory of the list
//    fclose
//    return false
// If everything is fine
//    fclose
//    arithlist points to the head and tail of the list
//    return true
bool readList(char * filename, List * arithlist)
{
  	FILE * fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		return false;
	}
	char  word[WORDLENGTH];
	while (fgets(word,sizeof(word),fptr) != NULL)
  	{
    		if (strchr(word,'\n') == NULL)
    		{
     			fclose(fptr);
      			deleteList(arithlist);
      			return false;
    		}
    		addNode(arithlist,word);
	}
	fclose(fptr);
	return true;
}
#endif

#ifdef TEST_DELETELIST
// If arithlist is NULL, do nothing
// release the memory of every node in the list
// release the memory of the list 
void deleteList(List * arithlist)
{	
	if (arithlist == NULL)
	{return;}
	while (arithlist -> head != NULL)
	{
		ListNode * p = arithlist -> head -> next;
		free (arithlist -> head);
		arithlist -> head = p;
	}
	free(arithlist);
	return;
}
#endif

#ifdef TEST_ADDNODE
// Input: 
// arithlist stores the addresses of head and tail
// If arithlist is NULL, do nothing
// word is the word to be added
//
// Output:
// a ListNode is added to the end (become tail)
//
// allocate memory for a new ListNode
// copy word to the word attribute of the new ListNode
// insert the ListNode to the list
void addNode(List * arithlist, char * word)
{
	if (arithlist == NULL)
	{return;}
	ListNode * q = malloc(sizeof(ListNode));
	strcpy(q -> word, word);
	q -> prev = NULL;
	q -> next = NULL;
	if (arithlist -> head == NULL)
	{
		arithlist -> head = q;
		arithlist -> tail = q;
	}
	else
	{
		q -> prev = arithlist -> tail;
		arithlist -> tail -> next = q;
		arithlist -> tail = q;
	}
	return;
}
#endif

#ifdef TEST_DELETENODE
//  Input:
// arithlist stores the addresses of head and tail
// If arithlist is NULL, return false
// If the list is empty (head and tail are NULL), return false
// ln is the node to be deleted
// If ln is not in the list, return false
// 
// Output:
// arithlist stores the addresses of head and tail
//   after ln is deleted
// return true.
//
// Be careful about delete the first or the last node
bool deleteNode(List * arithlist, ListNode * ln)
{
	if (arithlist == NULL)
	{return false;}
	if (arithlist -> head == NULL && arithlist -> tail == NULL)
	{return false;}
	ListNode * h = arithlist -> head;
	//ListNode * t = arithlist -> tail;
	while ((h != NULL) && (h != ln)){h = h -> next;}//new
	if (h == NULL){return false;} //#####new add
	if (ln == arithlist -> head)
	{	
		ListNode * r = arithlist -> head -> next;
    	if (r != NULL)
    	{
      		r -> prev = NULL;
    	}
		free (arithlist -> head);
		arithlist -> head = r;
		if (arithlist -> head == NULL){arithlist -> tail = NULL;}
		return true;
	}
	//edit !!!!!!
	else if (ln == arithlist -> tail)
	{
		ListNode * r = arithlist -> tail -> prev;
    	if (r != NULL)
    	{
      		r -> next = NULL;
    	}
		free (arithlist -> tail);
		arithlist -> tail = r;
		if (arithlist -> tail == NULL){arithlist -> head = NULL;}
		return true;
	}
	h -> next -> prev = h -> prev;
  	h -> prev -> next = h -> next;
  	free(h);
  	return true;
}
#endif

