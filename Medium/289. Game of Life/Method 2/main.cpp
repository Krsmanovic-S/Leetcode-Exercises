#include <iostream>
#include <vector>

using namespace std;

// Check if we are in bounds when dealing with the neighbouring cells,
// some may be out of the grid and those we don't want to check at all.
bool isInBounds(int a, int b, int row, int col) {
    return a >= 0 && a < row && b >= 0 && b < col;
}

// Track the state of the cell so we can do changes in place without affecting
// the entire grid with the cells updated status.
int currentState(int x, bool wasAlive) {
    if(wasAlive)
    {
        if(x < 2 || x > 3)
            return -1;
        
        return 1;
    }
    else
    {
        if(x == 3)
            return 2;
        
        return 0;
    }
}

void gameOfLife(vector<vector<int>>& board) {
    int row = board.size(), col = board[0].size();
    bool wasAlive;
    
    // Directions for all eight neighbouring cells,
    // row + dx and col + dy is going to be our neighbour,
    // keep in mind this goes in pairs, first dx/dy is (1, 0),
    // second is (1, 1) ecc..
    int dx [8] = {1, 1, 0, -1, -1, -1,  0,  1};
    int dy [8] = {0, 1, 1,  1, 0,  -1, -1, -1};
    
    int liveNeighbours;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            liveNeighbours = 0;
            
            if(board[i][j] == 1) wasAlive = true;
            else
                wasAlive = false;
            
            // Loop that checks the neighbouring cells.
            for(int k = 0; k < 8; k++)
            {
                if(isInBounds(i + dx[k], j + dy[k], row, col) && abs(board[i + dx[k]][j + dy[k]]) == 1)
                    liveNeighbours++;
            }
            
            // This will do all the heavy lifting for us, explanation is below the code.
            board[i][j] = currentState(liveNeighbours, wasAlive);
        }
    }
    
    // For the last part we need to go through the matrix and update our final values.
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(board[i][j] == -1)
                board[i][j] = 0;
            
            if(board[i][j] == 2)
                board[i][j] = 1;
        }
    }
    
    return;
}

int main()
{
    vector<vector<int>> board = { {0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0} };
    gameOfLife(board);

    int row = board.size(), col = board[0].size();

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}