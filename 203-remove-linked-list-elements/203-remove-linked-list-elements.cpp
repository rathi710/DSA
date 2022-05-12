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
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(!head) return NULL;
        ListNode *tmp = head;
        
        // Omit the nodes from the start of list by moving head pointer
        // if these nodes have to be deleted
        // eg [7, 7, 7, 3] val = 7, then we have to delete all 7 and move head to 3
        
        while(head && head->val==val){
            head=head->next;
        }
        
        // Now our head is updated
        // Now we will iterate our linked list using cur pointer
        // we surely know that cur is not to be deleted because we came to it
        // from the previous loop
        
        while(tmp->next){
            if(tmp->next->val==val){
                tmp->next = tmp->next->next;
            }
            else tmp=tmp->next;
        }
        return head;
    }
};


//Approach: 1
//* Solving the problem using two pointers: previous and current.

//Approach: 2(implemented above)
//*Solving the problem using a single pointer: current.