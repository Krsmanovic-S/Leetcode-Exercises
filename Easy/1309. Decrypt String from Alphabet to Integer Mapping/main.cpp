#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string freqAlphabets(string s) {
    unordered_map<int, char> map;
    string result;

    // Map all the characters from the ASCII table.
    for(int i = 1; i < 27; i++)
        map[i] = char(96 + i);

    string current;
    for(int i = s.length() - 1; i >= 0; i--)
    {
        // If there is no #, just add the letter.
        if(s[i] != '#')
            result += map[(s[i] - '0')];
        else
        {
            // If we encounter a #, create
            // a string and add two characters
            // that are before the index i
            // and use them to get the value we need.
            current += s[i - 2];
            current += s[i - 1];
            i -= 2;
            result += map[stoi(current)];
            current.clear();
        }
    }

    // Result is backwards so we need to reverse it.
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string s = "10#11#12";
    cout << freqAlphabets(s);
    
    return 0;
}