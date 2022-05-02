#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> result;   

// Function that will find each combination and output
// it into the resulting vector.
void find(vector<int> temp, int n, int k, int i) {
    // If our temp is size of k, that means we finished
    // one combination.
    if(temp.size() == k)
    {
        result.push_back(temp);
        return;
    }
    for(int j = i; j <= n; j++)
    {
        temp.push_back(j);
        find(temp, n, k, j + 1);
        temp.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<int> temp;
    find(temp, n, k, 1);
    
    return result;
}

int main()
{
    int n = 4, k = 2;
    result = combine(n, k);

    return 0;
}