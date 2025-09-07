int titleToNumber(char* columnTitle) {
    int result = 0;
    for (int index = 0; columnTitle[index] != '\0'; index++) {
        result = result * 26 + ( columnTitle[index] - 'A' ) + 1;
    }
    return result;
}