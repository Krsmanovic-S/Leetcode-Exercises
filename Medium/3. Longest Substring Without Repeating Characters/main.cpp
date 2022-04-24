#include <iostream>
#include <vector>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    if(s.length() == 1) return 1;
    
    // Keep track of what letters did we already
    // visit, size is 256 to represent each char
    // (range of char is 1-255).
    vector<int> visited(256, -1);
    
    int start = 0;
    int bestLen = 0;    
    for(int i = 0; i < s.length(); i++)
    {
        start = max(start, visited[s[i]] + 1);

        bestLen = max(bestLen, i - start + 1);

        visited[s[i]] = i;
    }
        
    return bestLen;
}

int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);

    return 0;
}