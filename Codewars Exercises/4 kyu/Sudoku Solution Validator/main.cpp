#include <iostream>
#include <vector>

bool validSolution(unsigned int board[9][9]){
  
  using ui = unsigned int;
  
  // Check the columns for repeating numbers
  // If found, return false and close the function
  for(ui i = 0; i < 9; i++)
    {
    ui count = 0;
    ui temporaryColumn = board[0][i];
        for(ui j = 0; j < 9; j++)
        {
            if(temporaryColumn == board[0][j])
            count++;
        }
    if(count >= 2)
      return false;
  }
  
  // Check the rows for repeating numbers
  // Same logic as for the rows
  for(ui i = 0; i < 9; i++)
    {
    ui count = 0;
    ui temporaryRow = board[i][0];
        for(ui j = 0; j < 9; j++)
        {
            if(temporaryRow == board[j][0])
            count++;
        }
    if(count >= 2)
      return false;
  }

  // Individual 3x3 square check for the repeating number
  std::vector<ui> tempBoard;
  ui indexLimitRow { 3 };
  ui indexLimitColumn { 3 }; // 6
  
 while(indexLimitRow <= 9)
 {
    while(indexLimitColumn <= 9)
    {
        for(ui k = indexLimitRow - 3; k < indexLimitRow; k++)
        {
            ui tempRow_2 = board[k][0]; 
            for(ui n = indexLimitColumn - 3; n < indexLimitColumn; n++)
            {
            tempBoard.push_back(board[k][n]);
            }
        }

        // Check the 3x3 matrix for duplicate numbers,
        // if found, return false
        for(auto i : tempBoard)
        {
            ui count = 0;
            for(auto j : tempBoard)
            {
                if(i == j)
                count++;
            }
            if(count >= 2)
            return false;
        }

        tempBoard.clear(); // Clear the temporary matrix
        indexLimitColumn += 3;
    }
    indexLimitColumn = 3; // Reset the column
    indexLimitRow += 3;
 }

  return true;
}

int main()
{
    unsigned int board [9][9] = {
    5, 3, 4, 6, 7, 8, 9, 1, 2,
    6, 7, 2, 1, 9, 5, 3, 4, 8,
    1, 9, 8, 3, 4, 2, 5, 6, 7,

    8, 5, 9, 7, 6, 1, 4, 2, 3,
    4, 2, 6, 8, 5, 3, 7, 9, 1,
    7, 1, 3, 9, 2, 4, 8, 5, 6,

    9, 6, 1, 5, 3, 7, 2, 8, 4,
    2, 8, 7, 4, 1, 9, 6, 3, 5,
    3, 4, 5, 2, 8, 6, 1, 7, 9
    };

    bool result = validSolution(board);
    std::cout << std::boolalpha;
    std::cout << result;
    return 0;
}