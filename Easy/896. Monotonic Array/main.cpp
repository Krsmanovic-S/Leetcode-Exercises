#include <iostream>
#include <vector>

using namespace std;

bool isMonotonic(vector<int>& nums) {
    int size = nums.size();
    if(size == 1) return true;
    
    // Check to see if the array is meant to be increasing or decreasing.
    bool increasing = (nums[0] > nums[size - 1] ? false : true);;
    
    // Main loop to check the array.
    for(int i = 0; i < size - 1; i++)
    {
        if(increasing)
        {
            if(nums[i] > nums[i + 1]) return false;
        }
        else
        {
            if(nums[i] < nums[i + 1]) return false;                
        }
    }
    return true;
}

int main()
{
    vector<int> nums = {6, 5, 4, 4};
    cout << isMonotonic(nums);
    
    return 0;
}