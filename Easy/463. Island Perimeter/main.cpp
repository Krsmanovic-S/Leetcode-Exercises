#include <iostream>
#include <vector>

using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    int col = grid.size(), row = grid[0].size();
    int perimeter = 0, cellPerimeter = 4;
    
    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < row; j++)
        {
            if(grid[i][j] == 1)
            {
                cellPerimeter = 4;
                
                // Check left and right for adjecent land.
                if(j != 0)
                {
                    if(grid[i][j - 1] == 1) cellPerimeter--;
                }
                if(j != row - 1)
                {
                    if(grid[i][j + 1] == 1) cellPerimeter--;
                }
                
                // Check above and below for adjecent land.
                if(i != 0)
                {
                    if(grid[i - 1][j] == 1) cellPerimeter--;
                }           
                if(i != col - 1)
                {
                    if(grid[i + 1][j] == 1) cellPerimeter--;
                }
                perimeter += cellPerimeter;
            }
        }
    }
    return perimeter;
}

int main()
{
    vector<vector<int>> grid = {{ 0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    cout << islandPerimeter(grid);
    
    return 0;
}