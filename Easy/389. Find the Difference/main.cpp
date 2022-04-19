#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char findTheDifference(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    
    for(int i = 0; i < t.length(); i++)
        if(s[i] != t[i]) return t[i];
    
    return '?';
}

int main()
{
    string s = "abcd", t = "abcde";
    cout << findTheDifference(s, t);
    
    return 0;
}