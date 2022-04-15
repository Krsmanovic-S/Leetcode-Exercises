#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> combination;
    
    int left, right, sum;
    
    for (int i = 0; i < nums.size() - 2; i++) 
    {
        // Skip all duplicates from left, check 
        // starts at second element.
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        left = i + 1;
        right = nums.size() - 1;
        
        // We fixed the first number to i, now time to look for
        // the other two using the two pointer approach.
        while(left < right) 
        {
            sum = nums[left] + nums[right] + nums[i];
            if (sum == 0) 
            {
                // Add triplet to result
                combination = {nums[left], nums[right], nums[i]};
                result.push_back(combination);
                
                right--;

                // Skip all duplicates from right.
                while(left < right && nums[right] == nums[right + 1]) right--;
            }
            // Move the pointers accordingly if sum isn't 0.
            else if (sum > 0)
                right--;
            else
                left++;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}