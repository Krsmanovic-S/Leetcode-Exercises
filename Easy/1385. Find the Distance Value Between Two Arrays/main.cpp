#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    sort(arr2.begin(),arr2.end());
    int distance = 0;
    int start, end, mid, minDistance;
    
    for(int i = 0; i < arr1.size(); i++) 
    { 
        // Binary search to find nearest element to arr1[i] from arr2.
        start = 0, end = arr2.size() - 1;
        while(start <= end)
        {
            mid = start + (end - start) / 2;
            
            if(arr2[mid] <= arr1[i])
                start = mid + 1;
            else
                end = end - 1;
        }  

        // Dealing with edge casses and calculating minimum distance 
        // between the current arr1 element and two elements from arr2 
        // (at position start and end).
        if(end < 0) 
            minDistance = abs(arr1[i] - arr2[start]);
        else if(start == arr2.size()) 
            minDistance = abs(arr1[i] - arr2[end]);
        else 
            minDistance = min(abs(arr1[i] - arr2[start]), abs(arr1[i] - arr2[end]));
        
        if(minDistance > d)
            distance++;
    }
    return distance;
}

int main()
{
    vector<int> arr1 = {4, 5, 8}, arr2 = {10, 9, 1, 8};
    int d = 2;

    cout << findTheDistanceValue(arr1, arr2, d);

    return 0;
}