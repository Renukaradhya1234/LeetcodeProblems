#include <vector>

class Solution {
    public:
        int maximizeExpressionOfThree(std::vector<int>& nums) {
            int first_largest_num = -101;
            int second_largest_num = -101;
            int first_smallest_num = 101;
            unsigned int total_size = nums.size();
            for (unsigned int index = 0; index < total_size; index++) {
                if (nums[index] > first_largest_num) {
                    second_largest_num = first_largest_num;
                    first_largest_num = nums[index];
                } else if (nums[index] > second_largest_num) {
                    second_largest_num = nums[index];
                }

                if (nums[index] < first_smallest_num) {
                    first_smallest_num = nums[index];
                }
            }

            return first_largest_num + second_largest_num - first_smallest_num;
        }
};