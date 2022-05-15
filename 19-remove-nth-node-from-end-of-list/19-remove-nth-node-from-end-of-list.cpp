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
       //BruteForce Method
      //Time Complexity :- O(n) + O(n) = O(2*n) [Two Pass]
      //Space Complexity:- O(1)
       
      //Counting the number of nodes in the linked list.
        ListNode*tmp=head;
        int c=0;
        while(tmp){
            tmp=tmp->next;
            c++;
        }
        
         //Checking the edge case when the 'n' i.e. node to be deleted
        //from end of the list is equal to the number of nodes in the 
        //linked list.
        /*For Example :- 
                       Input : [7,4] , n=2
                       Output: [4]
      */
        
        if(n==c){                   
          ListNode *node=head;  
          head=head->next;        //or simply: return head->next
          delete node;
          return head;
        }
        
         //If the node to be deleted is not the head of the list then we have 
        //to reach one node before it.
        tmp=head;
        int res=1;
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

