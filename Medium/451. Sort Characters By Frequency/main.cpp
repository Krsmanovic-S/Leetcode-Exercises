#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// This function will help us to compare map values and then sort them.
static bool comparePair(pair<char,int> a, pair<char,int> b) {
    return a.second < b.second;
}

string frequencySort(string s) {
    int size = s.length();
    char currentChar;
    string result = "";
    unordered_map<char, int> count;
    
    // Fill the map with all the occurences
    for(int i = 0; i < size; i++)
    {
        currentChar = s[i];
        count[currentChar]++;
    }
    
    // Drag all the values from the map to a vector and
    // sort it, we will use this to populate result later.
    vector<pair<char, int>> v(count.begin(), count.end());
    sort(v.begin(), v.end(), comparePair);
    pair<char, int> currentPair;
    int occurrence;
    
    for(int j = v.size() - 1; j >= 0; j--)
    {
        currentPair = v[j];
        occurrence = currentPair.second;
        
        // Keep adding the letter as many times as it occurred.
        while(occurrence > 0)
        {
            result += currentPair.first;
            occurrence--;
        }
    }
    return result;
}

int main()
{
    string s = "cccaaa";
    string result = frequencySort(s);

    cout << result;

    return 0;
}