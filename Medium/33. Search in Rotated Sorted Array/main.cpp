#include <vector>

int search(std::vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1, mid;
    
    // Since array is rotated, we first need to 
    // move the start to the point of rotation,
    // meanwhile checking if we found the target.
    while(nums[start] > nums[end])
    {
        if(nums[start] == target)
            return start;
        
        start++;
    }
    
    if(nums[start] == target) 
        return start;
    
    // Binary search for the 2nd part of the array.
    while(start <= end)
    {
        mid = (start + end) / 2;
        
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    
    return -1;
}

int main()
{
    return 0;
}