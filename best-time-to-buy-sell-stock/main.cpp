#include <iostream>
#include <vector>

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=problem-list-v2&envId=oizxjoit

/**
* You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 */

// Let profits be an array of ints such that profits[i] is the highest profit that could be made on or before the ith day
// On a given day, you will either wish you had bought the stock on that day (lowest price so far), or sell



int maxProfit(std::vector<int>& prices) {
    if (prices.size() <= 1) {
        return 0;
    }

    int purchasePrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++) {
        if (purchasePrice > prices[i]) {
            purchasePrice = prices[i];
        } else {
            int currentProfit = prices[i] - purchasePrice;
            maxProfit = std::max(currentProfit, maxProfit);
        }
    }

    return maxProfit;

}

int main() {
    std::vector<int> prices = {7,6,4,3,1};
    std::cout << maxProfit(prices) << std::endl;
    return 0;
}
