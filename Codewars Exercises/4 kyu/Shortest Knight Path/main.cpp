#include <iostream>
#include <string>

int knight(std::string start, std::string finish)
{
    using ui = unsigned int;

    ui board[8][8], startColumnIndex, endColumnIndex;

    ui startRowIndex = start[1] - '0'; 
    ui endRowIndex = finish[1] - '0';

    std::cout << "Start Index: " << startRowIndex << "\nEnd Index: " << endRowIndex;

    switch (start[0])
    {
        case 'a' :  startColumnIndex = 0; break;
        case 'b' :  startColumnIndex = 1; break;
        case 'c' :  startColumnIndex = 2; break;
        case 'd' :  startColumnIndex = 3; break;
        case 'e' :  startColumnIndex = 4; break;
        case 'f' :  startColumnIndex = 5; break;
        case 'g' :  startColumnIndex = 6; break;
        case 'h' :  startColumnIndex = 7; break;
        default: break;
    }
        switch (finish[0])
    {
        case 'a' :  endColumnIndex = 0; break;
        case 'b' :  endColumnIndex = 1; break;
        case 'c' :  endColumnIndex = 2; break;
        case 'd' :  endColumnIndex = 3; break;
        case 'e' :  endColumnIndex = 4; break;
        case 'f' :  endColumnIndex = 5; break;
        case 'g' :  endColumnIndex = 6; break;
        case 'h' :  endColumnIndex = 7; break;
        default: break;
    }

    

    // Calculate all possible moves from a given square
    // first -> column+- 2 + row+-1
    // second -> row+- 2 + column+-1
    bool inBounds = true;
    while(inBounds)
    {
        


    }


  return 0;
}

int main()
{
    std::string start { "a1" };
    std::string end {"c1" };

    knight(start, end);

    return 0;
}