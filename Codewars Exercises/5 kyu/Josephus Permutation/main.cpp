#include <iostream>
#include <vector>


std::vector <int> josephus(std::vector <int> items, int k)
{
    std::vector<int> result;

    // Check if items are empty
    // or k is invalid
    if (items.empty() || k == 0 || k < 0)
        return result;

    std::vector<int> collection = items;
    
    // Declare starting position and set it to 0
    unsigned int startingPos = 0;

    while (collection.size() != 1)
    {
        if (startingPos >= collection.size())
            startingPos = 0;

        for (int i = k - 1; i > 0; i--)
        {
            startingPos++;

            if(startingPos >= collection.size())
                startingPos = 0;     
        }

        // Push the element we need into result and
        // delete it from the collection
        result.push_back(collection[startingPos]);
        collection.erase(collection.begin() + startingPos);
    }

    // Push the last remaining element into result
    result.push_back(collection[0]);

    return result;
}

int main()
{
    std::vector <int> items{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
    int k = 59;
    std::vector <int> test = josephus(items, k);

    return 0;
}