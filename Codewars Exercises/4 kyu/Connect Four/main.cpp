#include <iostream>
#include <vector>
#include <string>

std::string checkGrid(unsigned int board[6][7])
{
    using ui = unsigned int;

    // Check the columns for the winner
    for(ui i = 0; i < 7; i++)
    {   
        int count = 0;
        for(ui j = 0; j < 6; j++)
        {
            if(board[j][i] == 1)
            {
                if(count > 0)
                    count++;
                else
                    count = 1;    
            }
            else if(board[j][i] == 2)
            {
                if(count > 0)
                    count = -1;
                else
                    count--;    
            }
            else if(board[j][i] == 0)
                count = 0;

            if(count == 4)
                return "Red";
            else if(count == -4)
                return "Yellow";        
        }
    }

    // Check the rows for the winner
    for(ui i = 0; i < 6; i++)
    {   
        int count = 0;
        for(ui j = 0; j < 7; j++)
        {
            if(board[i][j] == 1)
            {
                if(count > 0)
                    count++;
                else
                    count = 1;    
            }
            else if(board[i][j] == 2)
            {
                if(count > 0)
                    count = -1;
                else
                    count--;    
            }
            else if(board[i][j] == 0)
                count = 0;

            if(count == 4)
                return "Red";
            else if(count == -4)
                return "Yellow";
        }
    }

    // Initialize a vector to hold all numbers
    // from the diagonals of the grid and also
    // two variables to help us track them
    std::vector<ui> currentDiagonal;
    ui diagonal_1 = 0;
    ui diagonal_2 = 0;

    // Check for the right oriented diagonals
    for(int i = 2; i < 6; i++)
    {
        currentDiagonal.push_back(board[i][diagonal_1]);
        diagonal_1++;
    }
    currentDiagonal.push_back(9); // This will help us with checking the vector
    diagonal_1 = 0;

    for(int i = 1; i < 6; i++)
    {
        currentDiagonal.push_back(board[i][diagonal_1]);
        diagonal_1++;
    }
    currentDiagonal.push_back(9);
    diagonal_1 = 0;

    for(int i = 0; i < 6; i++)
    {
        currentDiagonal.push_back(board[i][diagonal_1]);
        diagonal_1++;
    }
    currentDiagonal.push_back(9);
    diagonal_1 = 1;

    for(int i = 0; i < 6; i++)
    {
        currentDiagonal.push_back(board[i][diagonal_1]);
        diagonal_1++;
    }
    currentDiagonal.push_back(9);
    diagonal_1 = 2;

    for(int i = 0; i < 5; i++)
    {
        currentDiagonal.push_back(board[i][diagonal_1]);
        diagonal_1++;
    }
    currentDiagonal.push_back(9);
    diagonal_1 = 3;

    for(int i = 0; i < 4; i++)
    {
        currentDiagonal.push_back(board[i][diagonal_1]);
        diagonal_1++;
    }
    currentDiagonal.push_back(9);


    // Check for the left oriented diagonals
    diagonal_2 = 3;
    for(int i = 0; i < 4; i++)
    {
        currentDiagonal.push_back(board[i][diagonal_2]);
        diagonal_2--;
    }
    currentDiagonal.push_back(9); // This will help us with checking the vector
    diagonal_2 = 4;

    for(int i = 1; i < 5; i++)
    {
        currentDiagonal.push_back(board[i][diagonal_2]);
        diagonal_2--;
    }
    currentDiagonal.push_back(9);
    diagonal_2 = 5;

    for(int i = 0; i < 6; i++)
    {
        currentDiagonal.push_back(board[i][diagonal_2]);
        diagonal_2--;
    }
    currentDiagonal.push_back(9);
    diagonal_2 = 6;

    for(int i = 0; i < 6; i++)
    {
        currentDiagonal.push_back(board[i][diagonal_2]);
        diagonal_2--;
    }
    currentDiagonal.push_back(9);
    diagonal_2 = 6;

    for(int i = 1; i < 6; i++)
    {
        currentDiagonal.push_back(board[i][diagonal_2]);
        diagonal_2--;
    }
    currentDiagonal.push_back(9);
    diagonal_2 = 6;

    for(int i = 2; i < 6; i++)
    {
        currentDiagonal.push_back(board[i][diagonal_2]);
        diagonal_2--;
    }

    // Check the vector for a winner
    int diagonalCount = 0;
    for(ui i = 0; i < currentDiagonal.size(); i++)
    {
        // Reset the count if we encounter a 9
        if(currentDiagonal[i] == 9 || currentDiagonal[i] == 0)
            diagonalCount = 0;
    
        if(currentDiagonal[i] == 1)
        {
            if(diagonalCount < 0)
                diagonalCount = 1;
            else
                diagonalCount++;
        }
        else if (currentDiagonal[i] == 2)
        {
            if(diagonalCount > 0)
                diagonalCount = -1;
            else
                diagonalCount--;    
        }

        if(diagonalCount == 4)
            return "Red";
        if(diagonalCount == -4)
            return "Yellow";       
    }

    return "";
}

std::string who_is_winner(std::vector<std::string> pieces_position_list)
{
    using ui = unsigned int;

    // Red will be represented by 1
    // Yellow will be represented by 2
    const ui red { 1 }, yellow { 2 };

    // Board initialization
    ui board [6][7] {};
    std::string currentMove;
    std::string result;

    // Translate the move
    for(ui i = 0; i < pieces_position_list.size(); i++)
    {
        currentMove = pieces_position_list[i];
        ui currentMoveColumn;
        char currentMoveColor = currentMove[2];
        switch(currentMove[0])
        {
            case 'A': currentMoveColumn = 0; break;
            case 'B': currentMoveColumn = 1; break;
            case 'C': currentMoveColumn = 2; break;
            case 'D': currentMoveColumn = 3; break;
            case 'E': currentMoveColumn = 4; break;
            case 'F': currentMoveColumn = 5; break;
            case 'G': currentMoveColumn = 6; break;
            default: break;
        }
        currentMove.clear();

        // Play the move
        for(ui j = 5; j >= 0; j--)
        {
            if(board[j][currentMoveColumn] == 0)
            {
                if(currentMoveColor == 'R')
                    board[j][currentMoveColumn] = red;
                else
                    board[j][currentMoveColumn] = yellow;

                break;    
            }
        }

        // Check the entire grid for the winner
        if(i > 6) // Only check after the 6th move, there can't be a winner before
        {
            result = checkGrid(board);
            if (result == "Red" || result == "Yellow")
            {
                // Print board for debugging
                for(ui i = 0; i < 6; i++)
                {
                    for(ui j = 0; j < 7; j++)
                    {
                    std::cout << board[i][j] << " ";
                    }
                std::cout << std::endl;
                }   
            return result;
            }   
        }      
    }
   return "Draw";
}

int main()
{
    // playingField [6-rows] [7-columns]
    // Rows are named from A to G
    // List may contain up to 42 moves
    std::vector<std::string> pieces_position_list
    {
        "C_Yellow",
        "B_Red",
        "B_Yellow",
        "E_Red",
        "D_Yellow",
        "G_Red",
        "B_Yellow",
        "G_Red",
        "E_Yellow",
        "A_Red",
        "G_Yellow",
        "C_Red",
        "A_Yellow",
        "A_Red",
        "D_Yellow",
        "B_Red",
        "G_Yellow",
        "A_Red",
        "F_Yellow",
        "B_Red",
        "D_Yellow",
        "A_Red",
        "F_Yellow",
        "F_Red",
        "B_Yellow",
        "F_Red",
        "F_Yellow",
        "G_Red",
        "A_Yellow",
        "F_Red",
        "C_Yellow",
        "C_Red",
        "G_Yellow",
        "C_Red",
        "D_Yellow",
        "D_Red",
        "E_Yellow",
        "D_Red",
        "E_Yellow",
        "C_Red",
        "E_Yellow",
        "E_Red"
    };

    std::string result = who_is_winner(pieces_position_list);
    std::cout << "Winner : " << result << "\n";

    return 0;
}