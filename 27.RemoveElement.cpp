#include <vector>

class Solution {
    public:
        int removeElement(std::vector<int>& nums, int val) {
            const unsigned int VECTOR_SIZE = nums.size();
            int element_index = 0;

            for (unsigned int index = 0; index < VECTOR_SIZE; index++) {
                if (nums[index] != val) {
                    nums[element_index++] = nums[index];
                }
            }

            return element_index;
        }
};