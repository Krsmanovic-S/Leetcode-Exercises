// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    // If one root is null, return the other one.
    if(!root1 || !root2)
        return (root1 == nullptr ? root2 : root1);
    
    // If both nodes exist, time to add them up.
    if(root1 && root2)
        root1->val += root2->val;
    
    // Preorder traversal of the trees,
    // we do this if both children exist.
    if(root1->left && root2->left)
        mergeTrees(root1->left, root2->left);
    
    if(root1->right && root2->right)
        mergeTrees(root1->right, root2->right);

    // Now we need to connect the part of the tree
    // that is missing in the first tree, depending on
    // which child is missing.
    if(!root1->left && root2->left)
        root1->left = root2->left;
    
    if(!root1->right && root2->right)
        root1->right = root2->right;
    
    return root1;
}

int main()
{
    return 0;
}