#include <vector>

class Solution {
    private:
        void sort(std::vector<int>& nums, int start_index, int end_index) {
            if (start_index < end_index) {
                int mid_index = start_index + (end_index-start_index) / 2;
                this->sort(nums, start_index, mid_index);
                this->sort(nums, mid_index+1, end_index);

                std::vector<int> temp_array;

                int start_index_iterator = start_index;
                int mid_index_iterator = mid_index+1;

                while (start_index_iterator <= mid_index && mid_index_iterator <= end_index) {
                    if (nums[start_index_iterator] < nums[mid_index_iterator]) {
                        temp_array.push_back(nums[start_index_iterator]);
                        start_index_iterator++;
                    } else {
                        temp_array.push_back(nums[mid_index_iterator]);
                        mid_index_iterator++;
                    }
                }

                while (start_index_iterator <= mid_index) {
                    temp_array.push_back(nums[start_index_iterator]);
                    start_index_iterator++;
                }

                while (mid_index_iterator <= end_index) {
                    temp_array.push_back(nums[mid_index_iterator]);
                    mid_index_iterator++;
                }

                int total_size = temp_array.size();
                for (int index = 0; index < total_size; index++) {
                    nums[start_index+index] = temp_array[index];
                }
            }
        }

    public:
        int findLHS(std::vector<int>& nums) {
            int total_size = nums.size();
            this->sort(nums, 0, total_size-1);

            int max_element = 0;
            int left_iterator = 0;
            int right_iterator = 1;

            while (right_iterator < total_size) {
                int difference = nums[right_iterator] - nums[left_iterator];
                if (difference == 1) {
                    int distance = (right_iterator - left_iterator)+1;
                    if (distance > max_element) {
                        max_element = distance;
                    }
                }

                if (difference <= 1) {
                    right_iterator++;
                } else {
                    left_iterator++;
                }
            }

            return max_element;
        }
};