#include <vector>

class Solution {
    private:
        int abs(int number) {
            if (number < 0) {
                number = -number;
            }
            return number;
        }

    public:
        std::vector<int> sortedSquares(std::vector<int>& nums) {
            int total_size = nums.size();
            std::vector<int> square_sorted_list(total_size, 0);
            int left_traveler = 0;
            int right_traveler = total_size-1;

            while (left_traveler <= right_traveler) {
                int left_value = this->abs(nums[left_traveler]);
                int right_value = this->abs(nums[right_traveler]);

                if (left_value > right_value) {
                    square_sorted_list[--total_size] = left_value*left_value;
                    left_traveler++;
                } else {
                    square_sorted_list[--total_size] = right_value*right_value;
                    right_traveler--;
                }
            }
            return square_sorted_list;
        }
};