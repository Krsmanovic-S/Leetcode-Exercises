#include <iostream>
#include <string>

using namespace std;

string mergeAlternately(string word1, string word2) { 
    string result;
    int ptr1 = 0, ptr2 = 0;
    
    // Two pointers used to track both words.
    while(ptr1 != word1.length() && ptr2 != word2.length())
    {
        result += word1[ptr1++];
        result += word2[ptr2++];
    }
    
    // Append the last remaining letters from the larger string.
    if(ptr2 == word2.length())
        return result.append(word1.begin() + ptr1, word1.end());
    
    return result.append(word2.begin() + ptr2, word2.end());
}

int main()
{
    string word1 = "abcd", word2 = "pq";
    cout << mergeAlternately(word1, word2);

    return 0;
}