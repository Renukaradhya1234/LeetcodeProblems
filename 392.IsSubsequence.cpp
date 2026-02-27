#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int s_index = 0;

        int s_size = s.size();
        int t_size = t.size();

        for (int t_index = 0; t_index < t_size && s_index < s_size ; t_index++) {
            if (t[t_index] == s[s_index]) {
                s_index++;
            }
        }

        if (s_index == s_size) {
            return true;
        }
        return false;
    }
};
