#include <vector>

class Solution {
    public:
        int findNonMinOrMax(std::vector<int>& nums) {
            int result = -1;
            int total_size = nums.size();
            int max_value = 0;
            int min_value = 101;
            for (int index = 0; index < total_size; index++) {
                int value = nums[index];
                if (value > max_value) {
                    max_value = value;
                }
                if (value < min_value) {
                    min_value = value;
                }
            }

            for (int index = 0; index < total_size; index++) {
                int value = nums[index];
                if (value != min_value && value != max_value) {
                    result = value;
                    break;
                }
            }
            return result;
        }
};