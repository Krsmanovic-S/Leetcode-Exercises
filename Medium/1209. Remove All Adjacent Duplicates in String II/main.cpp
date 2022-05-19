#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string removeDuplicates(string& s, int k) {
    if(s.length() < k) return s;
    
    // Declare a stack to hold pairs that represent
    // a character and how many times it appeared.
    stack<pair<char, int>> stk;
    
    for(int i = 0; i < s.length(); i++)
    {
        if(stk.empty() || stk.top().first != s[i])
            stk.push({s[i], 1});
        else
            stk.top().second++;        
        
        if(stk.top().second == k)
            stk.pop();
    }
    
    // Repopulate s from the stack.      
    s.clear();
    while(!stk.empty())
    {
        s += string(stk.top().second, stk.top().first);
        stk.pop();
    }
    
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    string s = "pbbcggttciiippooaais";
    int k = 2;

    cout << removeDuplicates(s, k);

    return 0;
}