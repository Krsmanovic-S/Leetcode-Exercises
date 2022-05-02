#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    
    // Base cases.
    if(n == 0)
        return 0;
    if(n == 1)
        return nums[0];

    // Declare an array to store the robbed amount 
    // througout the entire array traversal and
    // initialize the first two values as follows.
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    
    // Now we loop through the entire dp array and
    // fill out the maximum robbed amount at each index.
    for(int i = 2; i < n; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    
    // Finally we return the end of dp since it represents
    // the final robbed amount.
    return dp[n - 1];
}

int main()
{
    vector<int> nums = {2, 9, 7, 3, 1};
    cout << rob(nums);

    return 0;
}