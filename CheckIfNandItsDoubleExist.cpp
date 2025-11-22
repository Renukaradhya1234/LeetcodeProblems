#include <vector>

class Solution {
    public:
        bool checkIfExist(std::vector<int>& arr) {
            bool result = false;
            bool buffer_ref[2001] = { false };
            int total_size = arr.size();
            for (int index = 0; index < total_size; index++) {
                int original_value = arr[index];
                int value = original_value + 1000;

                // if (buffer_ref[value] == false) {
                    // Step-1: check the half value present or not...
                    if (original_value % 2 == 0) {
                        int half_value = (original_value/2)+1000;
                        if (buffer_ref[half_value]) {
                            result = true;
                            break;
                        }
                    }

                    // Step-2: check the double value present or not...
                    int double_value = (2*original_value)+1000;
                    if (double_value >= 0 && double_value < 2001 && buffer_ref[double_value]) {
                        result = true;
                        break;
                    }
                // }
                buffer_ref[value] = true;
            }

            return result;
        }
};