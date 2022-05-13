// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
     struct Node *reverse(struct Node *head){
        struct Node *prev = NULL;
        struct Node *curr = head;
        struct Node *next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        // code here
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        int sum=0, c=0;
        
        struct Node *tmp;
        struct Node *head = NULL;
        struct Node *curr = NULL;
            
        while(l1 or l2){
            sum = c + (l1?l1->data:0) + (l2?l2->data:0);
            c = (sum>=10)?1:0;
            sum = sum%10;
            
            tmp = new Node(sum);
            if(head==NULL) head = tmp;
            else curr->next = tmp;
            
            curr = tmp;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            
        }
        if(c>0){
            tmp = new Node(c);
            curr->next = tmp;
            curr = tmp;
        }
        head = reverse(head);
        return head;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends