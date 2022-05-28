/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(!root) return 0;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            Node* t = NULL;
            
            for(int i=0; i<size; i++){
                t = q.front();
                q.pop();
                
                //if this is not the last value then previous value will point to next one
                //Initially, all next pointers are set to NULL
                if(i != size-1) t->next = q.front();
                
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return root;
    }
};