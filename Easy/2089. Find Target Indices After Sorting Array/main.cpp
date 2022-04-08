#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> targetIndices(vector<int>& nums, int target) {
    int size = nums.size();
    
    if(size == 0) return nums;
    
    vector<int> result;
    sort(nums.begin(), nums.end());
    
    // These three variables will help us do our binary search.
    int start = 0;
    int end = size - 1;
    int mid;
    
    while(start <= end)
    {
        // Index of the middle element, calculate that
        // first, then use it to narrow our search.
        mid = start + (end - start) / 2;
        
        // This is the bread and butter of the search, since 
        // the array is sorted we can just check one element,
        // according to that shift our search forward or backward.
        if(target > nums[mid])
        {
            start = mid + 1;
        }
        else if(target < nums[mid])
        {
            end = mid - 1;
        }
        
        // Last part for when we have target == nums[mid].
        else
        {
            result.push_back(mid);
            int left, right;
            
            // We need to check adjecent elements to the one we 
            // found, since we need all indexes in the result.
            for(int i = 1; i < size; i++)
            {
                left = mid - i;
                right = mid + i;
                
                if(right < size)
                {
                    if(nums[right] == target)
                        result.push_back(right);
                }
                
                if(left >= 0)
                {
                    if(nums[left] == target)
                        result.push_back(left);
                }
            }
            break;
        }
    }
    sort(result.begin(), result.end());
    
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 5, 2, 3};
    int target = 2;

    vector<int> result = targetIndices(nums, target);

    for(auto x : result)
        cout << x << " ";

    return 0;
}