#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    int s_index = 0;
    
    for (int t_index = 0; t[t_index] != '\0' && s[s_index] != '\0'; t_index++) {
        if (t[t_index] == s[s_index]) {
            s_index++;
        }
    }

    bool result = false;
    if (s[s_index] == '\0') {
        result = true;
    }
    return result;
}