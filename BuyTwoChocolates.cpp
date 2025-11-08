#include <vector>

class Solution {
    public:
        int buyChoco(std::vector<int>& prices, int money) {
            int first_min = 101;
            int second_min = 101;
            int total_size = prices.size();
            for (int index = 0; index < total_size; index++) {
                if (prices[index] < first_min) {
                    second_min = first_min;
                    first_min = prices[index];
                } else if (prices[index] < second_min) {
                    second_min = prices[index];
                }
            }

            int result = money;
            if (money - (first_min+second_min) >= 0) {
                result = money - (first_min+second_min);
            }
            return result;
        }
};