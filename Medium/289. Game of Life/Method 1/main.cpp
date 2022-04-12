#include <iostream>
#include <vector>

using namespace std;

// Check if we are in bounds when dealing with the neighbouring cells,
// some may be out of the grid and those we don't want to check at all.
bool isInBounds(int a, int b, int row, int col)
{
    return a >= 0 && a < row && b >= 0 && b < col;
}

void gameOfLife(vector<vector<int>>& board) {
    int row = board.size(), col = board[0].size();
    vector<vector<int>> copy = board;
    
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
            // This loop will go through our dx/dy arrays and apply their values
            // to i and j so we can check all neighbours if they are in bounds,
            // we are looking for the live cells here.
            for(int k = 0; k < 8; k++)
            {
                if(isInBounds(i + dx[k], j + dy[k], row, col) && copy[i + dx[k]][j + dy[k]] == 1)
                    liveNeighbours++;
            }
            
            // We look at the copy here and apply the changes one by one to the actual
            // board, this way we don't update one cell and then use it's altered state to
            // modify the others.
            if(copy[i][j] == 0 && liveNeighbours == 3)
                    board[i][j] = 1;
                
            if(copy[i][j] == 1 && (liveNeighbours < 2 || liveNeighbours > 3))
                    board[i][j] = 0;
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