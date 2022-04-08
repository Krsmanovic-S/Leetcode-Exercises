#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// This function will traverse the entire tree and return us a vector of values from each tree node.
vector<int> populateVector(TreeNode* root, unordered_map<int, int>& map, vector<int> v) {
    if(!root) return v;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    
    // If we already added the value from this node, don't add it again,
    // otherwise we just add it to the map to keep track of it as well as
    // push it onto the vector.
    if(!map[root->val])
    {
        map[root-> val] = root->val;
        v.push_back(root->val);
    }
    else
        return v;
    
    // This is to traverse the tree.
    if(left != NULL)
    {
        v = populateVector(left, map, v);
    }
    if(right != NULL)
    {
        v = populateVector(right, map, v);
    }
    
    return v;
}

bool findTarget(TreeNode* root, int k) {
    unordered_map<int, int> map;
    vector<int> treeValues;
    
    treeValues = populateVector(root, map, treeValues);
    
    sort(treeValues.begin(), treeValues.end());
    int size = treeValues.size();
    int start = 0, end = size - 1;

    // Two pointer approach to find the sum if it exists,
    // we sorted the vector first so we can do this one pretty easy.
    while(start < end)
    {
        if(treeValues[start] + treeValues[end] == k)
            return true;
        
        // Move the two pointers accordingly.
        if(k - treeValues[start] < treeValues[end])
            end--;
        if(k - treeValues[start] > treeValues[end])
            start++;
    }
    return false;
}

int main()
{
    return 0;
}