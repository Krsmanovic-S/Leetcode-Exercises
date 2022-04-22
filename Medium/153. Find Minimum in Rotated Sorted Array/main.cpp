#include <iostream>
#include <vector>

int findMin(std::vector<int>& nums) {
    int start = 0, end = nums.size() - 1;
    
    // If first element is smaller than the last,
    // array wasn't really rotated, we just return
    // the first element.
    if(nums[start] < nums[end]) return nums[start];
    
    // Go until the starting element is greater
    // than the end, this will get us to the pivot
    // point, which is our minimum element.
    while(nums[start] > nums[end])
        start++;
    
    return nums[start];
}

int main()
{
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    std::cout << findMin(nums);
    
    return 0;
}