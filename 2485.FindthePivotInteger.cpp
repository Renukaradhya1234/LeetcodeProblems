#include <cmath>

class Solution {
    public:
        int pivotInteger(int n) {
            int n_square = n*n;
            int n_square_plus_n = n_square + n;
            int x_square = n_square_plus_n/2;

            int pivot_integer = -1;
            int x = std::sqrt(x_square);
            int real_x_square = x*x;
            if (real_x_square == x_square) {
                pivot_integer = x;
            }
            return pivot_integer;
        }
};