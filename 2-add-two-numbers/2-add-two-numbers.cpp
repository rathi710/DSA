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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {    
        int sum=0, c=0;
        
        ListNode *tmp;
        ListNode *head = NULL;
        ListNode *curr = NULL;
            
        while(l1 or l2){
            sum = c + (l1?l1->val:0) + (l2?l2->val:0);
            c = (sum>=10)?1:0;
            sum = sum%10;
            
            tmp = new ListNode(sum);
            if(head==NULL) head = tmp;
            else curr->next = tmp;
            
            curr = tmp;
            // Switch to next Node if it's possible
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            
        }
        // In case carry still exist - create new Node with addition value
        if(c>0){
            tmp = new ListNode(c);
            curr->next = tmp;
            curr = tmp;
        }
    
        return head;
    }
};


