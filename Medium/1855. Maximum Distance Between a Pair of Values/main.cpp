#include <iostream>
#include <vector>

using namespace std;

int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int result = 0, start, end, mid;
    
    // If last element of nums1 is greater than the
    // largest in nums2, we know the result will be 0.
    if(nums2[0] < nums1[nums1.size() - 1]) return result;
    
    for(int i = 0; i < nums1.size(); i++)
    {
        start = i, end = nums2.size() - 1;
        // Binary search to find the furthest away
        // element in nums2 that is greater than nums1[i].
        while(start <= end)
        {
            mid = (start + end) / 2;
            
            if(nums1[i] > nums2[mid])
                end = mid - 1;
            else if(nums1[i] <= nums2[mid])
                start = mid + 1;
        }
        
        // Check if the result of the search is an index at/after
        // index i and then check if result is a smaller distance.
        if(i <= start && result < start - i)
                result = start - i - 1;
    }
    return result;
}

int main()
{
    vector<int> nums1 = {55, 30, 5, 4, 2}, nums2 = {100, 20, 10, 10, 5};
    cout << maxDistance(nums1, nums2);

    return 0;
}