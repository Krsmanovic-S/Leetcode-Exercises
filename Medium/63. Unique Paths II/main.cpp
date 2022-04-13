#include <iostream>
#include <vector>

using namespace std;

// Create a matrix and set all values to -1, we will use this to track
// where we have been on the grid. We will traverse from the ending square
// to the starting (0, 0) one.
vector<vector<int>> visited = vector<vector<int>>(101,vector<int>(101,-1));

int helper(int i,int j, vector<vector<int>>& matrix)
{
    // If we hit an obstacle or we are out of bounds
    // just return 0.
    if(i < 0 || j < 0) return 0;
    if(matrix[i][j]) return 0;
    
    // We made it to the desired destination!
    if(i == 0 && j == 0)
        return 1;
    
    // If we calculated the number of paths till this square just return it,
    // don't calculate more than once if we already know the value!
    if(visited[i][j] != -1)
        return visited[i][j];
    else
        visited[i][j] = helper(i-1, j, matrix) + helper(i, j-1, matrix);
    
    return visited[i][j];
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size() - 1, n = obstacleGrid[0].size() - 1;
    
    return helper(m, n, obstacleGrid);
}

int main()
{
    vector<vector<int>> nums ={{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}};
    cout << uniquePathsWithObstacles(nums);

    return 0;
}