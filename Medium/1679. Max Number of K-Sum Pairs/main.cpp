#include <iostream>
#include <vector>
#include <algorithm>

int maxOperations(std::vector<int>& nums, int k) {
    if(nums.size() < 2) return 0;
    
    // Sort the nums array and initialize the two pointers.
    std::sort(nums.begin(), nums.end());
    int result = 0, left = 0, right = nums.size() - 1;
    
    // Now we loop until left meets right, meaning we visited
    // each number.
    while(left < right)
    {
        // Matching case, result gets incremented
        // and both pointers get moved.
        if(nums[left] + nums[right] == k)
        {
            result++;
            left++;
            right--;
        }
        // Otherwise we move one of the pointers
        // depending on where our sum is in relation to k.
        else if(nums[left] + nums[right] > k)
            right--;
        else
            left++;
    }
    return result;
}

int main()
{
    std::vector<int> nums = {1, 3, 3, 2, 5, 4, 2, 2};
    int k = 6;

    std::cout << maxOperations(nums, k);

    return 0;
}