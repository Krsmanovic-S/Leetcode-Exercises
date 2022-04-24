#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int plantable = 0;
    
    // Edge cases when size is 1.
    if(flowerbed.size() == 1)
    {
        if(flowerbed[0] == 0)
        {
            if(n <= 1) 
                return true;
            else 
                return false;
        }
        else
        {
            if(n == 0) 
                return true;
            else 
                return false;
        }
    }
    
    // Find out where we can't plant at all due to
    // already existing plants.
    for(int i = 0; i < flowerbed.size(); i++)
    {
        if(flowerbed[i] == 1)
        {
            if(i != 0 && i != flowerbed.size() - 1)
            {
                flowerbed[i + 1] = -1;
                flowerbed[i - 1] = -1;
            }
            else if(i == 0)
                flowerbed[i + 1] = -1;
            else
                flowerbed[i - 1] = -1;
        }
    }

    // Now just go through the array again, this time
    // planting wherever we can and keeping track of
    // how many we planted.    
    for(int i = 0; i < flowerbed.size(); i++)
    {
        if(flowerbed[i] == 0)
        {
            flowerbed[i] = 1;
            
            if(i != 0 && i != flowerbed.size() - 1)
            {
                flowerbed[i + 1] = -1;
                flowerbed[i - 1] = -1;
            }
            else if(i == 0)
                flowerbed[i + 1] = -1;
            else
                flowerbed[i - 1] = -1;
            
            plantable++;
        }
    }
    
    if(plantable >= n)
        return true;
    else
        return false;
}

int main()
{
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;

    cout << boolalpha;
    cout << canPlaceFlowers(flowerbed, n);

    return 0;
}