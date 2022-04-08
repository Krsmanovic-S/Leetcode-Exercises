#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int column = matrix.size() - 1; // Number of Columns
    int row = matrix[0].size() - 1; // Number of Rows
    
    // This below can confuse someone, good naming am I right? 
    int minimum = matrix[0][row]; // Maximum value in the FIRST row
    int maximum = matrix[column][0]; // Minimum value in the LAST row
    
    if(target == minimum || target == maximum) return true;
    
    // Loop that goes on until we have 1 row remaining.
    while(column != 0)
    {
        minimum = matrix[0][row];
        maximum = matrix[column][0];
        
        // Three special cases that immidiatelly tell us where the number should be,
        // if any of these occur then we can just check one vector right away and it's done.
        if(target == minimum || target == maximum) return true;
        
        if(target < minimum) // ---> Must be in the First Matrix row
        {
            vector<int> firstRow = matrix[0];
            for(int i = 0; i < firstRow.size(); i++)
                if(firstRow[i] == target) return true;
            
            return false;
        }
        if(target > maximum) // ---> Must be in the Last Matrix Row
        {
            vector<int> lastRow = matrix[column];
            for(int i = 0; i < lastRow.size(); i++)
                if(lastRow[i] == target) return true;
            
            return false;
        }
        
        // Here we delete rows if we see that our value is less/greater than
        // the variables above. This will narrow the search down to only 1 row.
        // We can do this because we know the matrix is sorted in ascending order!
        if(target > minimum)
        {
            matrix.erase(matrix.begin() + 0);
            column--;
            
            if(column == 0) break;
        }
        if(target < maximum)
        {
            matrix.pop_back();
            column--;
            
            if(column == 0) break;
        }
    }
    // Only 1 row remains, let's check that one by one element!
    vector<int> finalRow = matrix[0];
    for(int i = 0; i < finalRow.size(); i++)
        if(finalRow[i] == target) return true;

    return false;
}

int main()
{
    vector<vector<int>> matrix = { {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}; 
    int target = 3;

    cout << searchMatrix(matrix, target);

    return 0;
}