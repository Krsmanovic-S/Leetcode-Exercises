#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> result(2);
    
    // One map tracks nums1, other one
    // tracks nums2.
    unordered_map<int, int> map1;
    unordered_map<int, int> map2;
    
    vector<int> temp1;
    vector<int> temp2;
    
    // Traverse the array once to map
    // values from nums1, and another
    // time to map values from num2.
    for(int i = 0; i < nums1.size(); i++)
    {
        if(!map1[nums1[i]])
            map1[nums1[i]]++;
    }
    for(int j = 0; j < nums2.size(); j++)
    {
        if(!map2[nums2[j]])
            map2[nums2[j]]++;
    }
    
    // Traverse both maps and
    // fill the vectors accordingly.
    for(auto x : map1)
    {
        if(!map2[x.first])
            temp1.push_back(x.first);
    }
    for(auto x : map2)
    {
        if(!map1[x.first])
            temp2.push_back(x.first);
    }
            
    result[0] = temp1;
    result[1] = temp2;
    
    return result;
}

int main()
{
    vector<int> nums1 = {1, 2, 3}, nums2 = {2, 4, 6};
    vector<vector<int>> result = findDifference(nums1, nums2);

    return 0;
}