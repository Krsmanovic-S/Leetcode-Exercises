#include <iostream>
#include <vector>

int trap(std::vector<int>& height) {
    if(height.size() < 3) return 0;
    
    int left = 0, right = 1, result = 0, remember;
    
    // First we go from left to right.
    while(left != height.size())
    {
        // Breaking condition for the loop. 
        if(right == height.size())
        {
            remember = left;
            right--;
            left = right - 1;
            break;
        }            

        if(height[right] < height[left])
            right++;
        else
        {
            // Calculating the water in the current container.
            for(int i = left + 1; i < right; i++)
                result += height[left] - height[i];
            
            left = right;
            right++;
        }
    }
    
    // We then go from right to left, 
    // but only to the last position 
    // checked by the above while-loop.
    while(right != remember)
    {
        if(left < remember)
            break;
        
        if(height[right] > height[left])
            left--;
        else
        {
            // This time for calculation we take the
            // right height instead of the left one.
            for(int i = left + 1; i < right; i++)
                result += height[right] - height[i];
            
            right = left;
            left--;
        }
    }
    return result;
}

int main()
{
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << trap(height);
    
    return 0;
}