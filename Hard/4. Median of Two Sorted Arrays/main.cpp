#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // First create a 3rd array that will hold the two
    // inputs combined in one. Reserve as much space as
    // is the combined size of nums1 and nums2.
    vector<int> mergedArray;
    mergedArray.reserve(nums1.size() + nums2.size());
    
    // Now we just use merge-sort to get everything in order.
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(mergedArray));
    
    int n = mergedArray.size();
    
    if(n % 2 != 0)
        return (double)mergedArray[n / 2];

    return (double)(mergedArray[(n - 1) / 2] + mergedArray[n / 2]) / 2.0;
}

int main()
{
    vector<int> nums1 = {1, 2, 7, 10, 12}, nums2 = {3, 4};
    cout << findMedianSortedArrays(nums1, nums2);
    
    return 0;
}