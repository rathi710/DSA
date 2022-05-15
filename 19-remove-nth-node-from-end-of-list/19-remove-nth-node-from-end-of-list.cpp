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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int res=1;
        ListNode*tmp=head;
        int c=0;
        while(tmp){
            tmp=tmp->next;
            c++;
        }
        if(n==c){
            return head->next;
        }
        
        if(c==0 || c ==1 ) return NULL;
        tmp=head;
        while(tmp->next)
        {
            if(res==c-n){
                tmp->next = tmp->next->next;
                break;
            }
            else{
                tmp=tmp->next;
                res++;
            }
        }
        return head;
    }
};