#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> result;

    unsigned int c = 1;

    // First one must be equal to 1, if not we just add it.
    if(nums[0] != 1)
        result.push_back(1);
    
    // Loop will go through each member of the nums vector, and check if
    // that member is the next in line for a variable c (which starts at 1).
    for(int i = 0; i < nums.size(); i++)
    {
        unsigned int a = nums[i];
        
        // The number is either equal to our c variable or is one above it,
        // both scenarios are fine, means the numbers are there/not disappeared.
        if(nums[i] == c || nums[i] == c + 1)
        {
            // Don't forget we need to move c, not keep it at 1 all the time!
            c = a;
            continue;
        }
        else
        {
            // This loop will get us our result, it will fill the numbers
            // that we are missing from c (our counter variable) to a (nums[i] -> current value).
            for(int i = c + 1; i < a; i++)
            {
                result.push_back(i);
            }
            c = a; // Move c again, we filled the blanks now it's time to continue.
        }
    }
    
    // Last number is tricky, we need to check if there are
    // disappeared numbers between the last number and n (size of nums vector).
    if(nums[n - 1] != n)
    {
        for(int i = nums[n - 1] + 1; i <= n; i++)
            result.push_back(i);
    }
    
    return result;
}

int main()
{
    vector<int> example = { 4, 3, 2, 7, 8, 2, 3, 1 };
    vector<int> result = findDisappearedNumbers(example);

    return 0;
}