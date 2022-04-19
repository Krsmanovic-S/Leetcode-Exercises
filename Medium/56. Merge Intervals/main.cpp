#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> result;
    
    // Declare the queue and push the first interval.
    queue<vector<int>> q;
    q.push(intervals[0]);
    
    for(int i = 1; i < intervals.size(); i++)
    {
        // This is explained below the code.
        if(q.back()[1] >= intervals[i][0])
        {
            if(q.back()[1] < intervals[i][1])
                q.back()[1] = intervals[i][1];
        }
        else
            q.push(intervals[i]);
    }
    
    // Fill the result from the queue.
    while(!q.empty())
    {
        result.push_back(q.front());
        q.pop();
    }
    return result;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = merge(intervals);

    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}