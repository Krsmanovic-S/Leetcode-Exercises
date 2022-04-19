#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    set<pair<int,int>> set;
    unordered_map<int,int> map;
    vector<int> result(k, 0);
    
    // Make a pair out the vectors from logs
    // and insert them into the set as such.
    for(int i = 0; i < logs.size(); i++)
        set.insert(make_pair(logs[i][0],logs[i][1]));
    
    // Now traverse the set and use a map to check
    // which user was active for how long.
    for(auto i : set)
        map[i.first]++;

    // Finally go through the map again and
    // increment the resulting vector according
    // to each persons UAM (thats the pos in our result).
    for(auto i : map)
        result[i.second-1]++;
    
    return result;
}

int main()
{
    vector<vector<int>> logs = {{0, 5}, {1, 2}, {0, 2}, {0, 5}, {1, 3}};
    int k = 5;

    vector<int> result = findingUsersActiveMinutes(logs, k);

    for(auto i : result)
        cout << i << " ";

    return 0;
}