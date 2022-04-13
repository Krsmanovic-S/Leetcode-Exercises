#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            result[i].push_back(-1);
    
    int currentNumber = 1, i = 0, j = 0;
    bool check = true;
    
    while(currentNumber <= (n * n))
    {
        // If check is true we are going rightwards/normal direction -> right/down,
        // and if check turns to false that means we need to go left/up.
        if(check)
        {
            // Fill out the row at first (left -> right order) before moving down.
            while(j < n && result[i][j] == -1)
            {
                result[i][j] = currentNumber;
                currentNumber++;
                j++;
            }
            
            // We decrement here as j would be equal to n after the while-loop
            // and increment i which means we went to another column now.
            j--, i++;
            
            // Now we go downward (up -> down order).
            while(i < n && result[i][j] == - 1)
            {
                result[i][j] = currentNumber;
                currentNumber++;
                i++;
            }
            
            // Same logic as for the j variable above, but we want to decrement j as well.
            j--, i--;
            
            // Switch check now, by this point we are in the bottom right corner.
            check = !check;
        }
        else
        {
            // This is the right -> left order.
            while(j > -1 && result[i][j] == -1)
            {
                result[i][j] = currentNumber;
                currentNumber++;
                j--;                    
            }

            j++, i--;
            
            // This is down -> up order
            while(i > -1 && result[i][j] == -1)
            {
                result[i][j] = currentNumber;
                currentNumber++;
                i--;      
            }        
        
            j++, i++;
            
            // We switch check again so we can do right -> down order again.
            check = !check;
        }
    }

    return result;   
}

int main()
{
    int n = 5;
    vector<vector<int>> result = generateMatrix(5);

    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}