#include <iostream>
#include <string>

using namespace std;

string removeDuplicates(string s) {
    // Declare result and initialize it
    // to the first character in s.
    string result;
    result += s[0];
    
    // Now we loop through s from the 2nd char onwards.
    for(int i = 1; i < s.length(); i++)
    {
        // Add the character if result is empty or
        // the last character of result isn't the
        // currently viewed one.
        if(result.empty() || result.back() != s[i])
            result += s[i];
        // Otherwise we pop the last char from result.
        else
            result.pop_back();
    }
    return result;
} 

int main()
{
    string s = "abbaca";
    cout << removeDuplicates(s);
    
    return 0;
}