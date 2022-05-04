#include <iostream>

int minMoves(int& target, int& maxDoubles, int result = 0) {
    while(target > 1 && maxDoubles)
    {
        if(target % 2 == 0)
        {
            target /= 2;
            maxDoubles--;
        }
        else
            target--;
        result++;
    }
    return result + target - 1;
}

int main()
{
    int target = 20, maxDoubles = 2;
    std::cout << minMoves(target, maxDoubles);

    return 0;
}