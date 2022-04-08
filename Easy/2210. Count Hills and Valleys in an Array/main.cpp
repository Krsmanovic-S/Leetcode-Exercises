#include <iostream>
#include <vector>

using namespace std;

int countHillValley(vector<int>& nums) {
    int size = nums.size(), result = 0 ;
    
    // Initialize the left neighbour to the first element.
    int left = nums[0], current, next;
    
    for(int i = 1; i < size - 1; i++)
    {
        current = nums[i];
        next = nums[i + 1];
        
        // If the neighbouring number is the same just continue.
        if(current == left || current == next) continue;
        
        // This is to count the result, since we don't need the exact number of hills/vallies
        // we can just clump them into one result.
        if((current < left && current < next) || (current > left && current > next))
            result++;
        
        // Move the left neighbour at the end by one space forward.
        left = current;
    }
    return result;
}

int main()
{
    vector<int> nums = {2, 4, 1, 1, 6, 5};
    cout << countHillValley(nums);
    
    return 0;
}