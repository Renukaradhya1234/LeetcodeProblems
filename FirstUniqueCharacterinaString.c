int firstUniqChar(char* s) {
    int counter_ref[26] = { 0 };
    for (int index = 0; s[index] != '\0'; index++) {
        counter_ref[ s[index] - 'a' ]++;
    }   

    int result = -1;
    for (int index = 0; s[index] != '\0'; index++) {
        if (counter_ref[ s[index] - 'a' ] == 1) {
            result = index;
            break;
        }
    }
    return result;
}