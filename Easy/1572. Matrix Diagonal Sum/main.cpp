#include <iostream>
#include <vector>

using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
    int sum = 0;
    
    // Odd matrix will have an overlap in the middle,
    // we shouldn't count the element twice.
    if(mat.size() % 2 != 0)
        sum -= mat[mat.size() / 2][mat.size() / 2];

    // Calculate the sum with the values
    // from both diagonals, primary is first,
    // secondary diagonal is the second loop.
    for(int i = 0; i < mat.size(); i++)
        sum += mat[i][i];    
    
    for(int i = 0; i < mat.size(); i++)
        sum += mat[mat.size() - 1 - i][i];            

    return sum;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    };
    cout << diagonalSum(mat);
    
    return 0;
}