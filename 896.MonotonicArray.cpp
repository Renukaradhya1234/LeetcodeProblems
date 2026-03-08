#include <vector>

using namespace std;

class Solution {
    public:
        bool isMonotonic(vector<int>& nums) {
            int nums_size = nums.size();
            if (nums_size == 1) {
                return true;
            }
            
            bool increasing_order = true;
            bool decreasing_order = true;

            for (int index = 1; index < nums_size; index++) {
                int current_data = nums[index];
                int previous_data = nums[index-1];
                if (current_data > previous_data) {
                    // it may be increasing order...
                    decreasing_order = false;
                    if (!increasing_order) {
                        return false;
                    }
                }

                if (current_data < previous_data) {
                    // it may be decreasing order...
                    increasing_order = false;
                    if (!decreasing_order) {
                        return false;
                    }
                }
            }

           return true;
        }
};