#include <stdio.h>

/**
0 <= s.length <= 1000
t.length == s.length + 1
s and t consist of lowercase English letters.
*/

char findTheDifference(char* s, char* t) {
    int alphabets[26] = {0};
    unsigned int index = 0;
    
    while (s[index] != '\0') {
        alphabets[ t[index]-'a' ]++;
        alphabets[ s[index]-'a' ]--;
        index++;
    }
    alphabets[ t[index] ]++;

    char result = 'a';
    for (int index = 0; index <= 25; index++) {
        if (alphabets[index] == 1) {
            result = index+'a';
            break;
        }
    }
    return result;
}


int main() {

    return 0;
}