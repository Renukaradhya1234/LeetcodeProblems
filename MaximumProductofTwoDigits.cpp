class Solution {
    public:
        int maxProduct(int n) {
            int first_max = 0;
            int second_max = 0;

            while (n > 0) {
                int last_digit = n % 10;
                if (first_max < last_digit) {
                    second_max = first_max;
                    first_max = last_digit;
                } else if (second_max < last_digit) {
                    second_max = last_digit;
                }
                n /= 10;
            }

            return first_max * second_max;
        }
};