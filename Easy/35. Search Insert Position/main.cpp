#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1, mid;
    
    while(start <= end)
    {
        mid = start + (end - start) / 2;
        
        if(target > nums[mid])
            start = mid + 1;
        else if(target < nums[mid])
            end = mid - 1;
        else
            return mid;
    }
    
    if(target > nums[mid])
        return mid + 1;
    else if(target < nums[mid] && mid != 0)
        return mid;
    else
        return 0;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6}; 
    int target = 5;

    cout << searchInsert(nums, 5);

    return 0;
}