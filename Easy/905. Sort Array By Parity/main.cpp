#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
    for(int i = 0, j = nums.size() - 1; i < j; i++, j--)
    {
        while(i < j && nums[i] % 2 == 0) 
            i++;
        while(i < j && nums[j] % 2 == 1) 
            j--;
        
        if(i < j) swap(nums[i], nums[j]);
    }
    return nums;
}

int main()
{
    vector<int> nums = {3, 1, 2, 4};
    sortArrayByParity(nums);

    for(auto x : nums)
        cout << x << " ";

    return 0;
}