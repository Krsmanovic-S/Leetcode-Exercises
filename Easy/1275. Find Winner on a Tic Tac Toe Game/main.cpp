#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef vector<vector<int>> matrix;

matrix field = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};

string checkGrid(matrix& field) {
    // Check rows for a winner.
    for(int i = 0; i < 3; i++)
    {
        if(field[i][0] == 1 && field[i][1] == 1 && field[i][2] == 1)
            return "A";
        else if(field[i][0] == 2 && field[i][1] == 2 && field[i][2] == 2)
            return "B";
    }

    // Check columns for a winner.
    for(int j = 0; j < 3; j++)
    {
        if(field[0][j] == 1 && field[1][j] == 1 && field[2][j] == 1)
            return "A";
        else if(field[0][j] == 2 && field[1][j] == 2 && field[2][j] == 2)
            return "B";
    }

    // Check the two diagonals as well.
    if((field[0][0] == 1 && field[1][1] == 1 && field[2][2] == 1) ||
        (field[2][0] == 1 && field[1][1] == 1 && field[0][2] == 1))
        return "A";
    
    if((field[0][0] == 2 && field[1][1] == 2 && field[2][2] == 2) ||
        (field[2][0] == 2 && field[1][1] == 2 && field[0][2] == 2))
        return "B";
    
    return "0";
}

string tictactoe(matrix& moves) {
    int row, col;
    bool check = false;
    
    for(int i = 0; i < moves.size(); i++)
    {
        // Break out if we played 9 moves.
        if(i > 8) break;
        
        row = moves[i][0];
        col = moves[i][1];
        
        // Alternate the moves.
        if(!check)
            field[row][col] = 1;
        else
            field[row][col] = 2;
        check = !check;
    }
    
    // Now check the grid and then check
    // the result to see what we need to return.
    string result = checkGrid(field);
    
    if(result != "0") return result;
    else
    {
        if(moves.size() > 8)
            return "Draw";
        else
            return "Pending";
    }
}

int main()
{
    vector<vector<int>> moves = {
        {0,0},
        {2,0},
        {1,1},
        {2,1},
        {2,2}
    };
    cout << tictactoe(moves);

    return 0;
}