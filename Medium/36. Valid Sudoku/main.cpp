#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    if(board.empty()) return false;
    using ui = unsigned int;

    // We use this temp vector to track individual rows/columns,
    // as well as later use it for the 3x3 matrix.
    vector<char> temp;
    
    // Check the columns for repeating numbers,
    // add each column to a vector, traverse the vector for duplicates.
    for(ui i = 0; i < 9; i++)
    { 
    for(ui j = 0; j < 9; j++)
    {   
        if(board[j][i] == '.') continue;
        
        temp.push_back(board[j][i]);
    }
    if(temp.empty()) continue;  
        
    sort(temp.begin(), temp.end());
        
    for(int k = 0; k < temp.size() - 1; k++)
        if(temp[k] == temp[k+1]) return false;
    
    temp.clear();  
    }

    // Check the rows for repeating numbers,
    // same logic as for the columns.
    for(ui i = 0; i < 9; i++)
    {
    for(ui j = 0; j < 9; j++)
    {
        if(board[i][j] == '.') continue;
        
        temp.push_back(board[i][j]);
    }
    if(temp.empty()) continue;  
        
    sort(temp.begin(), temp.end());
        
    for(int k = 0; k < temp.size() - 1; k++)
        if(temp[k] == temp[k+1]) return false;
    
    temp.clear();  
    }
    
    // These variables are crucial for our selection of a 3x3 square,
    // we want to use them so we can select matrixes like this: 
    // 0-2 row/0-2 column, 3-5 row/0-2 column, 6-8 row/0-2 column ecc...
    ui indexLimitRow { 3 };
    ui indexLimitColumn { 3 };
    
    // Individual 3x3 square check for the repeating number.
    while(indexLimitRow <= 9)
    {
        while(indexLimitColumn <= 9)
        {
            // Fill out the 3x3 matrix first, then we check it.
            for(ui k = indexLimitRow - 3; k < indexLimitRow; k++)
            {
                for(ui n = indexLimitColumn - 3; n < indexLimitColumn; n++)
                {
                    temp.push_back(board[k][n]);
                }
            }

            // Check the 3x3 matrix for duplicate numbers,
            // if found, return false
            for(auto i : temp)
            {
                ui count = 0;
                for(auto j : temp)
                    if(i == j && j != '.') count++;
            
                if(count >= 2) return false;
            }

            // temp is cleared here, when we enter next iteration we
            // will fill it up with another 3x3 matrix.
            temp.clear();
            indexLimitColumn += 3;
        }
        indexLimitColumn = 3;
        indexLimitRow += 3;
    }
    return true;
}

int main()
{
    return 0;
}