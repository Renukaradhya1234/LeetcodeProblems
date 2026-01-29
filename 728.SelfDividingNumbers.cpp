#include <vector>

class Solution {
    private :
        bool isSelfDividingNumber(int number) {
            bool result = true;
            int temp_number = number;

            while (temp_number > 0) {
                int last_number = temp_number%10;
                if (last_number == 0) {
                    result = false;
                    break;
                } else if (number % last_number != 0) {
                    result = false;
                    break;
                }
                temp_number /= 10;
            }
            return result;
        }

    public:
        std::vector<int> selfDividingNumbers(int left, int right) {
            std::vector<int> result;

            for (int number = left; number <= right; number++) {
                if (this->isSelfDividingNumber(number)) {
                    result.push_back(number);
                }
            }

            return result;
        }
};