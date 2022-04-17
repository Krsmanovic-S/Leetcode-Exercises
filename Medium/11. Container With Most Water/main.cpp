#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    int result = 0, currentArea;
    int left = 0, right = height.size() - 1;
    
    // We use two pointers to traverse the array,
    // with the strategy of moving the pointer which is
    // smaller than the other one.
    while(left < right)
    {
        if(height[left] < height[right])
        {
            currentArea = height[left] * (right - left);
            if(currentArea > result)
                result = currentArea;
            
            left++;
        }
        else
        {
            currentArea = height[right] * (right - left);
            if(currentArea > result)
                result = currentArea;
            
            right--;
        }
    }
    return result;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height);
    
    return 0;
}