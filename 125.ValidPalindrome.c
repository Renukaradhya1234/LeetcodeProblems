#include <stdbool.h>

bool isNumeric(char character) {
    if (character >= '0' && character <= '9') {
        return true;
    }
    return false;
}

bool isAlpha(char character) {
    if (character >= 'a' && character <= 'z') {
        return true;
    } else if (character >= 'A' && character <= 'Z') {
        return true;
    }
    return false;
}

char toLower(char character) {
    char lower_character = character;

    if (lower_character >= 'A' && lower_character <= 'Z') {
        lower_character += 32;
    }

    return lower_character;
}

bool isPalindrome(char* s) {
    int s_size = 0;
    while (s[s_size] != '\0') {
        s_size++;
    }
    int end_index = s_size-1;
    int start_index = 0;

    while (start_index <= end_index) {
        bool start_valid = isAlpha(s[start_index]) || isNumeric(s[start_index]);
        if (!start_valid) {
            start_index++;
        } else {
            bool end_valid = isAlpha(s[end_index]) || isNumeric(s[end_index]);
            if (!end_valid) {
                end_index--;
            } else {
                if (toLower(s[start_index++]) != toLower(s[end_index--])) {
                    return false;
                }
            }
        }
    }

    return true;
}