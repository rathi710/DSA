// { Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.

 Node *solve(Node *l1, Node *l2){
        Node *curr1 = l1;
        Node *next1  = curr1->next;
        Node *curr2 = l2;
        Node *next2  = curr2->next;
        
        if(!curr1->next){
            curr1->next = curr2;
            return l1;
        }
        
        while(next1 && curr2)
        {
            if(curr2->data>=curr1->data && curr2->data<=next1->data)
            {
                //inserting node in between the first ll
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
                next1 = next1->next;
                
                //if first ll ends,traverse other ll fully
                if(!next1){
                    curr1->next = curr2;
                    return l1;
                }
            }
        }
        return l1;
        
    }
Node* sortedMerge(Node* l1, Node* l2)  
{  
    // code here
     if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->data <= l2->data){
            return solve(l1,l2);
        }
        else {
            return solve(l2,l1);
        }
}  