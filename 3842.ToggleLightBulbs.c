#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* toggleLightBulbs(int* bulbs, int bulbsSize, int* returnSize) {
    int toggle_light_bulbs[101] = {};
    for (int index = 0; index < bulbsSize; index++) {
        toggle_light_bulbs[ bulbs[index] ]++;
    }   

    int total_on_bulbs = 0;
    for (int index = 1; index < 101; index++) {
        if (toggle_light_bulbs[index] % 2 == 1) {
            total_on_bulbs++;
        }
    }

    int* on_bulbs = (int*)malloc(total_on_bulbs*sizeof(int));
    if (on_bulbs == NULL) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = total_on_bulbs;
    int array_index = 0;
    for (int index = 1; index < 101; index++) {
        if (toggle_light_bulbs[index] % 2 == 1) {
            on_bulbs[array_index++] = index;
        }
    }

    return on_bulbs;
}