#include <stdbool.h>

bool hasAlternatingBits(int n) {
    /// right shift to get all opposite bit means 1s becomes 0s and 0s becomes 1s
    int n_opposite_bits = n>>1;
    
    /// checks which are all bits or in opposite. 
    // like 101 -> 010 = 111
    unsigned int consecutive_different_bits = n ^ n_opposite_bits;
    
    
    /// convert all consecutive 1s to 0 
    /// like 111 + 001 = 1000
    unsigned int converted_one_to_zero = consecutive_different_bits+1;
    
    /// check that any bits are same (collision) are present.
    if ((converted_one_to_zero & consecutive_different_bits) == 0) {
        return true;
    }
    /// if present then adjacent bits are same.
    return false;
}