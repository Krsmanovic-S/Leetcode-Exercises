#include <iostream>
#include <vector>

using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result = { -1, -1 };
    int size = nums.size();
    
    // No point in checking empty vectors or those,
    // that have a target larger than the last element.
    if(nums.empty() || target > nums[size - 1]) 
        return result;
    
    int start = 0, end = size, mid;
    
    // Bread and butter for the exercise, we use binary
    // search here to find the element ASAP.
    while(start <= end)
    {
        mid = start + (end - start) / 2;
        
        if(target > nums[mid])
            start = mid + 1;
        else if(target < nums[mid])
            end = mid - 1;
        else
        {
            // Remember where we found the target, we will
            // need this a bit later for the last occurrence.
            int remember = mid;
            
            // We found the element but we need to go to the
            // first occurrence, lower mid until we get there.
            while(mid > 0)
            {
                if(nums[mid - 1] == target)   
                    mid--;
                else
                    break;
            }
            
            // This is so we can cycle through until we find the
            // last occurrence of the element.
            while(remember < size - 1)
            {
                if(nums[remember + 1] == target)   
                    remember++;
                else
                    break;
            }
            
            result[0] = mid;
            result[1] = remember;
            break;
        }
    }
    
    return result;
}

int main()
{
    vector<int> example = { 2, 3, 3, 3, 4, 5, 6, 6, 6, 6, 8, 8, 9, 9, 10, 10 };
    int target = 6;

    vector<int> result = searchRange(example, target);

    for(auto x : result)
        cout << x << " ";

    return 0;
}