#include <stdbool.h>

int minDeletion(char* s, int k) {
    int s_buffer[26] = { 0 };
    int distinct_letters = 0;
    for (int index = 0; s[index] != '\0'; index++) {
        s_buffer[ s[index] - 'a' ]++;
        if (s_buffer[ s[index] - 'a' ] == 1) {
            distinct_letters++;
        }
    }

    int result = 0;
    if (distinct_letters > k) {
        int frequency_buffer[17] = {0};
        for (int index = 0; index < 26; index++) {
            if (s_buffer[index] > 0) {
                frequency_buffer[ s_buffer[index] ]++;
            }
        }
        int remaining_deletion = distinct_letters-k;
        int delection_count = 0;
        for (int index = 0; index < 17; index++) {
            bool stop_iteration = false;

            int frequency_count = frequency_buffer[index];

            while (frequency_count > 0) {
                result += index;
                delection_count++;
                if (delection_count == remaining_deletion) {
                    stop_iteration = true;
                    break;
                }

                frequency_count--;
            }

            if (stop_iteration) {
                break;
            }
        }
    }
    return result;
}

