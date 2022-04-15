#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int titleToNumber(string columnTitle) {
    unordered_map<char, int> map;
    int val = 1;
    
    // For uppercase letters ASCII values
    // go from 65 to 90, let's map them first.
    for(int i = 65; i <= 90; i++)
    {
        map[char(i)] = val;
        val++;
    }

    val = map[columnTitle[0]];
    
    // For every other letter in the string other than
    // the first one, we need to multiply the result by 26
    // (there are 26 total letters) and add the remaining value
    // of that letter to the value.
    for(int j = 1; j < columnTitle.length(); j++)
    {
        val *= 26;
        val += map[columnTitle[j]];                
    }
    
    return val;
}

int main()
{
    string columnTitle = "ABCDEFG";
    cout << titleToNumber(columnTitle);

    return 0;
}