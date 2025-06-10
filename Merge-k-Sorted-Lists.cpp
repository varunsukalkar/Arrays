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
   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if( lists.size()==0){
            return nullptr;
        }
    typedef pair<int,ListNode*>p;
    priority_queue<p,vector<p>,greater<p>>pq;
    
    for(int i = 0 ; i< lists.size(); i++){
        if(lists[i]!=nullptr)
        pq.push({lists[i]->val,lists[i]});

    }
    ListNode * dummynode = new ListNode(-1);
    ListNode * temp = dummynode;
     while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        ListNode * node = it.second;
         temp->next = node;
         temp=temp->next;
         if(node->next){
            pq.push({node->next->val,node->next});
         }
     }
     return dummynode->next;
    }
   
};