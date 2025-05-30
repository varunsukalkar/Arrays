/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode * reverse(ListNode * A){
     ListNode * prev= NULL;
     ListNode * curr = A;
     while(curr!=NULL){
         ListNode * temp = curr->next;
         curr->next = prev ;
         prev=curr;
         curr=temp;

     
     }
     return prev;
 }
 
    void reorderList(ListNode* A) {
      if(A==NULL || A->next==NULL){
        return ;
    }
    ListNode * slow = A;
    ListNode * fast =A;
    while(fast !=NULL && fast->next!=NULL){
        slow=slow->next;
        fast = fast->next->next;
    }
    ListNode * cc = slow->next;
    slow->next = NULL;
    ListNode * head2 = reverse(cc);
    ListNode * curr = A;
    
    
   while(head2!=NULL ){
    ListNode * newnode = curr->next;
    curr->next  = head2;
    head2=head2->next;
    curr=curr->next;
    curr->next = newnode;
    curr=curr->next;
    
   }
 
    
    }
};