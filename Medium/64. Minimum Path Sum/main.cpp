#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int sum(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp)
{
    // Out of bounds case.
    if(i >= m||i < 0|| j >= n|| j < 0)
        return INT_MAX;
    // If we already know the sum for that tile,
    // just return it, don't calculate again.
    if(dp[i][j] != INT_MAX)
        return dp[i][j];
    
    // Calculate the sum up to this tile.
    dp[i][j] = grid[i][j] + min(sum(i - 1, j, m, n, grid, dp),sum(i, j - 1, m, n, grid, dp));
    
    return dp[i][j];
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    
    // Initialize a vector of the same size as the grid,
    // just put each cells value as INT_MAX.
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    
    // First cells value (top-right corner) is known from the start.
    dp[0][0] = grid[0][0];
    
    return sum(m - 1, n - 1, m, n, grid, dp);
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum(grid);
    
    return 0;
}