#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> point;

// This function will help us sort the vector contianing the
// indexes as first param and distance as the second.
static bool comparePoint (point a, point b) {
    return a.second < b.second;
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    int size = points.size(), distance;
    
    // Temp stores pairs<index in points, distance from (0, 0)> and result
    // will just hold the points which we return at the end.
    vector<point> temp;
    vector<vector<int>> result;
    
    // Populate the temp vector with pairs of indexes from points and their
    // distance to the (0, 0) point.
    for(int i = 0; i < size; i++)
    {
        distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        temp.push_back({i, distance});
    }

    // We sort the temp vector according to our helper function which will
    // sort by distance.
    sort(temp.begin(), temp.end(), comparePoint);
    
    // Lastly we just need to fill the result with the first k-elements.
    for(int j = 0; j < k; j++)
        result.push_back(points[temp[j].first]);
    
    return result;
}

int main()
{
    vector<vector<int>> points = {
        {2, 10}, {-9, -9}, {0, 8}, {-2, -2}, {8, 9}, {-10, -7}, {-5, 2}, {-4, -9}
    };
    int target = 7;

    vector<vector<int>> result = kClosest(points, target);
    
    return 0;
}