void reverseString(char* s, int sSize) {
    int start_index = 0;
    int end_index = sSize-1;
    int temp;
    while (start_index < end_index) {
        temp = s[start_index];
        s[start_index] = s[end_index];
        s[end_index] = temp;

        start_index++;
        end_index--;
    }
}