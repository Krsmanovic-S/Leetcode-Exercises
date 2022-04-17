// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int sum = 0;

TreeNode* convertBST(TreeNode* root) {
    if(!root) return nullptr;
    
    if(root->right)
        convertBST(root->right);
    
    root->val = root->val + sum;
    sum = root->val;        
    
    if(root->left)
        convertBST(root->left);
    
    return root;
}

int main()
{
    return 0;
}