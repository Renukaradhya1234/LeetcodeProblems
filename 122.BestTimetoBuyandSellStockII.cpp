#include <vector>

class Solution {
    public:
        int maxProfit(std::vector<int>& prices) {
            int max_profit = 0;
            const unsigned int PRICES_SIZE = prices.size();
            int buyed_stock_price = prices[0];
            int prev_stock = prices[0];
            for (unsigned int index = 1; index < PRICES_SIZE; index++) {
                int current_stock_price = prices[index];
                if (current_stock_price < prev_stock) {
                    /// sell the stock...
                    int current_profit = prev_stock - buyed_stock_price;
                    max_profit += current_profit;
                    buyed_stock_price = current_stock_price;
                }

                prev_stock = current_stock_price;
            }

            /// sell the last stock....
            if (buyed_stock_price < prev_stock) {
                max_profit += prev_stock - buyed_stock_price;
            }

            return max_profit;
        }
};