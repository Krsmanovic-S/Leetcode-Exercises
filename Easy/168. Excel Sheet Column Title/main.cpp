#include <iostream>
#include <string>

std::string convertToTitle(int columnNumber) {
    std::string result;
    int currentLetter;
    
    while(columnNumber>26) 
    {
        currentLetter = columnNumber % 26;
        if(currentLetter == 0) 
        {
            currentLetter = 26;
            columnNumber--;
        }
        result = char((int)'A' + currentLetter - 1) + result;
        columnNumber /= 26;
    }
    
    if(columnNumber) 
        result = char((int)'A'+ columnNumber - 1) + result;
    
    return result;
}

int main()
{
    int columnNumber = 701;
    std::cout << convertToTitle(columnNumber);
    
    return 0;
}