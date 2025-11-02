#include <stdlib.h>
#include <stdio.h>

struct index_value_ref {
    int index;
    int value;
};

void swap(struct index_value_ref* index_value_ref_array, int first_index, int second_index) {
    struct index_value_ref temp = index_value_ref_array[first_index];
    index_value_ref_array[first_index] = index_value_ref_array[second_index];
    index_value_ref_array[second_index] = temp;
}

int getIndexToInsert(struct index_value_ref* index_value_ref_array, int start_index, int end_index, int value) {
    while (start_index <= end_index) {
        int mid_index = start_index + (end_index-start_index) / 2;
        if (index_value_ref_array[mid_index].value > value) {
            start_index = mid_index+1;
        } else {
            end_index = mid_index-1;
        }
    }
    return start_index;
}

void binaryInserationSort(struct index_value_ref* index_value_ref_array, int start_index, int end_index) {
    for (int index = start_index; index <= end_index; index++) {
        struct index_value_ref value = index_value_ref_array[index];

        int target_index = getIndexToInsert(index_value_ref_array, start_index, index-1, value.value);

        for (int sub_index = index-1; sub_index >= target_index; sub_index--) {
            index_value_ref_array[sub_index+1] = index_value_ref_array[sub_index];
        }
        index_value_ref_array[target_index] = value;
    }
}

void setPivotToLast(struct index_value_ref* index_value_ref_array, int start_index, int end_index) {
    int highest_index = 0;
    int mean_index = 0;
    int mid_index = start_index + (end_index-start_index)/2;
    
    if (index_value_ref_array[start_index].value > index_value_ref_array[mid_index].value && index_value_ref_array[start_index].value > index_value_ref_array[end_index].value) {
        highest_index = start_index;
    } else if (index_value_ref_array[mid_index].value > index_value_ref_array[start_index].value && index_value_ref_array[mid_index].value > index_value_ref_array[end_index].value) {
        highest_index = mid_index;
    } else {
        highest_index = end_index;
    }

    if (start_index == highest_index) {
        if (index_value_ref_array[mid_index].value > index_value_ref_array[end_index].value) {
            mean_index = mid_index;
        } else {
            mean_index = end_index;
        }
    } else if (mid_index == highest_index) {
        if (index_value_ref_array[start_index].value > index_value_ref_array[end_index].value) {
            mean_index = start_index;
        } else {
            mean_index = end_index;
        }
    } else {
        if (index_value_ref_array[start_index].value > index_value_ref_array[mid_index].value) {
            mean_index = start_index;
        } else {
            mean_index = mid_index;
        }
    }

    if (end_index != mean_index) {
        swap(index_value_ref_array, end_index, mean_index);
    }
}

void quickSort(struct index_value_ref* index_value_ref_array, int start_index, int end_index) {
    if (start_index < end_index) {
        int total_size = (end_index - start_index)+1;
        if (total_size <= 64) {
            binaryInserationSort(index_value_ref_array, start_index, end_index);    
        } else {
            setPivotToLast(index_value_ref_array, start_index, end_index);
            int pivot_index = start_index-1;
            int pivot_value = index_value_ref_array[end_index].value;

            for (int index = start_index; index < end_index; index++) {
                if (index_value_ref_array[index].value > pivot_value) {
                    swap(index_value_ref_array, ++pivot_index, index);
                }
            }

            swap(index_value_ref_array, ++pivot_index, end_index);
            quickSort(index_value_ref_array, start_index, pivot_index-1);
            quickSort(index_value_ref_array, pivot_index+1, end_index);
        }
    }
}

void introSort(struct index_value_ref* index_value_ref_array, int start_index, int end_index) {
    int total_size = (end_index-start_index)+1;
    if (total_size <= 64) {
        binaryInserationSort(index_value_ref_array, start_index, end_index);
    } else {
        quickSort(index_value_ref_array, start_index, end_index);
    }
}

char* integerToString(int number) {
    char number_array[10];
    int total_length = 0;
    
    while (number > 0) {
        int last_number = number % 10;
        number_array[total_length++] = '0' + last_number;
        number /= 10;
    }

    char* string = (char*)malloc((total_length+1)*sizeof(char));
    if (string != NULL) {
        string[total_length] = '\0';
        int last_index = total_length-1;
        for (int index = 0; index < total_length; index++) {
            string[index] = number_array[last_index--];
        }
    }
    return string;
}

char first_price[11] = "Gold Medal";
char second_price[13] = "Silver Medal";
char third_prices[13] = "Bronze Medal";

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    struct index_value_ref* index_value_ref_array  = (struct index_value_ref*)malloc(scoreSize*sizeof(struct index_value_ref));
    char** result = NULL;
    *returnSize = 0;
    if (index_value_ref_array != NULL) {
        
        for (int index = 0; index < scoreSize; index++) {
            struct index_value_ref index_value;
            index_value.index = index;
            index_value.value = score[index];

            index_value_ref_array[index] = index_value;
        }

        introSort(index_value_ref_array, 0, scoreSize-1);

        result = (char**)malloc(scoreSize*sizeof(char*));
        if (result != NULL) {
            printf("memeory allocated....");
            *returnSize = scoreSize;
            for (int index = 0; index < scoreSize; index++) {
                struct index_value_ref index_value = index_value_ref_array[index];
                if (index == 0) {
                    result[index_value.index] = first_price;
                } else if (index == 1) {
                    result[index_value.index] = second_price;
                } else if (index == 2) {
                    result[index_value.index] = third_prices;
                } else {
                    result[index_value.index] = integerToString(index+1);
                }
            }
        }
    }
    free(index_value_ref_array);
    return result;
}