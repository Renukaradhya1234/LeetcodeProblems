/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
 
char first_row_keys[] = { 'E', 'I', 'O', 'P', 'Q', 'R', 'T', 'U', 'W', 'Y' };
char second_row_keys[] = { 'A', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'S' };
char third_row_keys[] = { 'B', 'C', 'M', 'N', 'V', 'X', 'Z' };

int isElementPresentInArray(char character, char* character_array, unsigned int array_size) {
    int result = 0;
    int start_index = 0;
    int end_index = array_size-1;
    int mid_index;
    while (start_index <= end_index) {
        mid_index = start_index + ((end_index - start_index) / 2);
        if (character_array[mid_index] == character) {
            result = 1;
            break;
        } else if (character_array[mid_index] < character) {
            start_index = mid_index+1;
        } else {
            end_index = mid_index-1;
        }
    }
    return result;
}

unsigned int getElementRowNumber(char character) {
    unsigned int result = 0;
    if (character >= 'a' && character <= 'z') {
        character = character-32;
    }
    result = isElementPresentInArray(character, first_row_keys, sizeof(first_row_keys)/sizeof(char));
    if (result == 0) {
        unsigned int is_present = isElementPresentInArray(character, second_row_keys, sizeof(second_row_keys)/sizeof(char));
        if (is_present == 1) { result = 2; }
    }
    if (result == 0) {
        unsigned int is_present = isElementPresentInArray(character, third_row_keys, sizeof(third_row_keys)/sizeof(char));
        if (is_present == 1) { result = 3; }
    }

    return result;
}

char** findWords(char** words, int wordsSize, int* returnSize) {
    unsigned int total_words = 0;
    int* valid_word_ref = calloc(wordsSize, sizeof(int));
    for (unsigned int index = 0; index < wordsSize; index++) {
        char* single_word = words[index];
        unsigned int valid = 1;
        unsigned int row_number = getElementRowNumber(single_word[0]);

        for (unsigned int char_index = 1; single_word[char_index] != '\0'; char_index++) {
            unsigned int character_row_number = getElementRowNumber(single_word[char_index]);
            if (character_row_number != row_number) {
                valid = 0;
                break;
            }
        }
        
        if (valid == 1) {
            total_words++;
            valid_word_ref[index] = 1;
        }
    }

    char** output = malloc(total_words*sizeof(char*));
    *returnSize = total_words;
    unsigned int ref_index = 0;
    for (unsigned int index = 0; index < wordsSize; index++) {
        if (valid_word_ref[index] == 1) {
            output[ref_index++] = words[index];
        }
    }
    free(valid_word_ref);
    return output;
}