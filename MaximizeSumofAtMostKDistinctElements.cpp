#include <vector>

class Solution {
    private:
        int getTargetIndex(std::vector<int>& nums, int start_index, int end_index, int target) {

            while (start_index <= end_index) {
                int mid_index = start_index + (end_index-start_index)/2;
                if (nums[mid_index] <= target) {
                    end_index = mid_index-1;
                } else {
                    start_index = mid_index+1;
                }
            }

            return start_index;
        }

        void sort(std::vector<int>& nums) {
            int total_size = nums.size();
            
            for (int index = 0; index < total_size; index++) {
                int value = nums[index];

                int target_index = this->getTargetIndex(nums, 0, index-1, value);

                for (int sub_index = index; sub_index > target_index; sub_index--) {
                    nums[sub_index] = nums[sub_index-1];
                }

                nums[target_index] = value;
            }
        }

    public:
        std::vector<int> maxKDistinct(std::vector<int>& nums, int k) {
            std::vector<int> result;
            this->sort(nums);
            int last_num = nums[0];
            result.push_back(last_num);
            int count = 1;
            if (k != count) {
                int total_size = nums.size();
                for (int index = 1; index < total_size; index++) {
                    int current_value = nums[index];
                    if (last_num != current_value) {
                        result.push_back(current_value);
                        if (k == ++count) {
                            break;
                        }
                    }
                    last_num = current_value;
                }
            }
            return result;
        }
};