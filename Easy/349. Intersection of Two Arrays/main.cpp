#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    int size_1 = nums1.size(), size_2 = nums2.size();
    unordered_map<int, int> map;
    vector<int> result;
    
    // Populate map from nums1. We track each element once.
    for(int i = 0; i < size_1; i++)
        if(!map[nums1[i]]) map[nums1[i]]++;
    
    // Now go and check for each number in nums2 do we have a match
    // in our map, if we do, we push that onto the result.
    for(int j = 0; j < size_2; j++)
    {
        if(map[nums2[j]]) 
        {
            result.push_back(nums2[j]);
            map[nums2[j]] = 0;
        }
    }
    
    return result;
}

int main()
{
    vector<int> nums1 = {4, 9, 5}, nums2 = {9, 4, 9, 8, 4};

    auto result = intersection(nums1, nums2);
    for(auto x : result)
        cout << x << " ";
    
    return 0;
}