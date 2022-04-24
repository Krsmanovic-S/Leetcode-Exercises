#include <iostream>
#include <vector>

using namespace std;

vector<int> constructRectangle(int area) {
    vector<int> result(2);
    int width = 1, length;
    int minDistance = INT_MAX, currentDistance;
    
    // Width must be less than square root of the area to
    // satisfy the condition that its less than the length.
    while(width <= sqrt(area))
    {
        length = area / width;
        
        // For those cases like 5 / 2 = 2 but 2 * 2 != 5.
        if(length * width == area)
        {
            currentDistance = abs(length - width);

            // This is so we get the correct result with the
            // minimum distance, this check is performed
            // every iteration of the loop.
            if(minDistance > currentDistance)
            {
                minDistance = currentDistance;
                result[0] = length;
                result[1] = width;
            }
        }
        width++;
    }
    return result;
}

int main()
{
    int area = 122122;
    vector<int> result = constructRectangle(area);

    for(auto x : result)
        cout << x << " ";

    return 0;
}