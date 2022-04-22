#include <iostream>
#include <vector>

using namespace std;

int specialArray(vector<int>& nums) {
    int count = 0;
    
    // We go from 1 till 1000 because the constraints
    // say that nums[i] will be between 1 and 1000.
    for(int i = 1; i <= nums[nums.size() - 1]; i++)
    {
        // Now we check for each element.
        for(int j = 0; j < nums.size(); j++)
        {
            if(nums[j] >= i)
                count++;
            
            // At any point that count exceeds i, we can break.
            if(count > i) break;
        }
        
        if(count == i)
            return i;
        else
            count = 0;
    }
    return -1;
}

int main()
{
    vector<int> nums = {3, 5, 4, 0, 2, 3, 5, 6, 7};
    cout << specialArray(nums);
    
    return 0;
}