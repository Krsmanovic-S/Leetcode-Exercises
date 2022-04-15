#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    if(nums.size() < 4) return result;
    
    vector<int> combination;
    sort(nums.begin(), nums.end());
    
    int left, right, last;
    ll sum;
    
    for(int i = 0; i < nums.size() - 3; i++)
    {
        // We don't want to re-use same elements,
        // this check starts at the second element(i = 1),
        // we still use the nums[0].
        if(i > 0 && nums[i] == nums[i - 1])
            continue;

        for(left = i + 1; left < nums.size() - 2; left++)
        {
            // Same check as for the first number, no duplicates!
            if(left > i + 1 && nums[left] == nums[left - 1])
                continue;
            
            right = left + 1;
            last = nums.size() - 1;
            while(right < last)
            {    
                sum = (ll)nums[i] + (ll)nums[left] + (ll)nums[right] + (ll)nums[last];

                if(sum == target)
                {
                    combination = {nums[i], nums[left], nums[right], nums[last]};
                    result.push_back(combination);
                    
                    // Another check for duplicates... sheesh we really 
                    // don't want them do we?
                    while(right < last && nums[right] == nums[right + 1])
                        right++;
                        
                    while(right<last && nums[last] == nums[last - 1])
                        last--;
                }
                
                // Do the traversal according to the sum to target relation.
                if(sum < target)
                    right++;
                else
                    last--;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = fourSum(nums, target);

    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}