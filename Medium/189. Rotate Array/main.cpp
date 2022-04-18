#include <iostream>
#include <vector>

using namespace std;

// Reverses elements from the beginning till
// index k, and reverses from index k to the end.
void helper(vector<int>& nums, int k) {
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());        
}

void rotate(vector<int>& nums, int k) {
    // In the first case we need to rotate
    // the array once and see how much
    // k-left over do we have after a full cycle.
    if(k > nums.size())
    {
        reverse(nums.begin(), nums.end());
        k %= nums.size();

        helper(nums, k);
    }
    else
    {
        reverse(nums.begin(), nums.end());
        helper(nums, k);
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(nums, k);

    for(auto x : nums)
        cout << x << " ";

    return 0;
}