#include <vector>


class Solution {
    private:
    
        void swap(std::vector<int>& array, int first_index, int second_index) {
            int temp = array[first_index];
            array[first_index] = array[second_index];
            array[second_index] = temp;
        }
        
        void quickSort(std::vector<int>& array, int start_index, int end_index) {
            if (start_index < end_index) {
                int pivot_index = start_index-1;
                int pivot_value = array[end_index];
        
                for (int index = start_index; index < end_index; index++) {
                    /// value is greater then pivot swift after the pivot index.
                    if (array[index] < pivot_value) {
                        this->swap(array, ++pivot_index, index);
                    }
                }
                this->swap(array, ++pivot_index, end_index);
                this->quickSort(array, start_index, pivot_index-1);
                this->quickSort(array, pivot_index+1, end_index);
            }
        }

        int abs(int number) {
            if (number < 0) {
                number = -number;
            }
            return number;
        }

    public:
        std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
            int total_size = arr.size();
            this->quickSort(arr, 0, total_size-1);

            int min_absolute_diff = this->abs(arr[0]-arr[1]);

            for (int index = 1; index < total_size; index++) {
                int absolute_diff = this->abs(arr[index-1] - arr[index]);
                if (absolute_diff < min_absolute_diff) {
                    min_absolute_diff = absolute_diff;
                }
            }

            std::vector<std::vector<int>> result;

            for (int index = 1; index < total_size; index++) {
                int absolute_diff = this->abs(arr[index-1] - arr[index]);
                if (absolute_diff == min_absolute_diff) {
                    std::vector<int> values = { arr[index-1], arr[index] };
                    result.push_back(values);
                }
            }
            return result;
        }
};