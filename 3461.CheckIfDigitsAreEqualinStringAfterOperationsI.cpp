#include <string>
#include <queue>

class Solution {
    public:
        bool hasSameDigits(std::string s) {
            std::queue<int> operations;
            const unsigned int S_SIZE = s.size();

            for (unsigned int index = 0; index < S_SIZE; index++) {
                operations.push(s[index]-'0');
            }

            int operations_size = operations.size();

            while (operations_size > 2) {
                for (int number = 1; number < operations_size; number++) {
                    int first_number = operations.front(); operations.pop();
                    int result = (first_number + operations.front()) % 10;
                    operations.push(result);
                }
                operations.pop();
                operations_size = operations.size();
            }
  
            int first_number = operations.front(); operations.pop();
            int second_number = operations.front(); operations.pop();
            
            bool has_same_digits = false;
            if (first_number == second_number) {
                has_same_digits = true;
            }

            return has_same_digits;
        }
};