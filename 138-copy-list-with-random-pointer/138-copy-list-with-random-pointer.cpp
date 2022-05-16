/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    void insertNode(Node * &head, Node * &tail, int data) 
    {
        Node*newNode = new Node(data);     //making the node with fetched data
        if(head==NULL){          //node coming first time
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    Node* copyRandomList(Node* head) 
    {
        //clone the linear LL first without random
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;
        
        Node *tmp = head;
        while(tmp){
            insertNode(cloneHead,cloneTail,tmp->val);
            tmp=tmp->next;
        }
        
        Node *originalNode = head;
        Node *cloneNode = cloneHead;
        
        //create a map (original--->clone)
        unordered_map<Node*,Node*> m;
        
        while(originalNode && cloneNode)
        {
            m[originalNode] = cloneNode;
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        
        //connecting random pointer of cloneNode
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode!=NULL){
            cloneNode->random = m[originalNode->random];
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        
        return cloneHead;
    }
};