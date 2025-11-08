#include <vector>

class Solution {
    public:
        bool isGood(std::vector<int>& nums) {
            int buffer[201] = {0};
            int max_value = 0;
            int total_size = nums.size();
            for (int index = 0; index < total_size; index++) {
                int value = nums[index];
                buffer[value]++;
                if (value > max_value) {
                    max_value = value;
                }
            }

            bool result = false;
            if (max_value + 1 == total_size && buffer[max_value] == 2) {
                result = true;
                for (int index = 1; index < max_value; index++) {
                    if (buffer[index] != 1) {
                        result = false;
                        break;
                    }
                }
            }

            return result;
        }
};