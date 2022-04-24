#include <iostream>
#include <string>

using namespace std;

bool repeatedSubstringPattern(string s) {
    string substring, current;
    int len = 1;

    // len indicates the current length
    // of a substring we are looking at.
    while(len <= s.length() / 2)
    {
        substring = s.substr(0, len);
        
        // Fill up current until its size matches s
        // with the current substring we have.
        while(current.length() < s.length())
            current += substring; 

        // If at any point current matches to s,
        // we can do an early return true.        
        if(current == s)
            return true;
        
        current.clear();
        len++;
    }
    
    return false;
}

int main()
{
    string s = "abba";
    cout << repeatedSubstringPattern(s);

    return 0;
}