#include <algorithm>
#include <climits>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// We need to find the two nodes that are in
// the wrong position as well as keep track of the
// node that is before the root.
TreeNode* firstWrong, *secondWrong, *prevNode;
void helper(TreeNode* root) {
    if(!root) return;
    
    // We first want to go to the left side,
    // this is important as we know that we have
    // a BST and all values leftwards are lower.
    helper(root->left);
    
    // prevNode starts at INT_MIN and we will use
    // it to populate the first and second wrong node
    // when we find them. Going left first comes to play
    // here, we want lower values first.
    if(!firstWrong && root->val < prevNode->val)
        firstWrong = prevNode;
    if(firstWrong && root->val < prevNode->val)
        secondWrong = root;
    
    // Move the previous node to the current one
    // and start moving rightwards.
    prevNode = root;
    helper(root->right);
}

void recoverTree(TreeNode* root) {
    prevNode = new TreeNode(INT_MIN);
    helper(root);
    
    std::swap(firstWrong->val, secondWrong->val);
}

int main()
{
    return 0;
}