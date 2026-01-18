#include <vector>

class Solution {
    public:
        int removeDuplicates(std::vector<int>& nums) {
            int element_index = 0;
            const unsigned int VECTOR_SIZE = nums.size();
            int prev_value = 101;
            
            for (unsigned int index = 0; index < VECTOR_SIZE; index++) {
                if (nums[index] != prev_value) {
                    nums[element_index++] = nums[index];
                }
                prev_value = nums[index];
            }

            return element_index;
        }
};