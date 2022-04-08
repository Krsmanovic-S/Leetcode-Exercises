#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int size = nums.size();
    if(size == 1) return 0;
    
    int start = 0, end = size - 1, mid;
    while(start <= end)
    {
        mid = start + (end - start) / 2;
        
        // If we satisfy the condition return early with the index. First we check
        // the base case and then two edge cases so we don't go out of bounds.
        if(mid != 0 && mid != size -1)
        {
            if(nums[mid] > nums[mid + 1] && nums[mid] >= nums[mid - 1])
                return mid;
        }
        else if(mid == 0)
        {
            if(nums[mid] > nums[mid + 1])
                return mid;
        }
        else if(mid == size -1)
        {
            if(nums[mid] > nums[mid - 1])
                return mid;
        }
        
        // Now we need to move start/end accordingly.
        if(nums[mid] < nums[mid + 1])
            start = mid + 1;
        else if(nums[mid] > nums[mid + 1])
            end = mid - 1;
        else
        {
            start++;
            end--;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 5, 6,};
    cout << findPeakElement(nums);
    
    return 0;
}