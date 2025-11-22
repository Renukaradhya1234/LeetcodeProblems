#include <vector>

class Solution {
    public:
        std::vector<int> targetIndices(std::vector<int>& nums, int target) {
            unsigned int buffer[101] = {0};
            unsigned int total_size = nums.size();
            for (unsigned int index = 0; index < total_size; index++) {
                buffer[ nums[index] ]++;
            }

            unsigned int cumulative_sum = 0;
            for (unsigned int index = 0; index < 101; index++) {
                cumulative_sum += buffer[index];
                buffer[index] = cumulative_sum;
            }

            std::vector<int> result;

            unsigned int start_index = 0;
            if (target != 0) {
                start_index = buffer[target-1];
            }

            while (start_index < buffer[target]) {
                result.push_back(start_index);
                start_index++;
            }

            return result;
        }
};