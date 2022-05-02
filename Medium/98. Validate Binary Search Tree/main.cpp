#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Inorder traversal of the entire tree,
// we will travel inorder and fill up the vector values.
void inorder(TreeNode* root, std::vector<int>& values) {
    if(!root) return;
    
    inorder(root->left, values);
    
    values.push_back(root->val);
    
    inorder(root->right, values);
}

bool isValidBST(TreeNode* root) {
    if(!root) return true;
    std::vector<int> values;
    
    inorder(root, values);
    
    // Since we did inorder traversal, every
    // member of values has to be smaller than the
    // next member, otherwise we don't have a BST.
    for(int i = 0; i < values.size() - 1; i++)
    {
        if(values[i] >= values[i + 1])
            return false;
    }
    return true;
}