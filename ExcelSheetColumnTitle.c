#include <stdlib.h>
#include <stdio.h>

char* convertToTitle(int columnNumber) {
    char buffer[32];
    unsigned string_length = 0;
    while (columnNumber > 0) {
        columnNumber--;
        buffer[string_length] = 'A' + columnNumber % 26;
        string_length++;
        columnNumber /= 26;
    }

    char* result_string = (char*) malloc(string_length+1 * sizeof(char));
    unsigned int total_size = string_length;
    result_string[string_length] = '\0';
    for (unsigned int index = 0; index < total_size; index++) {
        result_string[index] = buffer[--string_length];
    }
    return result_string;
}

int main() {
    unsigned int input = 1;
    char* result = convertToTitle(input);
    for (unsigned int index = 0; result[index] != '\0'; index++) {
        printf("char: %c\n", result[index]);
    }

    return 0;
}