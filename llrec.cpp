#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot)
{
	if(head!=NULL)
	{
		Node*& temp_next=head->next;
		if(head->val<=pivot)
		{
			smaller=head;
			if(&head!=&smaller && (&head!=&larger))
			// if head pointer is not in the list (ei the first head pointer) 
			{
			head=nullptr;
			}
			
			llpivot (temp_next,smaller->next,larger,pivot);

		}else{
			larger=head;
			if(&head!=&larger && (&head!=&smaller)) 
			// if head pointer is not in the list (ei the first head pointer)
			{
				head=nullptr;
			}

			llpivot (temp_next,smaller,larger->next,pivot);
		}	
	} else	{
		smaller=nullptr;
		larger=nullptr;
	}
	return;

}
