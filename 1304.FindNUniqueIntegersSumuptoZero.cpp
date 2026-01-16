#include <vector>

class Solution {
    public:
        std::vector<int> sumZero(int n) {
            std::vector<int> sum_zero_vector;
            int half_number = n/2;
            if (n % 2 == 1) {
                sum_zero_vector.push_back(0);
            }

            for (int number = 1; number <= half_number; number++) {
                sum_zero_vector.push_back(number);
                sum_zero_vector.push_back(-number);
            }

            return sum_zero_vector;
        }
};