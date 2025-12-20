#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize) {
    int alice_total = 0;
    for (int index = 0; index < aliceSizesSize; index++) {
        alice_total += aliceSizes[index];
    }

    int bob_total = 0;
    for (int index = 0; index < bobSizesSize; index++) {
        bob_total += bobSizes[index];
    }

    /// equation to find the answer...
    /// 1. AliceTotal == BobTotal
    /// here Alice need to give X number of candidates to BobTotal
    /// and Bob need to give Y number of candidates to Alice.
    /// so, equation is AliceTotal - X + Y = BobTotal - Y + X
    /// so AliceTotal - BobTotal = X + X - Y - Y
    /// AliceTotal - BobTotal = 2X - 2Y
    /// AliceTotal - BobTotal = 2 (X-Y)
    /// (AliceTotal - BobTotal)/2 = X-Y
    /// finally = X = ((AliceTotal - BobTotal) / 2 ) + Y
    /// so Number candidates That alias should give is = ((AliceTotal - BobTotal) / 2 ) + Y
    
    int difference = (alice_total - bob_total) / 2;
    int* swap_candy = (int*)calloc(2, sizeof(int));
    *returnSize = 2;
    for (int index = 0; index < aliceSizesSize; index++) {
        int x = aliceSizes[index];
        int found = 0;
        for (int bob_index = 0; bob_index < bobSizesSize; bob_index++) {
            if (x == difference + bobSizes[bob_index]) {
                swap_candy[0] = x;
                swap_candy[1] = bobSizes[bob_index];
                found = 1;
                break;
            }
        }

        if (found == 1) {
            break;
        }
    }

    return swap_candy;
}