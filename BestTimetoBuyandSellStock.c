int maxProfit(int* prices, int pricesSize) {
    int buyed_stock = prices[0];
    int profit = 0;
    int max_profit = 0;
    for (int index = 1; index < pricesSize; index++) {
        /// buy the stock when it is min value.
        if (buyed_stock > prices[index]) {
            buyed_stock = prices[index];
        }

        // check the profit of current stock with buyed stock.
        profit = prices[index] - buyed_stock;
        if (profit > max_profit) {
            max_profit = profit;
        }
    }

    return max_profit;
}