#include <vector>

class Solution {
    public:
        void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
            int merged_index = nums1.size();
            int m_last_index = --m;
            int n_last_index = --n;
            while (m_last_index >= 0 && n_last_index >= 0) {
                if (nums1[m_last_index] > nums2[n_last_index]) {
                    nums1[--merged_index] = nums1[m_last_index--];
                } else {
                    nums1[--merged_index] = nums2[n_last_index--];
                }
            }

            while (n_last_index >= 0) {
                nums1[--merged_index] = nums2[n_last_index--];
            }
        }
};