#include <stack>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    TreeNode* smallest;
    std::stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        traversal(root);
    }
    
    void traversal(TreeNode* root) {
        TreeNode* temp = root;
        
        while(temp)
        {
            s.push(temp);
            temp = temp->left;
        }
    }
    
    int next() {
        smallest = s.top();
        s.pop();
        
        if(smallest->right != NULL)
            traversal(smallest->right);  
     
        return smallest->val;
    }
    
    bool hasNext() {
        return (s.empty() ? false : true);
    }
};

int main()
{
    return 0;
}