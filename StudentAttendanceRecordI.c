#include <stdbool.h>

bool checkRecord(char* s) {
    int late_count = 0;
    int fewer_count = 0;
    for (int index = 0; s[index] != '\0'; index++) {
        if (s[index] == 'L') {
            late_count++;
        } else if (s[index] == 'A') {
            fewer_count++;
            late_count = 0;
        } else {
            late_count = 0;
        }
        if (late_count >= 3 || fewer_count >= 2) {
            break;
        }
    }

    bool result = false;
    if (late_count < 3 && fewer_count < 2) {
        result = true;
    }
    return result;
}