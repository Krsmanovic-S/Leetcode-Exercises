#include <iostream>
#include <string>

using namespace std;

bool isSubsequence(string& s, string& t) {
    // Base cases, length can be 0 for both strings
    // according to the constraints.
    if(s.empty()) return true;
    if(t.empty()) return false; 

    int index = 0;
    bool found = true;
    while(found)
    {
        found = false;
        for(int i = index; i < t.length(); i++)
        {
            if(t[i] == s[0])
            {      
                index = i;
                found = true;
                
                s.erase(s.begin() + 0);    
                t.erase(t.begin() + i);
        
                break;
            }
        }
    }
    
    // If we found all letters, return true,
    // otherwise return false.
    if(s.empty())
        return true;
    else
        return false;
}

int main()
{
    string s = "abc", t = "ahbgdc";
    cout << boolalpha;
    
    cout << isSubsequence(s, t);
    
    return 0;
}