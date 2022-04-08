#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int currentPath = 0;
bool found = false;

bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == NULL) return false;
    
    // No point to waste time, if we find it once,
    // that's all we need!
    if(found) return found;
    
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    
    // Process the current node
    currentPath += root->val;
    
    // Traverse the tree till we find a leaf node
    if(left != NULL)
    {
        hasPathSum(left, targetSum);
    }
    if(right != NULL)
    {
        hasPathSum(right, targetSum);
    }
    
    // Found a leaf node! Now check if it matches to target,
    // if it doesn't dont forget to reduce the currentPath by
    // it's value since we are backtracking now.
    if(left == NULL && right == NULL)
    {
        if(currentPath == targetSum) 
            found = true;
    }
    
    // We are backtracking in the node traversal now, don't forget to
    // decrement the path by the last node's value
    currentPath -= root->val;

    return found;
}

int main()
{
    return 0;
}