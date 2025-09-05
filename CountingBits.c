#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 int* countBits(int n, int* returnSize) {
   *returnSize = n + 1;
    int* result = (int*) malloc(*returnSize * sizeof(int));
    result[0] = 0;
    int temp;
    for (int index = 1; index <= n; index++) {
        temp = index;
        result[index] = 0;
        while (temp > 0) {
            if (temp % 2 == 1) {
                result[index]++;
            }

            temp /= 2;
        }
    }

    return result;
}