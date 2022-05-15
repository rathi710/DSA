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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *prev=dummy;
        
        while(head)
        {
           if(head->next && head->val==head->next->val){
               
               //skipping the duplicate values
               while(head->next && head->val==head->next->val){
                   head=head->next;
               }
               prev->next=head->next;         //connecting prev & head
           }
           else{
                prev=head;
           }
            
            head=head->next;
        }
        
        return dummy->next;              //returning head
        
    }
};