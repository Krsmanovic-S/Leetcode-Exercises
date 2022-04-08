#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int size = arr.size();
    int start = 0, end = size - 1, mid, num;
    
    while(start <= end)
    {
        mid = start + (end - start) / 2;
        num = arr[mid];
        
        // Main body of the binary search.
        if(num > arr[mid + 1] && num > arr[mid - 1])
            return mid;
        else if(num < arr[mid + 1])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> arr = {0, 10, 5, 2};
    cout << peakIndexInMountainArray(arr);
    
    return 0;
}