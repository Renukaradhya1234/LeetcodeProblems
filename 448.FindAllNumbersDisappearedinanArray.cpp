#include <vector>

class Solution {
    public:
        std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
            std::vector<int> disappeared_numbers;
            const unsigned int NUMS_SIZE = nums.size();

            for (unsigned int index = 0; index < NUMS_SIZE; index++) {
                int data = nums[index];
                if (data < 0) {
                    data = -data;
                }
                data--;
                if (nums[data] > 0) {
                    nums[data] = -nums[data];
                }
            }

            for (unsigned int index = 0; index < NUMS_SIZE; index++) {
                if (nums[index] > 0) {
                    disappeared_numbers.push_back(index+1);
                }
            }

            return disappeared_numbers;
        }
};