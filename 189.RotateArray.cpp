#include <vector>

class Solution {
    private:
        void reverse(std::vector<int>& num_array, int start_index, int end_index) {
            while (start_index < end_index) {
                int temp = num_array[start_index];
                num_array[start_index++] = num_array[end_index];
                num_array[end_index--] = temp;
            }
        }

    public:
        void rotate(std::vector<int>& nums, int k) {
            const unsigned int NUMS_SIZE = nums.size();
            if (NUMS_SIZE != k) {
                this->reverse(nums, 0, NUMS_SIZE-1);
                while (k > NUMS_SIZE) {
                    k = k-NUMS_SIZE;
                }
                this->reverse(nums, 0, k-1);
                this->reverse(nums, k, NUMS_SIZE-1);
            }
        }
};