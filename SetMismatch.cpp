#include <vector>
#include <iostream>

class Solution {
    public:
        std::vector<int> findErrorNums(std::vector<int>& nums) {
            int total_size = nums.size();
            
            int sum = 0;
            for (int index = 0; index < total_size; index++) {
                sum += nums[index];
            }

            int duplicate_number = -1;
            for (int index = 0; index < total_size; index++) {
                int value = nums[index];
                if (value < 0) {
                    value = -value;
                }

                if (nums[value-1] < 0) {
                    duplicate_number = value;
                    break;
                } else {
                    nums[value-1] = -nums[value-1];
                }
            }
            int total_sum = (total_size* (total_size+1)) / 2;
            std::vector<int> result;
            result.push_back(duplicate_number);
            result.push_back(total_sum-(sum-duplicate_number));
            return result;
        }
};