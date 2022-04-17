#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Helper function to help  
// us sort the array.
static bool compare(int num1, int num2) {
    string s1 = to_string(num1);
    string s2 = to_string(num2);
    
    // If the first char isn't the
    // same, return the greater
    // char (in this case number).
    if(s1[0] != s2[0])
        return s1[0] > s2[0];
    
    // Otherwise check both
    // combinations of appending
    // and prepending both strings.
    return (s1 + s2) > (s2 + s1);
}

string largestNumber(vector<int>& nums) {
    string result;
    sort(nums.begin(), nums.end(), compare);
    
    for(auto x : nums)
        result += to_string(x);
    
    // If result starts with a zero
    // just return the one zero.
    if(result[0] == '0')
        return "0";
    
    return result;
}

int main()
{
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << largestNumber(nums);

    return 0;
}