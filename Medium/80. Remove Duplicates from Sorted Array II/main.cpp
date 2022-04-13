#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() <= 2)
        return nums.size();
    
    int count = 0;
    int current = nums[0];
    
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == current)
            count++;
        
        if(count == 3)
        {
            nums.erase(nums.begin() + i);
            count--;
            i--;
        }

        if(nums[i] != current)
        {
            current = nums[i];
            count = 1;
        }
    }
    return nums.size();
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int newSize = removeDuplicates(nums);
    
    return 0;
}