#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    unordered_map<int, int> m;
public:
    // Used so we can sort a vector<pair<int, int>> later on
    // with the highest frequency numbers at the beginning.
    static bool compare(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }

    void populateMap(TreeNode* root) {
        // Use the root->val as the key and
        // increment its number of occurrences.
        m[root->val]++;
        
        // Preorder traversal, first left then right.
        if(root->left)
            populateMap(root->left);
        if(root->right)
            populateMap(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        // Use this function to traverse the entire
        // tree and map out each nodes num of occurrences.
        populateMap(root);
        
        vector<pair<int, int>> temp;
        vector<int> result;
        
        // Populate temp with the values from the map
        // and then sort it according to the highest 
        // frequency elements.
        for(auto x : m)
            temp.push_back(x);
        sort(temp.begin(), temp.end(), compare);
        
        // Assign the highest frequency element
        // to the result, loop through to see
        // if any other element has same frequency.
        result.push_back(temp[0].first);        
        for(int i = 1; i < temp.size(); i++)
        {
            if(temp[i].second == temp[0].second)
                result.push_back(temp[i].first);
            else
                break;
        }

        return result;
    }
};

int main()
{
    return 0;
}