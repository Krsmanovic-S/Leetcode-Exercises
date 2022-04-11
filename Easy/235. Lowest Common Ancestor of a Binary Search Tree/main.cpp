#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* result = NULL;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return root;
    
    // If our values are lower than the current root, that
    // means we need to search the left side of the tree.
    if(p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    
    // Same logic as above, just for when they are greater,
    // this time we search the right side of the tree.
    else if(p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    
    // If one of them is equal to our root then that is the answer,
    // exercise guaranteed both values are in the tree, so we just need
    // to find one.
    else
        result = root;
    
    return result;
}

int main()
{
    return 0;
}