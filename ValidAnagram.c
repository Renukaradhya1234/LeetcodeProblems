#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    int s_count[26] = { 0 };
    int t_count[26] = { 0 };

    int s_count_index = 0;
    int t_count_index = 0;

    while (s[s_count_index] != '\0' && t[t_count_index] != '\0') {
        s_count[ s[s_count_index] - 'a' ]++;
        t_count[ t[t_count_index] - 'a' ]++;

        s_count_index++;
        t_count_index++;
    }

    while (s[s_count_index] != '\0') {
        s_count[ s[s_count_index] - 'a' ]++;
        s_count_index++;
    }

    while (t[t_count_index] != '\0') {
        t_count[ t[t_count_index] - 'a' ]++;
        t_count_index++;
    }

    bool result = true;
    for (int index = 0; index < 26; index++) {
        if (s_count[index] != t_count[index]) {
            result = false;
            break;
        }
    }
    return result;
}