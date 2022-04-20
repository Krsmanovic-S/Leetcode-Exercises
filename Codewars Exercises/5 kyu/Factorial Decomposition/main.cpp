#include <iostream>
#include <string>
#include <vector>
#include <cmath>

std::string decomp(int n) {

    using ui = unsigned int;
    ui increment = 2;
    std::string result;
    std::vector<ui> primeNumbers = { 2 };

    // Get all the prime numbers from 3 to n in the vector
    for(ui i = 3; i <= n; i += increment)
    {   
        bool isPrime = true; 
        for(ui j = 2; j<=sqrt(i); j++)
        {   
            if(i % j==0)
                isPrime = false; 
        }

        if(isPrime) 
            primeNumbers.push_back(i);
    }

    // Main loop to generate the string result    
    for(ui i = 0; i < primeNumbers.size(); i++)
    {
        ui tempPrime = primeNumbers[i];
        ui count = 0;
        for(ui j = n; j > 0; j--)
        {
            ui tempNum = j;
            while(tempNum % tempPrime == 0)
            {
                tempNum = tempNum / tempPrime;
                count++;
            }
        }

        // Check the count and do the format accordingly
        if(count != 0 && count != 1)
        {
            result += std::to_string(tempPrime) + "^" + std::to_string(count);
            result += " * ";
        }
        else if(count == 1)
        {
            result += std::to_string(tempPrime);
            result += " * ";
        }        
    }

    // Remove the last two characters so format is right
    result.pop_back();
    result.pop_back();

    return result;
}

int main()
{
    std::string result = decomp(98);

    std::cout << result;

    return 0;
}