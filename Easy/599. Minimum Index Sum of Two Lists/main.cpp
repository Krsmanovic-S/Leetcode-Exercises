#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// We will use this to sort the pair vector by the lowest
// index sum of the pairs inside.
static bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first + a.second < b.first + b.second;
}

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    vector<string> result;
    vector<pair<int, int>> temp;
    
    // Populate temp with all the valid indexes.        
    pair<int, int> indexes;        
    for(int i = 0; i < list1.size(); i++)
    {
        for(int j = 0; j < list2.size(); j++)
        {
            if(list1[i] == list2[j])
            {
                indexes = {i, j};
                temp.push_back(indexes);
            }
        }
    }
    
    // Sort temp and push the first member 
    // into the result (least index sum).
    sort(temp.begin(), temp.end(), compare);
    result.push_back(list1[temp[0].first]);
    
    // Now loop through temp just to see if some other
    // pairs have the exact same index sum, if so push them
    // as well.
    for(int i = 1; i < temp.size(); i++)
    {
        if(temp[i].first + temp[i].second == temp[0].first + temp[0].second)
            result.push_back(list1[temp[i].first]);
        else
            break;
    }
    
    return result;
}

int main()
{
    vector<string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"}, 
                   list2 = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};

    vector<string> result = findRestaurant(list1, list2);
    for(auto x : result)
        cout << x << " ";

    return 0;
}