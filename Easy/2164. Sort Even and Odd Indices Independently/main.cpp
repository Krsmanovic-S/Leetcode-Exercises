#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortEvenOdd(vector<int>& nums) {
    vector<int> odds, evens;
    
    // Separate the odd indices and even indices
    // into two arrays.
    for(int i = 0; i < nums.size(); i++)
    {
        if(i % 2 != 0) 
            odds.push_back(nums[i]);
        else 
            evens.push_back(nums[i]);
    }
    
    // Sort them both now.
    sort(evens.begin(), evens.end());
    sort(odds.begin(), odds.end());
    
    int indexE = 0, indexO = odds.size() - 1;
    
    // Fill out the nums array with the values
    // from evens and odds depending on which index
    // they need to be at.
    for(int i = 0; i < nums.size(); i++)
    {
        if(i % 2 != 0)
        {
            nums[i]= odds[indexO];               
            indexO--;
        }
        else
        {
            nums[i]= evens[indexE];
            indexE++;
        }

    }
    return nums;
}

int main()
{
    vector<int> nums = {4, 1, 2, 3};
    sortEvenOdd(nums);

    for(auto x : nums)
        cout << x << " ";

    return 0;
}