/**
 * Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

 

Example 1:

Input: n = 16
Output: true
Example 2:

Input: n = 5
Output: false
Example 3:

Input: n = 1
Output: true
 
 */


public class PowerOfFour {
    public boolean isPowerOfFour(int n) {
        boolean result = false;
        /** should be greater then 0 */
        if (n >= 1) {
            /** should be divide by 4 */
            if (n % 4 == 0) {
                double quotient = n;
                while (quotient > 1) {
                    quotient = quotient / 4;
                }
                if (quotient == 1.0) {
                    result = true;
                }
            } else if (n == 1) {
                // execption for 1
                result = true;
            }
        }

        return result;
    }

    public static void main(String[] args) {
        PowerOfFour power_of_four = new PowerOfFour();
        int input_number = 4096;
        boolean result = power_of_four.isPowerOfFour(input_number);
        System.out.println("result:- " + result);
    }
}
