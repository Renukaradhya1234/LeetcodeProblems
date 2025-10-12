#include <stdbool.h>

bool isAllCharactersAreCaptial(char* word) {
    bool result = true;
    for (unsigned int index = 1; word[index] != '\0'; index++) {
        if (word[index] < 'A' || word[index] > 'Z') {
            result = false;
            break;
        }
    }
    return result;
}

bool isAllCharactersAreSmall(char* word) {
    bool result = true;
    for (unsigned int index = 1; word[index] != '\0'; index++) {
        if (word[index] < 'a' || word[index] > 'z') {
            result = false;
            break;
        }
    }
    return result;
}

bool detectCapitalUse(char* word) {
    bool result = true;
    if (word[0] >= 'A' && word[0] <= 'Z') {
        // if first word is captial...
        if (!(isAllCharactersAreCaptial(word) || isAllCharactersAreSmall(word))) {
            result = false;
        }
    } else if(!isAllCharactersAreSmall(word)) {
        result = false;
    }
    return result;
}