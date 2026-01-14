#include <vector>

class Solution {
    public:
        std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
            const unsigned int NUMBER_BUFFER_SIZE = 101;
            int number_buffer[NUMBER_BUFFER_SIZE] = {0};
            const unsigned int NUMS_SIZE = nums.size();
            std::vector<int> smaller_numbers_than_current(NUMS_SIZE);

            for (unsigned int index = 0; index < NUMS_SIZE; index++) {
                number_buffer[ nums[index] ]++;
            }

            unsigned int pre_sum = 0;
            for (unsigned int index = 0; index < NUMBER_BUFFER_SIZE; index++) {
                int temp = number_buffer[index];
                number_buffer[index] = pre_sum;
                pre_sum += temp;
            }
            
            for (unsigned int index = 0; index < NUMS_SIZE; index++) {
                smaller_numbers_than_current[index] = number_buffer[ nums[index] ];
            }

            return smaller_numbers_than_current;
        }
};