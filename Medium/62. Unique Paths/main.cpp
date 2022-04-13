#include <iostream>
#include <vector>

using namespace std;

// We use a matrix here to remember where we were so that we don't
// need to calculate multiple same paths over and over again.
int helper(int i, int j, int n, int m, vector<vector<int>>& matrix)
{
    // Base cases
    if(i == n || j == m)
        return 0;
    if(i == n - 1 && j == m - 1 )
        return 1;
    if(matrix[i][j] != -1) 
        return matrix[i][j];
    
    // If we didn't arrive at a base case and this position was never
    // reached, we want to calculate it and remember the value in that square.
    matrix[i][j] = helper(i + 1, j, n, m, matrix) + helper(i, j + 1, n, m, matrix);
    
    return matrix[i][j];    
}

int uniquePaths(int m, int n) {
    // Initialize a matrix with the size of m * n with all values
    // of -1 which means that we didn't visit that square.
    vector<vector<int>> matrix (m, vector<int>(n, -1));
    return helper(0, 0, m, n, matrix);
}

int main()
{
    int m = 20, n = 17;
    
    cout << uniquePaths(m, n);

    return 0;
}