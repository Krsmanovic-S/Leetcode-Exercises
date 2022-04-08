#include <iostream>
#include <string>

using namespace std;

string removeKdigits(string num, int k) {
    string result = "";
    int size = num.size(), len = result.length();

    // Base cases that we know the result of.
    if(k == size) return "0";
    if(k == 0) return num;
    
    for(auto i : num)
    {
        // Check the length and if we have more to remove first, then see
        // if the back digit of result is greater than the current one,
        // if it is keep removing the back char until we either remove all 
        // that we need (k == 0) or we hit a lesser/equal digit.
        while(len && k && result.back() > i)
        {
            result.pop_back();
            k--;
            len--;
        }
        
        // This is so we don't add trailing zeros.
        if(len != 0 || i != '0')
        {
            result.push_back(i);
            len++;
        }
    }
    
    // Remove remaining numbers if we still have to. The erasing
    // is done from the back of the result because we know that the
    // highest numbers are on the right, not on the left!
    while(len && k)
    {          
        result.pop_back();
        k--;
        len--;
    }
    
    if(len == 0) return "0";
    
    return result;
}

int main()
{
    string num = "1432219"; 
    int k = 3;

    string result = removeKdigits(num, k);
    cout << result;

    return 0;
}