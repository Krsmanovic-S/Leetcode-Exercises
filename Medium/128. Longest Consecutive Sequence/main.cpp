#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    // Base cases.
    if(nums.size() == 0) return 0;
    if(nums.size() == 1) return 1;
    
    set<int> s;
    int bestLen = 1, len = 1;
    
    // Populate the set with every number in the array,
    // don't import duplicates as well.
    for(int i = 0; i < nums.size(); i++)
    {
        if(s.find(nums[i]) == s.end())
            s.insert(nums[i]);
    }
    
    // Now we create an iterator to the beginning of the set
    // and initialize our first value, after which we move the iterator
    // since we whanna loop from the second element onwards.
    set<int>::iterator itr = s.begin();
    int current = *itr;
    
    itr++;

    for(itr; itr != s.end(); itr++)
    {
        // If our sequence is there, increase
        // our current length as well as the
        // integer that represents the last
        // element of the sequence.
        if(*itr == current + 1)
        {
            len++;
            current += 1;
        }
        else
        {
            // We broke the sequence so time to 
            // check our lenght to the best one.
            if(bestLen < len)
                bestLen = len;
            
            // As well as assign our new start of the
            // sequence and setting the length to 1.
            current = *itr;
            len = 1;
        }
    }
    return bestLen < len ? len : bestLen;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums);
    
    return 0;
}