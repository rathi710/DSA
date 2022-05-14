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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(!head || !head->next || left==right) return head;   //edge cases
        
        ListNode *dummy = new ListNode(-1);  //to make things easier(less edge case handling)
        dummy->next = head;
        
        ListNode *pre_it = NULL;
        ListNode *it = dummy;
        
        //traverse till left index
        for(int i=0;i<left;i++){
            pre_it = it;
            it = it->next;
        }                     
        //after this pre_it is at previous of left;
        //it is at left
        
        //reverse
        ListNode *pre_R = pre_it;     //pointer change to preserve the address 
        ListNode *itR = it;
        ListNode *next;
        
        for(int i=left; i<=right; i++){
            next = itR->next;
            itR->next  = pre_R;
            pre_R = itR;
            itR = next;
        }
        //after this itR is one ahead of right
        //prev_R is at right
        
        //making last connections
         it->next = itR;
        pre_it->next = pre_R;
       
        
        return dummy->next;       //returning head
        
    }
};

