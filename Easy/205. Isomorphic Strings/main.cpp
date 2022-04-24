#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char, int> map_1;
    unordered_map<char, int> map_2;
    
    // Populate the two maps in regards to
    // each characters position in s/t.
    for(int i = 0; i < s.length(); i++)
    {
        map_1[s[i]] = i + 1;
        map_2[t[i]] = i + 1;
    }
    
    // Now just go through the maps and look
    // at each characters place in and if
    // they don't match, return false.
    for(int i = 0; i < s.length(); i++)
        if(map_1[s[i]] != map_2[t[i]]) return false;
    
    return true;
}

int main()
{
    string s = "egg", t = "add";
    cout << boolalpha;

    cout << isIsomorphic(s, t);
    
    return 0;
}