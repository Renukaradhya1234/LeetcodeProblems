#include <vector>

class Solution {
    private:
        int getTargetIndex(std::vector<int>& int_array, int start_index, int end_index, int target) {

            while (start_index <= end_index) {
                int mid_index = start_index + ( end_index-start_index ) / 2;
                if (int_array[mid_index] <= target) {
                    start_index = mid_index+1;
                } else {
                    end_index = mid_index-1;
                }
            }

            return start_index;
        }

        void inserationSort(std::vector<int>& int_array) {
            int total_size = int_array.size();
            for (int index = 0; index < total_size; index++) {
                int value = int_array[index];
                int target_index = this->getTargetIndex(int_array, 0, index-1, value);
                
                for (int sub_index = index-1; sub_index >= target_index; sub_index--) {
                    int_array[sub_index+1] = int_array[sub_index];
                }

                int_array[target_index] = value;
            }
        }

    public:
        int heightChecker(std::vector<int>& heights) {
            int total_size = heights.size();
            
            std::vector<int> heights_copy;
            
            for (int index = 0; index < total_size; index++) {
                heights_copy.push_back(heights[index]);
            }
            
            this->inserationSort(heights_copy);
            
            int count = 0;
            for (int index = 0; index < total_size; index++) {
                if (heights[index] != heights_copy[index]) {
                    count++;
                }
            }

            return count;
        }
};