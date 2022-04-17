#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    vector<string> result;
    
    if(s.length() < 10)
        return result;
    
    unordered_map<string, int> map;
    string sub;
    
    // Map all the possible substrings of length 10.
    for(int i = 0; i < s.length() - 9; i++)
    {
        sub = s.substr(i, 10);
        map[sub]++;
    }
    
    // If any string occurs more than
    // once, we add it to result.
    for(auto x : map)
    {
        if(x.second > 1)
            result.push_back(x.first);
    }
    
    return result;
}

int main()
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> result = findRepeatedDnaSequences(s);

    for(auto x : result)
        cout << x << '\n';

    return 0;
}