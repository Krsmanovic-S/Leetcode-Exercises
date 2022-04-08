#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class KthLargest {
private:
    int target;
    vector<int> stream;
public:
    KthLargest(int k, vector<int>& nums) {
        // Variable assignment
        this->target = k;
        this->stream = nums;
        
        sort(stream.begin(), stream.end());
    }
    
    int add(int val) {
        // Find the appropriate index to insert the value without
        // disturbing the sorted order.
        auto index = lower_bound(stream.begin(), stream.end(), val);
        stream.insert(index, val);
        
        return stream[stream.size() - target];
    }
};

int main()
{
    return 0;
}