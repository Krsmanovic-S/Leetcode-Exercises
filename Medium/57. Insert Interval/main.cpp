#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    
    // Of course this case exists :( ...
    if(intervals.empty())
    {
        result.push_back(newInterval);
        return result;
    }

    // Find the position to insert the new interval,
    // we are looking at when its beginning is lower
    // than the next element in the vector.
    for(int i = 0; i < intervals.size(); i++)
    {
        if(newInterval[0] < intervals[i][0])
        {
            intervals.insert(intervals.begin() + i, newInterval);
            break;
        }                
        
        // This is if we need to add it to the end of the vector.
        if(i == intervals.size() - 1)
        {
            intervals.push_back(newInterval);
            break;
        }
    }
    
    // After this we sort the intervals
    // (it could have had its order disrupted),
    // declare our queue and push the first element.
    sort(intervals.begin(), intervals.end());
    queue<vector<int>> q;
    q.push(intervals[0]);
    
    // This is how we will sort each element as they come.
    // I explained this logic in depth in the 
    // 56. Merge Intervals exercise, check out my profile for it.
    for(int i = 1; i < intervals.size(); i++)
    {
        if(q.back()[1] >= intervals[i][0])
        {
            if(q.back()[1] < intervals[i][1])
                q.back()[1] = intervals[i][1];
        }
        else
            q.push(intervals[i]);               
    }
    
    // Now we just populate the result with the
    // values from the queue.
    while(!q.empty())
    {
        result.push_back(q.front());
        q.pop();
    }
    
    return result;
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}; 
    vector<int> newInterval = {4, 8};

    insert(intervals, newInterval);

    for(int i = 0; i < intervals.size(); i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cout << intervals[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}