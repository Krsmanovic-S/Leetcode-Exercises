#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
typedef pair<int, int> intPair;

// Helper function to compare the frequency of numbers
// for the priority queue.
struct ComparePair {
    bool operator() (intPair a, intPair b)
    {
        return a.second < b.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    int size = nums.size();
    vector<int> result;
    
    if(size == 1)
    {
        result.push_back(nums[0]);
        return result;
    }
    
    // First we map each number and it's amount of occurence to the map.        
    unordered_map<int, int> map;
    for(int i = 0; i < size; i++)
        map[nums[i]]++;
    
    // This is the second part of how we finish this, full explanation is below.
    priority_queue<intPair, vector<intPair>, ComparePair> q;
    
    // Fill the queue with every single value from map, keep in mind every
    // value in the map is a pair<int, int>, where first int is the key
    // (the number itself) and the second int is the frequency.
    for(auto x : map)
        q.push(x);
    
    // Here we just go from the top of the queue k-times to get the result.
    while(k > 0)
    {
        result.push_back(q.top().first);
        q.pop();
        k--;
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = topKFrequent(nums, k);
    for(auto x : result)
        cout << x << " ";

    return 0;
}