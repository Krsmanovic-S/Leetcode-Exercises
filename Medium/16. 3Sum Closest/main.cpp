#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int size = nums.size(), left, right, sum;
    
    // We start closest as the sum of the first three numbers
    // and initialize the best range by the distance from closest
    // to the target value.
    int closest = nums[0] + nums[1] + nums[2];
    int newRange, bestRange = abs(closest - target);
    
    for(int i = 0; i < size - 2; i++)
    {
        left = i + 1;
        right = size - 1;
        while(left < right)
        {
            sum = nums[i] + nums[left] + nums[right];
            
            // Moving the two pointers accordingly.
            if(sum > target) 
                right--;
            else if(sum < target)
                left++; 
            else
                return sum;

            // Now we calculate the new range to the target from
            // the current sum of values and then compare it to 
            // the best range.
            newRange = abs(sum - target);

            if(newRange < bestRange)
            {
                bestRange = newRange;
                closest = sum;
            }
        }
    }
    return closest;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int target = -5;

    cout << threeSumClosest(nums, target);

    return 0;
}