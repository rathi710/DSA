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
    
    ListNode *solve(ListNode *l1, ListNode *l2){
        ListNode *curr1 = l1;
        ListNode *next1  = curr1->next;
        ListNode *curr2 = l2;
        ListNode *next2  = curr2->next;
        
        if(!curr1->next){                //base case
            curr1->next = curr2;
            return l1;
        }
        
        while(next1 && curr2)
        {
            if(curr2->val>=curr1->val && curr2->val<=next1->val)
            {
                //inserting node in between the first lust
                curr1->next = curr2;
                next2 = curr2->next;
                curr2->next = next1;
                
                //updating pointers;
                curr1 = curr2;
                curr2 = next2;
            }
            else{
                //go ahead if element does not lie in the range
                curr1 = next1;
                next1 = curr1->next;
                
                //if first ll ends,attach it to second one and return
                if(!next1){
                    curr1->next = curr2;
                    return l1;
                }
            }
        }
        return l1;   
    }
    
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val < l2->val){
            return solve(l1,l2);
        }
        else {
            return solve(l2,l1);
        }
    }
};


//inplace merging of 2 list(above)..(IMP)



//recursive :-

// ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
// 		if(l1 == NULL){
// 			return l2;
// 		}
// 		if(l2 == NULL){
// 			return l1;
// 		}        
// 		if(l1->val < l2->val){
// 			l1->next = mergeTwoLists(l1->next, l2);
// 			return l1;
// 		}
// 		else{
// 			l2->next = mergeTwoLists(l1, l2->next);
// 			return l2;            
// 		}
// 	}
