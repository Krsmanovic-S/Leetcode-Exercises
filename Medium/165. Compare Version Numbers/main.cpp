#include <iostream>
#include <string>

using namespace std;

int compareVersion(string version1, string version2) {
    int num1 = 0, num2 = 0;
    int s1 = version1.length();
    int s2 = version2.length();
    int firstPointer = 0, secondPointer = 0;
    
    while(firstPointer < s1 || secondPointer < s2)
    {
        // We first need to represent the numbers up to a dot character,
        // at the start we do this for num1, then for num2. This approach
        // works cause we can represent numbers in the integer format as the
        // exercise said to us. 
        while(firstPointer < s1 && version1[firstPointer] != '.')
        {
            num1 = 10 * num1 + (version1[firstPointer] - '0');
            firstPointer++;
        }
        while(secondPointer < s2 && version2[secondPointer] != '.')
        {
            num2 = 10 * num2 + (version2[secondPointer] - '0');
            secondPointer++;
        }
                    
        // Compare the two values now.
        if(num1 > num2)
        {
            return 1;
        }
        if(num1 < num2)
        {
            return -1;
        }
        
        // Reset the numbers, we already checked the part before the dot,
        // now in the next iteration we move to the next segment after the dot.
        num1 = 0;
        num2 = 0;
        
        // Move the pointers by one space.
        firstPointer++;
        secondPointer++;
    }
    return 0;
}

int main()
{
    string ver1 = "1.01";
    string ver2 = "1.001";

    compareVersion(ver1, ver2);

    return 0;
}