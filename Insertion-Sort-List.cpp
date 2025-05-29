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
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr || head->next == nullptr){
            return head;
        }

        ListNode  * sortedlist  = new ListNode(head->val);
        ListNode * curr = head->next;
        while(curr!=nullptr){
            if(curr->val <sortedlist->val){
                ListNode * newfirst = new ListNode(curr->val);
                newfirst->next  = sortedlist;
                sortedlist =newfirst;
            }
            else{
                ListNode * first  = sortedlist;
                ListNode * prev = sortedlist->next;
                while(1){
                   if(prev==nullptr || curr->val<prev->val){
                    ListNode * newnode = new ListNode(curr->val);
                    newnode->next=first->next;
                    first->next=newnode;
                    break;
                   }else{
                    first =first->next;
                    prev=prev->next;
                   }
                }


            }
            curr=curr->next;
        }
        return sortedlist;
    }
};