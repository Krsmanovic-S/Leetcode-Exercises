#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Helper function to help us
// get the minimum ways to finish
// a certian amount of one task.
int minAmount(int taskCount) {
    int ans = 0;
    
    while(taskCount - 3 >= 0)
    {
        ans++;
        taskCount -= 3;
    }
    
    // Special case for when we get 1
    // left over after picking the 3's.
    if(taskCount == 1)
    {
        ans--;
        taskCount += 3;
    }
    
    while(taskCount - 2 >= 0)
    {
        ans++;
        taskCount -= 2;
    }
    
    return ans;
}

int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> map;
    int result = 0;
    
    // Populate the map.
    for(int i = 0; i < tasks.size(); i++)
        map[tasks[i]]++;
    
    for(auto x : map)
    {
        if(x.second == 1)
            return -1;
        
        result += minAmount(x.second);
    }
    
    return result;
}

int main()
{
    vector<int> tasks = {2, 2, 3, 3, 2, 4, 4, 4, 4, 4};
    cout << minimumRounds(tasks);

    return 0;
}