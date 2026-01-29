class Solution {
    public:
        bool isPalindrome(int x) {
            bool is_palindrome = false;
            if (x >= 0) {
                unsigned int reverse_x = 0;
                int temp_x = x;
                while (temp_x > 0) {
                    reverse_x *= 10;
                    reverse_x += temp_x%10;
                    temp_x /= 10;
                }

                if (x == reverse_x) {
                    is_palindrome = true;
                }
            }
            return is_palindrome;
        }
};