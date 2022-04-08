#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int missingNumber(vector<int>& nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    
    // First element must always be a 0, 
    // last element must be equal to the size.
    if(nums[0] != 0) return 0;
    if(nums[size - 1] != size) return size;
    
    // Main loop of the function, we know the numbers are in increasing 
    // order (we sorted beforehand) and consecutive, if we find a gap, 
    // thats the missing number.
    for(int i = 0; i < size - 1; i++)
    {
        if(nums[i] + 1 != nums[i + 1])
            return nums[i] + 1;
    }
    
    return - 1;
}

int main()
{
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << missingNumber(nums);
    
    return 0;
}