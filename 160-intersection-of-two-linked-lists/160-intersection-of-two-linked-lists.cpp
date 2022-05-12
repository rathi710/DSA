/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode* ptr1 = headA;
        ListNode*ptr2 = headB;
        
        while(ptr1!=ptr2){
            
            if(!ptr1) ptr1=headB;
            else ptr1=ptr1->next;
                
            if(!ptr2) ptr2=headA;
            else ptr2=ptr2->next;
            
        }
        return ptr1;
    }
};



// 1. Brute Force Solution
// Time Complexity : O(m ^ n)
// Space Complexity : O(1)

// class Solution {
// public:
// 	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
// 		ListNode *temp;
// 		while(headA != NULL){
// 			temp = headB;
// 			while(temp != NULL){
// 				if(headA == temp){
// 					return headA;
// 				}
// 				temp = temp -> next;
// 			}
// 			headA = headA -> next;
// 		}
// 		return NULL;
// 	}
// };


// 2. HashMap Solution
// Time Complexity : O(m + n)
// Space Complexity : O(m)

// class Solution {
// public:
// 	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
// 		unordered_map<ListNode*, int> m;
// 		while(headA != NULL){
// 			m[headA]++;
// 			headA = headA -> next;
// 		}
// 		while(headB != NULL){
// 			if(m[headB] > 0){
// 				return headB;
// 			}
// 			headB = headB -> next;
// 		}
// 		return NULL;
// 	}
// };


// 3. Length Difference Solution
// Time Complexity : O(m + n)
// Space Complexity : O(1)

// class Solution {
// public:
// 	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
// 		int n = 0;
// 		int m = 0;
// 		ListNode* ptr1 = headA;
// 		ListNode* ptr2 = headB;
// 		while(ptr1 != NULL){
// 			n++;
// 			ptr1 = ptr1 -> next;
// 		}
// 		while(ptr2 != NULL){
// 			m++;
// 			ptr2 = ptr2 -> next;
// 		}
// 		int t = abs(n - m);
// 		if(n > m){
// 			while(t){
// 				headA = headA -> next;
// 				t--;
// 			}
// 		}
// 		else{
// 			while(t){
// 				headB = headB -> next;
// 				t--;
// 			}
// 		}
// 		while(headA != NULL and headB != NULL){
// 			if(headA == headB){
// 				return headA;
// 			}
// 			headA = headA -> next;
// 			headB = headB -> next;
// 		}
// 		return NULL;
// 	}
// };


//4-Two-Pointers Solution(above)(short &clean->preferable)
//Time Complexity : O(m + n)
//Space Complexity : O(1)