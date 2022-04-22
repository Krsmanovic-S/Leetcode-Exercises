#include <iostream>
#include <vector>

int findMin(std::vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    int start = 0, end = nums.size() - 1;
    
    // Early return if the start is less than the
    // final element, means array wasn't rotated really.
    if(nums[start] < nums[end]) return nums[start];
    
    // Increment start as long as it's greater or equal
    // to the end element and it isn't the end index itself.
    while(nums[start] >= nums[end] && start != end)
        start++;
    
    return nums[start];
}

int main()
{
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 4};
    std::cout << findMin(nums);
    
    return 0;
}