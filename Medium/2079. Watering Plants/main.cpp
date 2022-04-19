#include <iostream>
#include <vector>

using namespace std;

int wateringPlants(vector<int>& plants, int capacity) {
    int currentCapacity = capacity, steps = 0;
    bool refill = true;
    
    for(int i = 0; i < plants.size(); i++)
    {
        // Water the plant if we can, otherwise
        // we will need to refill.
        if(plants[i] <= currentCapacity)
        {
            currentCapacity -= plants[i];
            steps++;
            refill = false;
        }
        else
            refill = true;
        
        // When refilling, restore capacity,
        // increase our steps by two times 
        // the index (simulates trip to river and back),
        // and decrement the index since we still 
        // didn't water that plant.
        if(refill)
        {
            currentCapacity = capacity;
            steps += i * 2;
            refill = false;
            i--;
        }
    }
    return steps;
}

int main()
{
    vector<int> plants = {7, 4, 5, 3, 3, 2, 10};
    int capacity = 8;

    cout << wateringPlants(plants, capacity);

    return 0;
}