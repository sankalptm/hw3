#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  //simply change the pointers for each of the Nodes that are given
  if (head==NULL){
    smaller=NULL;
    larger=NULL;
    head=NULL;
    return;
  }
  llpivot(head->next, smaller, larger, pivot);
  int current=head->val;
  if (current<= pivot){
    head->next=smaller;
    smaller=head;
  }
  else {
    head->next=larger;
    larger= head;
  }
  head=NULL;








}
