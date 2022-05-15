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
       //Optimised Method
       //Time Complexity:- O(n) [One Pass]
       //Space Complexity:-O(1)

        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        
        ListNode *fast=dummy;
        ListNode *slow = dummy;
        
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        
    //let's keep a slow pointer which is assigned to
    //dummy(by which we dont need to handle the case when fast==null). Now, move       
    //both slow and fast pointer simultaneously
    //till the fast pointer reaches the last node. Here,you will observe 
    //that slow pointer is standing one node before the node to be 
    //deleted. 
        
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        
        return dummy->next;
    }
};


//  ListNode* removeNthFromEnd(ListNode* head, int n) 
//     {   
//        //BruteForce Method
//       //Time Complexity :- O(n) + O(n) = O(2*n) [Two Pass]
//       //Space Complexity:- O(1)
       
//       //Counting the number of nodes in the linked list.
//         ListNode*tmp=head;
//         int c=0;
//         while(tmp){
//             tmp=tmp->next;
//             c++;
//         }
        
//          //Checking the edge case when the 'n' i.e. node to be deleted
//         //from end of the list is equal to the number of nodes in the 
//         //linked list.
//         /*For Example :- 
//                        Input : [7,4] , n=2
//                        Output: [4]
//       */
        
//         if(n==c){                   
//           ListNode *node=head;  
//           head=head->next;        //or simply: return head->next
//           delete node;
//           return head;
//         }
        
//          //If the node to be deleted is not the head of the list then we have 
//         //to reach one node before it.
//         tmp=head;
//         int res=1;
//         while(tmp->next)
//         {
//             if(res==c-n){
//                 tmp->next = tmp->next->next;
//                 break;
//             }
//             else{
//                 tmp=tmp->next;
//                 res++;
//             }
//         }
//         return head;
//     }
