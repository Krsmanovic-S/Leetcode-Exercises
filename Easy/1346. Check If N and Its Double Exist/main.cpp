#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool checkIfExist(vector<int>& arr) {
    unordered_set<int> set;
    
    for(int current : arr)
    {
        // If element isn't in the set, insert it.
        // A zero will guarantee a true if we already have
        // one zero in the array (0 == 2 * 0).
        if(set.find(current) == set.end())
            set.insert(current);
        else if(current == 0 && set.find(current) != set.end()) 
            return true;

        // For other elements we check if there is a double version
        // of them already in the set.
        if(current != 0 && set.find(current * 2) != set.end()) 
            return true;
        // Check if half of current is in the set, then compare
        // if two times the half is equal to current, this is for
        // cases where an odd integer appears (5 / 2 = 2);
        else if(current != 0 && set.find(current / 2) != set.end() &&
                (current / 2) * 2 == current)
            return true;
    }
    return false;
}

int main()
{
    vector<int> nums = {10, 2, 5, 3};
    
    cout << boolalpha;
    cout << checkIfExist(nums);

    return 0;
}