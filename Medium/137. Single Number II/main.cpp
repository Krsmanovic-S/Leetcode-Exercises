#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int singleNumber(vector<int>& nums) {
    int size = nums.size(), count = 0, currentElem;
    sort(nums.begin(), nums.end());
    
    currentElem = nums[0];
    
    for(int i = 0; i < size - 2; i++)
    {
        if(currentElem == nums[i])
            count++;
        else
        {
            if(count == 1)
                return currentElem;
            currentElem = nums[i];
            count = 1;
        }
        
    }
    return nums[size - 1];
}

int main()
{
    vector<int> nums = {2, 2, 3, 2};
    cout << singleNumber(nums);
    
    return 0;
}