#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    int size = nums.size();

    // Fill out the queue first, it will sort by default
    // exactly what we need, meaning it will sort by decreasing order.
    priority_queue<int> q;
    for(int i = 0; i < size; i++)
        q.push(nums[i]);
    
    // Pop elements off the queue until we reach the one element we need,
    // after which we just return it.
    while(k > 1)
    {
        q.pop();
        k--;
    }

    return q.top();
}

int main()
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6}; 
    int k = 4;

    cout << findKthLargest(nums, k);

    return 0;
}