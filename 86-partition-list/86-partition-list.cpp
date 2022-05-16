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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode*l1=new ListNode(0);
        ListNode*t1=l1;
        ListNode*l2=new ListNode(0);
        ListNode*t2=l2;
        
        while(head){
            if(head->val<x){
                t1->next=head;
                t1=t1->next;
            }
            else if(head->val>=x){
                t2->next=head;
                t2=t2->next;
            }
            head=head->next;
        }
        
        //connecting the lists
        t1->next=l2->next;
        t2->next=NULL;
        
        return l1->next;
    }
};



//explanation:-
//make two linked lists one for the values smaller than x and other for greater than or equal //to x and connect them at last