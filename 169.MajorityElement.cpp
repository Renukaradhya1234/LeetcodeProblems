#include <vector>

class Solution {
    public:
        int majorityElement(std::vector<int>& nums) {
            const unsigned int NUMS_SIZE = nums.size();
            int count = 1;
            int candidate = nums[0];

            for (unsigned int index = 1; index < NUMS_SIZE; index++) {
                if (count == 0) {
                    candidate = nums[index];
                    count = 1;
                } else if (candidate == nums[index]) {
                    count++;
                } else {
                    count--;
                }
            }

            return candidate;
        }
};