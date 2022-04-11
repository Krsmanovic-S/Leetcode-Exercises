#include <iostream>

bool isPerfectSquare(int num) {
    int start = 0, end = num;
    unsigned long long mid;
    
    while(start <= end)
    {
        mid = (start + end) / 2;
        
        if(mid * mid == num) return true;
        
        if(mid * mid > num)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return false;
}

int main()
{
    int num = 2333556;
    std::cout << isPerfectSquare(num);

    return 0;
}