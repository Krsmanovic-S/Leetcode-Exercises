#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    vector<int> result;
    unordered_map<int, int> map;
    
    // Populate the map with each number from nums and
    // its number of occurrences.
    for(int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]++;
    }
    
    // Traverse the map and find the two elements that
    // only appear once and add them to the resulting vector.
    for(auto x : map)
    {
        if(x.second == 1)
            result.push_back(x.first);
        
        if(result.size() == 2)
            break;
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> result = singleNumber(nums);

    for(auto x : result)
        cout << x << " ";

    return 0;
}