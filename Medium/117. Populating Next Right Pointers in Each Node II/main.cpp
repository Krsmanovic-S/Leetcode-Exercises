#include <queue>

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

Node* connect(Node* root) {
    if(!root)
        return root;
    
    // Breadth first search with a queue.
    std::queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    Node* curr;
    
    while(q.size() > 1)
    {
        curr = q.front();
        q.pop();
        if(!curr)
        {
            q.push(NULL);
            continue;
        }
        
        curr->next = q.front();
        
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
    return root;
}