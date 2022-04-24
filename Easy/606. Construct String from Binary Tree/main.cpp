#include <string>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
void dfs(TreeNode* root, std::string& result) {
    if(!root) return;
    
    // Process the node we are at.
    result += std::to_string(root->val);
    
    // Early return so that we keep that bracket
    // order we need.
    if(!root->left && !root->right) return;
    
    // First we add the open bracket and then go left,
    // afterwards always add a closing bracket.
    result += '(';
    dfs(root->left, result);
    result += ')';           

    // Here we want to check whether the child exists,
    // previously we didn't check cause we needed the 
    // correct bracket order as the exercise requires.
    if(root->right)
    {
        result += '('; 
        dfs(root->right, result);
        result += ')';           
    }      
}

std::string tree2str(TreeNode* root) {
    std::string result = "";
    dfs(root, result);
    
    return result;
}