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

int maximum = 0;
int tempMax = 1;
    
int maxDepth(TreeNode* root) {
    if(root == NULL) return maximum;

    TreeNode* left = root->left;
    TreeNode* right = root->right;

    // This is the main bread and butter of DFS,
    // explanation is below the code.
    if(left != NULL)
    {
        root = left;
        tempMax++;
        maxDepth(root);
    }
    if(right != NULL)
    {
        root = right;
        tempMax++;
        maxDepth(root);
    }

    // We need to compare the current maximum to the actual one,
    // do the assignment if it's bigger, and finally decrement
    // tempMax which means we went one node backwards.
    if(tempMax > maximum) 
        maximum = tempMax;
    tempMax--;         

    return maximum;
}

int main()
{
    return 0;
}