#include <vector>

class Solution {
    public:
        std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
            int mapper[1001] = { 0 } ;
                int first_array_size = arr1.size();
                for (int index = 0; index < first_array_size; index++) {
                    int value = arr1[index];
                    mapper[value]++;
                }

                std::vector<int> result;
                int second_array_size = arr2.size();
                for (int index = 0; index < second_array_size; index++) {
                    int value = arr2[index];
                    while (mapper[value] > 0) {
                        result.push_back(value);
                        mapper[value]--;
                    }
                }

                for (int index = 0; index < 1001; index++) {
                    int count = mapper[index];
                    while (count > 0) {
                        result.push_back(index);
                        count--;
                    }
                }
                return result;
        }
};