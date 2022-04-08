#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    int size = stones.size();
    
    int firstStone, secondStone;
    
    while(size > 1)
    {
        // We sort first and then pick the heaviest two stones.
        sort(stones.begin(), stones.end());
        firstStone = stones[size - 1];
        secondStone = stones[size - 2];
        
        // Both stones are destroyed if they are equal.
        if(firstStone == secondStone)
        {
            stones.pop_back();
            stones.pop_back();
            size -= 2;
        }
        // Otherwise just pop one stone, the other one should change it's
        // value to the difference between the last two stones.
        else
        {
            stones[size - 2] = abs(firstStone - secondStone);
            stones.pop_back();
            size--;
        }
    }
    
    if(stones.empty())
        return 0;
    else
        return stones[0];
}

int main()
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    int result = lastStoneWeight(stones);

    cout << result;

    return 0;
}