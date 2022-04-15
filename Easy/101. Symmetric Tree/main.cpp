// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool helper(TreeNode* leftSide, TreeNode* rightSide) {
    // If one side reaches NULL check if the other one reached NULL as well.
    if(leftSide == nullptr || rightSide == nullptr) 
        return leftSide == rightSide;
    
    // If none are NULL we check their values to see if they match.
    if(leftSide->val != rightSide->val) return false;
    
    // Now we just recursively call the function, left child of the left side is called
    // with the right child of the right side and the oposite in the other call.
    return helper(leftSide->left, rightSide->right) && helper(leftSide->right, rightSide->left);
}

bool isSymmetric(TreeNode* root) {
    return helper(root->left, root->right);
}

int main()
{
    return 0;
}