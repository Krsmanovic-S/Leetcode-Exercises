#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.empty()) return 0;
    
    int indexBuy, indexSell; // Keeps track that we sell on a day that is after the buy.
    int buy = -1, sell = -1, minBuy = -1, maxSell = -1;

    for(int i = 0; i < prices.size(); i++)
    {
        // First we do the initial buy and sell, it's important that we reset the sell
        // if we get a buy value.
        if(buy == -1 || prices[i] < buy) buy = prices[i], sell = -1, indexBuy = i;
        else if(sell == -1 || prices[i] > sell) sell = prices[i], indexSell = i;
        
        // After we have the buy and sell, check if the sale is valid (day for selling is after buying),
        // and compare the sell - buy to the maximum profit.
        if(buy != -1 && sell != -1)
        {
            if(indexSell > indexBuy && sell - buy > maxSell - minBuy)
                minBuy = buy, maxSell = sell;
        }
    }
    if(minBuy != -1 && maxSell != -1) return maxSell - minBuy;
    
    return 0;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = maxProfit(prices);

    cout << result;

    return 0;
}