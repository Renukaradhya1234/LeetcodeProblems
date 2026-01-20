#include <vector>
#include <climits>

class Solution {
    public:
        int removeDuplicates(std::vector<int>& nums) {
            const unsigned int NUMS_SIZE = nums.size();
            const unsigned int MAX_NUM_COUNT = 2;
            int element_index = 0;
            int prev_value = INT_MIN;
            unsigned int current_num_count = 1;

            for (unsigned int index = 0; index < NUMS_SIZE; index++) {
                if (prev_value == nums[index]) {
                    if (current_num_count <= MAX_NUM_COUNT) {
                        nums[element_index++] = nums[index];
                    }
                } else {
                    nums[element_index++] = nums[index];
                    current_num_count = 1;
                }

                prev_value = nums[index];
                current_num_count++;
            }

            return element_index;
        }
};