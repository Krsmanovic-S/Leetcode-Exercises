#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;
typedef pair<string, int> stringPair;

// Helper function to help the priority queue sort  
// by frequency and lexicographical order as well.
struct Compare {
    bool operator() (stringPair a, stringPair b)
    {
        // Same frequency means sort by lexicographical order.
        if(a.second == b.second)
        return a.first > b.first;
        
        // Otherwise just take the frequency into account.
        return a.second < b.second;
    }
};

vector<string> topKFrequent(vector<string>& words, int k) {
    int size = words.size();
    unordered_map<string, int> map;
    vector<string> result;
    
    // First we populate the map.
    for(int i = 0; i < size; i++)
        map[words[i]]++;
    
    // Here we use a queue to push all map variables on to it, 
    // the queue holds pairs <string, int> and will sort them
    // according to our Compare struct, which will insert the
    // highest frequency words at the top of the queue.
    priority_queue<stringPair, vector<stringPair>, Compare> q;
    for(auto x : map)
        q.push(x);
    
    // Here we just take the most frequent words (those at the top)
    // and assign them to the vector.
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
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;

    vector<string> result = topKFrequent(words, k);
    for(auto x : result)
        cout << x << " ";

    return 0;
}