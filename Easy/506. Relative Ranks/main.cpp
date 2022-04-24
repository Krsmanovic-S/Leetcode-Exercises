#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
    // First we copy the scores, sort them and
    // reverse them (sorting form end gives some error).
    vector<int> copy = score;
    sort(copy.begin(), copy.end());
    reverse(copy.begin(), copy.end());
    
    // Now time to populate the result accordingly.
    vector<string> result;        
    for(int i = 0; i < score.size(); i++)
    {
        for(int j = 0; j < score.size(); j++)
        {
            if(copy[j] == score[i])
            {
                if(j == 0)
                    result.push_back("Gold Medal");
                else if(j == 1)
                    result.push_back("Silver Medal");
                else if(j == 2)
                    result.push_back("Bronze Medal");
                else
                    result.push_back(to_string(j + 1));
                
                break;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> score = {10, 3, 8, 9, 4};
    vector<string> result = findRelativeRanks(score);

    for(auto x : result)
        cout << x << " ";

    return 0;
}