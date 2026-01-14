#include <vector>
#include <string>
#include <stack>

class Solution {
    public:
        std::vector<std::string> buildArray(std::vector<int>& target, int n) {
            const unsigned int TARGET_SIZE = target.size();
            int start_index = 0;
            std::vector<std::string> operations;
            std::stack<int> target_stack;
            for (unsigned int number = 1; number <= n; number++) {
                if (start_index >= TARGET_SIZE) {
                    break;
                }
                target_stack.push(number);
                operations.push_back("Push");
                if (target[start_index] != target_stack.top()) {
                    target_stack.pop();
                    operations.push_back("Pop");
                } else {
                    start_index++;
                }
            }

            return operations;
        }
};