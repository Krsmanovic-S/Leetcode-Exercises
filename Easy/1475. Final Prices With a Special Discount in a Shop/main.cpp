#include <iostream>
#include <vector>

using namespace std;

vector<int> finalPrices(vector<int>& prices) {
    int size = prices.size(), discount;
    vector<int> result;
    bool pushedDiscount = false;
    
    for(int i = 0; i < size; i++)
    {
        pushedDiscount = false;
        for(int j = i + 1; j < size; j++)
        {
            if(j < size && prices[j] <= prices[i])
            {
                discount = prices[i] - prices[j];
                result.push_back(discount);
                pushedDiscount = true;
                break;
            }
        }
        // If we didn't find a discount, just push the current price.
        if(!pushedDiscount)
            result.push_back(prices[i]);
    }
    return result;
}

int main()
{
    vector<int> prices = {8, 4, 6, 2, 3};
    vector<int> result = finalPrices(prices);

    for(auto x : result)
        cout << x << " ";

    return 0;
}