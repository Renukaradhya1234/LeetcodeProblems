#include <vector>

class Solution {
    public:
        std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
            unsigned int buffer[101] = {0};
            std::vector<int> result;
            unsigned int total_size = nums.size();
            for (unsigned int index = 0; index < total_size; index++) {
                buffer[ nums[index] ]++;
            }

            unsigned int cumulative_sum = 0;
            for (unsigned int index = 0; index < 101; index++) {
                cumulative_sum += buffer[index];
                buffer[index] = cumulative_sum;
            }

            for (unsigned int index = 0; index < total_size; index++) {
                if (nums[index] == 0) {
                    result.push_back(0);
                } else {
                    result.push_back(buffer[ nums[index]-1 ]);
                }
            }

            return result;
        }
};