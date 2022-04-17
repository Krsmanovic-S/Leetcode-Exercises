#include <iostream>
#include <vector>
#include <string>

using namespace std;

string digitSum(string s, int k) {
    vector<string> round;
    int index = 0, digitSum;
    string copy, sub;
    
    while(k < s.length())
    {
        copy = s;
        s.clear();
        index = 0;
        
        // Divide
        while(index + k <= copy.size())
        {
            sub = copy.substr(index, k);
            round.push_back(sub);
            index += k;
        }
        
        // If we had a k that is larger than the array
        // size for the last element.
        if(index != copy.size())
        {
            sub = copy.substr(index, copy.size() - index);
            round.push_back(sub);
        }
        
        // Replace & Merge
        for(int i = 0; i < round.size(); i++)
        {
            for(int j = 0; j < round[i].length(); j++)
            {
                digitSum += round[i][j] - '0';
            }
            
            s += to_string(digitSum);
            digitSum = 0;
        }
        
        round.clear();
    }
    return s;
}

int main()
{
    string s = "11111222223";
    int k = 3;

    cout << digitSum(s, k);

    return 0;
}