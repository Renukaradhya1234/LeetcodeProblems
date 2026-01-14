#include <vector>

class Solution {
    public:
        std::vector<int> shuffle(std::vector<int>& nums, int n) {
            const unsigned int NUMS_SIZE = nums.size();
            const unsigned int TOTAL_ITERATION = NUMS_SIZE/2;
            std::vector<int> shuffled_array(NUMS_SIZE);
            unsigned int shuffled_index = 0;

            for (int index = 0; index < TOTAL_ITERATION; index++) {
                shuffled_array[shuffled_index++] = nums[index];
                shuffled_array[shuffled_index++] = nums[index+TOTAL_ITERATION];
            }

            return shuffled_array;
        }
};