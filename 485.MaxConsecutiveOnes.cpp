#include <vector>
class Solution {
    public:
        int findMaxConsecutiveOnes(std::vector<int>& nums) {
            const unsigned int NUMS_SIZE = nums.size();
            int max_consecutive_ones = 0;
            int current_max_consecutive_ones = 0;

            for (unsigned int index = 0; index < NUMS_SIZE; index++) {
                if (nums[index] == 0) {
                    if (current_max_consecutive_ones > max_consecutive_ones) {
                        max_consecutive_ones = current_max_consecutive_ones;
                    }
                    current_max_consecutive_ones = 0;
                } else {
                    current_max_consecutive_ones++;
                }
            }

            if (current_max_consecutive_ones > max_consecutive_ones) {
                max_consecutive_ones = current_max_consecutive_ones;
            }

            return max_consecutive_ones;
        }
};