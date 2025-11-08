#include <vector>

class Solution {
    public:
        std::vector<int> findMissingElements(std::vector<int>& nums) {
            int buffer[100] = { 0 };

            int max_value = 0;
            int min_value = 101;
            int total_size = nums.size();

            for (int index = 0; index < total_size; index++) {
                int value = nums[index];
                buffer[value-1] = 1;
                if (value > max_value) {
                    max_value = value;
                }
                if (value < min_value) {
                    min_value = value;
                }
            }

            std::vector<int> result;

            for (int index = min_value-1; index < max_value; index++) {
                if (buffer[index] == 0) {
                    result.push_back(index+1);
                }
            }

            return result;
        }
};