#include <stdio.h>
#include <stdbool.h>

bool canConstruct(char* ransomNote, char* magazine) {
    int alphabets[26] = {0};

    for (int index=0; magazine[index] != '\0'; index++) {
        alphabets[ magazine[index] - 'a' ]++;
    }

    bool result = true;
    for (int index=0; ransomNote[index] != '\0'; index++) {
        if (alphabets[ ransomNote[index] - 'a' ] == 0) {
            result = false;
            break;
        }
        alphabets[ ransomNote[index] - 'a' ]--;
    }

    return result;
}

int main() {

    return 0;
}