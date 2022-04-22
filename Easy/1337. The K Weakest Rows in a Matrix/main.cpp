#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// This is used to compare the rows and sort them by
// the lower amount of soldiers. If we have the same
// amount of soldiers, sort by the lower row number.
static bool sortPair(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

// Helper function that counts the soldiers in one row.
int helper(vector<int>& row, int start, int end) {
    int soldiers = 0;
    while(start <= end)
    {
        if(row[start] == 1)
        {
            soldiers++;
            start++;
        }
        else
            break;
    }
    return soldiers;
}

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<pair<int, int>> soldierCount;
    
    // Get all the pairs (row number, soldiers)
    // into a vector to hold them.
    pair<int, int> current;
    for(int i = 0; i < mat.size(); i++)
    {
        current.first = i;
        current.second = helper(mat[i], 0, mat[i].size() - 1);
        soldierCount.push_back(current);
    }
    
    // Sort the vector so that the weakest rows are first.
    sort(soldierCount.begin(), soldierCount.end(), sortPair);
    vector<int> result;
    
    // Fill out the result.
    for(int i = 0; i < k; i++)
        result.push_back(soldierCount[i].first);
    
    return result;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };
    int k = 3;

    vector<int> result = kWeakestRows(mat, k);
    for(auto x : result)
        cout << x << " ";

    return 0;
}