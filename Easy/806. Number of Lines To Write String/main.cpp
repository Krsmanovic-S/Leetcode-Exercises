#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> numberOfLines(vector<int>& widths, string s) {
    unordered_map<char, int> map;
    vector<int> result(2);
    
    // Populate the map with each width of each char,
    // 97 is the ASCII code for the char 'a', from there
    // it will go until the last lowercase letter and assign
    // the width of the letter to it.
    for(int i = 0; i < widths.size(); i++)
        map[char(97 + i)] = widths[i];
    
    int sumSoFar = 0, totalLines = 0, lastLine = 0;
    
    // Run through the string and add each letters width to the
    // sum so far. If it exceeds 100, we have a full line and new
    // sum should be that value that exceeded us over 100.
    for(int j = 0; j < s.length(); j++)
    {
        sumSoFar += map[s[j]];
    
        if(sumSoFar > 100)
        {
            totalLines++;
            sumSoFar = map[s[j]];
        }
    }
    
    // Last line is what we have left over, totalLines needs
    // to be incremented by 1 just so it includes the last line
    // as well.
    lastLine = sumSoFar;
    result[0] = totalLines + 1;
    result[1] = lastLine;
    
    return result;
}

int main()
{
    vector<int> widths = {4,6,10,10,10,10,10,10,10,5,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10}; 
    string s = "abcdefghijklmnopqrstuvwxyz";

    vector<int> result = numberOfLines(widths, s);
    for(auto x : result)
        cout << x << " ";

    return 0;
}