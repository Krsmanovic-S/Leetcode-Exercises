#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
    // We use this variable so that we don't
    // infinitely sort ending 2's.
    int stop = 0;
    
    for(int i = 0; i < nums.size(); i++)
    {
        if(stop == nums.size())
            break;

        if(nums[i] == 0 && i != 0)
        {
            nums.erase(nums.begin() + i);
            nums.insert(nums.begin(), 0);
            stop++;
        }
        else if(nums[i] == 2 && i != nums.size() - 1)
        {
            nums.erase(nums.begin() + i);
            nums.push_back(2);
            i--;
            stop++;
        }
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0, 2, 2, 2, 2, 2, 1, 1, 1, 0, 2, 1, 1, 1, 1};
    sortColors(nums);

    for(auto x : nums)
        cout << x << " ";

    return 0;
}