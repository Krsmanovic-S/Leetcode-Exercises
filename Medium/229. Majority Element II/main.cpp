#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> map;
    vector<int> result;
    
    // First populate the map with each number in the array
    // and it's number of occurrences.
    for(int i = 0; i < nums.size(); i++)
        map[nums[i]]++;
    
    // Traverse the map and look for every number if it
    // satisfies the exercise condition. If it does we
    // push it on to the resulting vector, if not we just continue.
    for(auto x : map)
    {
        if(x.second > nums.size() / 3)
            result.push_back(x.first);
    }
    return result;
}

int main()
{
    vector<int> nums {3, 2, 3};
    vector<int> result = majorityElement(nums);

    for(auto x : result)
        cout << x << " ";

    return 0;
}