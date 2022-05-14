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
    
     ListNode* reverse(ListNode* head)
    {
        ListNode *curr=head;
        ListNode *prev=NULL;
        ListNode *next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if(!head) return;
        
        //step 1 - find mid of list
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //step 2 - reverse the second half and split the list into two
        ListNode*second = reverse(slow->next);
        slow->next=NULL;
        ListNode*first = head;
        
        
        //step 3 - merging the two list
        //second list can be shorter when LL size is odd    
        while(second){
            ListNode*tmp1 = first->next;
            ListNode*tmp2 = second->next;
            
            first->next = second;
            second->next = tmp1;
            
            first = tmp1;
            second = tmp2;
        }
        
        
    }
};