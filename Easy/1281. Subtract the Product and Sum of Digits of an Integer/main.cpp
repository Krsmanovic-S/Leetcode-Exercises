#include <iostream>

int subtractProductAndSum(int n) {
    unsigned long long multiply = 1, sum = 0;
    int digit = 0, num = n;
    
    // First get the multiply sum.
    while(num)
    {
        digit = num % 10;
        num /= 10;
        multiply *= digit;
    }
    
    // Reset num to be equal to n for the second
    // round of getting the digits.
    num = n;
    
    // Then get the sum of digits.
    while(num)
    {
        digit = num % 10;
        num /= 10;
        sum += digit;
    }
    
    // Return what the exercise requires of us
    return multiply - sum;
}

int main()
{
    int n = 4223;

    std::cout << subtractProductAndSum(n);

    return 0;
}