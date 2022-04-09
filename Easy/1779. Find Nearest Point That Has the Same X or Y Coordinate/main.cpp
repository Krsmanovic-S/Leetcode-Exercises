#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> intPair;

// Function that will help us compare the two point distances.
static bool comparePoint(intPair a, intPair b)
{
    // If the distance is the same, prefer
    // the element with the smallest index.
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int size = points.size(), distance;
    vector<intPair> validPoints;
    
    vector<int> currentPoint;
    for(int i = 0; i < size; i++)
    {
        currentPoint = points[i];
        
        // First we check do we have a match for our own point,
        // since that distance will be 0 and it can't be lower than that.
        if(currentPoint[0] == x && currentPoint[1] == y)
            return i;
        
        // If the point matches what we are looking for, calculate
        // it's distance and push it onto validPoints, where we store
        // pairs<index in points, their distance to our point>.
        if(currentPoint[0] == x || currentPoint[1] == y)
        {
            distance = abs(x - currentPoint[0]) + abs(y - currentPoint[1]);
            validPoints.push_back({i, distance});
        }
    }
    
    // If we find no valid points after the for-loop, we just return -1.
    if(validPoints.empty()) return -1;
    
    // Now we sort the temp vector according to the lowest distance from us
    // and we want to return the first element (smallest distance to our point).
    sort(validPoints.begin(), validPoints.end(), comparePoint);
    
    return validPoints[0].first;
}

int main()
{
    vector<vector<int>> points = { {1, 2}, {3, 1}, {2, 4}, {2, 3}, {4, 4} };
    int x = 3, y = 4;

    cout << nearestValidPoint(x, y, points);

    return 0;
}