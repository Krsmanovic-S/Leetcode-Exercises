#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> result;
    
    // Matrix to keep track of where we already went in the
    // original matrix.
    vector<vector<int>> visited = matrix;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            visited[i][j] = -1;
    
    int i = 0, j = 0;
    bool check = true;
    
    // We loop until the result has the same size as the matrix,
    // meaning we visited each node in the original matrix.
    while(result.size() < (m * n))
    {
        // First order is to go from left -> right then from up -> down.
        if(check)
        {
            while(j < n && visited[i][j] == -1)
            {
                result.push_back(matrix[i][j]);
                visited[i][j] = 1;
                j++;
            }
            
            j--, i++;
            
            while(i < m && visited[i][j] == -1)
            {
                result.push_back(matrix[i][j]);
                visited[i][j] = 1;
                i++;             
            }
            
            j--, i--;
            
            check = !check;
        }
        // Second order is from right -> left and then from down -> up.
        else
        {
            while(j > -1 && visited[i][j] == -1)
            {
                result.push_back(matrix[i][j]);
                visited[i][j] = 1;
                j--;
            }
            
            j++, i--;
            
            while(i > -1 && visited[i][j] == -1)
            {
                result.push_back(matrix[i][j]);
                visited[i][j] = 1;
                i--;             
            }
            
            j++, i++;                
            
            
            check = !check;
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> matrix = { { 1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
    vector<int> result = spiralOrder(matrix);

    for(auto x : result)
        cout << x << " ";

    return 0;
}