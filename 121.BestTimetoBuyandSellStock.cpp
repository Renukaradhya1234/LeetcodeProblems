#include <vector>

class Solution {
    public:
        int maxProfit(std::vector<int>& prices) {
            int max_profit = 0;
            const unsigned int PRICES_SIZE = prices.size();
            int min_price = prices[0];

            for (unsigned int index = 1; index < PRICES_SIZE; index++) {
                if (prices[index] < min_price) {
                    min_price = prices[index];
                } else {
                    int current_max_profit = prices[index]-min_price;
                    if (current_max_profit > max_profit) {
                        max_profit = current_max_profit;
                    }
                }
            }

            return max_profit;
        }
};