#include <iostream>

// This is defined for us in the exercise.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int start = 1, end = n, mid;
    bool check;
    
    while(start <= end)
    {
        mid = start + (end - start) / 2;
        
        check = isBadVersion(mid);
        
        if(check)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}

int main()
{
    return 0;
}