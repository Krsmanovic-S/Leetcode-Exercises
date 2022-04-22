// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);
    
    // Create a copy of the root and use it for
    // traversal. This will get us where we need
    // to insert.
    TreeNode* current = root;
    while(true)
    {
        // Go to the right first.
        if(current->val <= val)
        {
            // If the right child exists,
            // keep moving in that direction.
            if(current->right)
                current = current->right;
            // If not, that is where we need to insert.
            else
            {
                current->right = new TreeNode(val);
                return root;
            }
        }
        // Then to the left side. Same logic
        // applies as to the above code.
        else
        {
            if(current->left)
                current = current->left;
            else
            {
                current->left = new TreeNode(val);
                return root;
            }
        }
    }
}

int main()
{
    return 0;
}