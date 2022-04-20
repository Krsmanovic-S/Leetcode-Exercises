#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char, int> map;
    
    // Map the characters order, lower numbers mean
    // that character comes earlier than the higher
    // numbered ones.
    for(int i = 0; i < order.length(); i++)
        map[order[i]] = i;
    
    int len;
    string currentWord, nextWord;
    for(int i = 0; i < words.size() - 1; i++)
    {
        currentWord = words[i];
        nextWord = words[i + 1];
        
        // Assign the length to the shorter string so
        // we don't go out of bounds in the for-loop below.
        if(currentWord.length() > nextWord.length())
            len = nextWord.length();
        else
            len = currentWord.length();
        
        // This is for the cases like "apple" and "app",
        // i.e. one string is a substring of another.
        if(currentWord.length() != len)
        {
            // If the first word contains the 2nd as it's substring
            // but its also longer than the next word, this returns false.
            if(currentWord.substr(0, len) == nextWord) 
                return false;
        }
    
        // Now check for the order between the two words,
        // if the mapped value for the first words letter
        // is higher than the second, that means its not sorted.
        for(int j = 0; j < len; j++)
        {
            if(map[currentWord[j]] > map[nextWord[j]])
                return false;
            if(map[currentWord[j]] < map[nextWord[j]])
                break;
        }
    }
    return true;
}

int main()
{
    vector<string> words = {"apple", "app"};
    string order = "abcdefghijklmnopqrstuvwxyz";

    cout << std::boolalpha;
    cout << isAlienSorted(words, order);

    return 0;
}