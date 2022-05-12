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
    bool isPalindrome(ListNode* head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //to get the middle element pointed by slow
        
        ListNode*prev = NULL;
        ListNode*curr=slow;
        ListNode*next;
        
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        //reversed the other half of linked list
        
        //comparing elements
        fast=head;
        while(prev){
            if(prev->val!=fast->val){
                return false;
            }
            prev=prev->next;
            fast=fast->next;
                
        }
        return true;
        
    }
};