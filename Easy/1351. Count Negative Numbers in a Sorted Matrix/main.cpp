#include <iostream>
#include <vector>

using namespace std;

int helper(vector<int>& grid, int start, int end)
{
    // Binary search implementation,
    // we are looking at the first occurence
    // of a negative number.
    int mid;
    while(start <= end)
    {
        mid = (start + end) / 2;
        
        // Move start or end depending on
        // if middle element is greater/equal to 0.
        if(grid[mid] >= 0)
            start = mid + 1;
        else
            end = mid - 1;
    }
    
    // Once we found it just return the amount
    // of negative numbers in that one row.
    // Start points to the first negative number here.
    return grid.size() - start;
}

int countNegatives(vector<vector<int>>& grid) {
    int result = 0;
    
    // Loop through each row and calculate the amount
    // of negative numbers with the helper function.
    for(int i = 0; i < grid.size(); i++)
        result += helper(grid[i], 0, grid[i].size() - 1);
    
    return result;
}

int main()
{
    vector<vector<int>> grid = {
    {4, 3, 2, -1},
    {3, 2, 1, -1},
    {1, 1, -1, -2},
    {-1, -1, -2, -3}
    };

    cout << countNegatives(grid);

    return 0;
}