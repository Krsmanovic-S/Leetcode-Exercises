#include <iostream>
#include <string>

using namespace std;

static bool isVowel(char c) {
    char d = tolower(c);

    return (d == 'a') || (d == 'e') ||(d == 'i') ||(d == 'o') ||(d == 'u'); 
}

string reverseVowels(string& s) {
    int start = 0, end = s.length() - 1;
    char t1, t2;
    
    while(start < end)
    {
        t1 = s[start];
        t2 = s[end];
        
        // Disaster if-chain but hey it works!
        if(isVowel(t1) && isVowel(t2))
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
        else if(isVowel(t1) && !isVowel(t2))
            end--;
        else if(isVowel(t2) && !isVowel(t1))
            start++;
        else
        {
            start++;
            end--;
        }
    }
    return s;
}

int main()
{
    string s = "leetcode";

    cout << reverseVowels(s);

    return 0;
}