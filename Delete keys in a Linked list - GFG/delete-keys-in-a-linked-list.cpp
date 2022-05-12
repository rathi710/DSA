// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void append(struct Node** head_ref, struct Node **tail_ref,
           int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
struct Node* deleteAllOccurances(struct Node *head,int );

void printList(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << "\n";
}
int sizeofthelinkedlist(Node* head)
{
    int x=0;
    while(head!=NULL)
    {
        x++;
        head=head->next;
    }
    return x;
}


/* Driver program to test above function*/
int main()
{
  int T,i,n,l;

  // TO BE REMOVED
  for (int i=0; i<2000; i++);


    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

	int kk;
	cin>>kk;
    head =deleteAllOccurances(head,kk);
    cout<<sizeofthelinkedlist(head)<<endl;
    printList(head);
    }
    return 0;
}

// } Driver Code Ends


/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};*/
/*You are required to complete below method*/
Node* deleteAllOccurances(Node *head,int x)
{
    if(!head) return NULL;
        Node *tmp = head;
        
        // Omit the nodes from the start of list by moving head pointer
        // if these nodes have to be deleted
        // eg [7, 7, 7, 3] val = 7, then we have to delete all 7 and move head to 3
        
        while(head && head->data==x){
            head=head->next;
        }
        
        // Now our head is updated
        // Now we will iterate our linked list using cur pointer
        // we surely know that cur is not to be deleted because we came to it
        // from the previous loop
        
        while(tmp->next){
            if(tmp->next->data==x){
                tmp->next = tmp->next->next;
            }
            else tmp=tmp->next;
        }
        return head;
}
