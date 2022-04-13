#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParityII(vector<int>& nums) {
    vector<int> odds, evens;
    
    // Fill out the odds and evens arrays.
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] % 2 != 0)
            odds.push_back(nums[i]);
        else
            evens.push_back(nums[i]);
    }
    
    int indexE = 0, indexO = 0;
    
    // Now pick a number from each one depending on
    // if i is even or odd.
    for(int i = 0; i < nums.size(); i++)
    {
        if(i % 2 != 0)
            nums[i]= odds[indexO++];               
        else
            nums[i]= evens[indexE++];
    }
    
    return nums;
}

int main()
{
    vector<int> nums = {4, 2, 5, 7};
    sortArrayByParityII(nums);

    for(auto x : nums)
        cout << x << " ";

    return 0;
}