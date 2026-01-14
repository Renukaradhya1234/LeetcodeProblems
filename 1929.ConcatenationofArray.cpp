#include <vector>

class Solution {
    public:
        std::vector<int> getConcatenation(std::vector<int>& nums) {
            const unsigned int NUMS_SIZE = nums.size();
            std::vector<int> concatenated_array(2*NUMS_SIZE, 0);

            for (unsigned int index = 0; index < NUMS_SIZE; index++) {
                concatenated_array[index] = nums[index];
                concatenated_array[index+NUMS_SIZE] = nums[index];
            }

            return concatenated_array;
        }
};