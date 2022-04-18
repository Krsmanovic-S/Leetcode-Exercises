#include <iostream>
#include <vector>

using namespace std;

int sumOddLengthSubarrays(vector<int>& arr) {
    // Sum up all elements with the total sum
    // of each element before them.
    for(int i = 1; i < arr.size(); i++)
        arr[i] += arr[i - 1];

    // Sliding window with an odd size.
    int result = 0, start, end;
    for(int i = 1 ; i <= arr.size(); i += 2)
    {
        // Set up the start and end of the window
        // and loop until the window arrives at the
        // end of the array.
        start = 0; 
        end = i - 1;
        while(end < arr.size())
        {
            // Check if start is 0, we don't want
            // to go out of bounds with arr[start - 1].
            if(start == 0)
                result += arr[end];
            else
            {
                result += arr[end] - arr[start - 1];
            }
            start++, end++;
        }    
    }
    return result;
} 

int main()
{
    vector<int> arr = {1, 4, 2, 5, 3};
    cout << sumOddLengthSubarrays(arr);

    return 0;
}