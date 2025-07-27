/**
 * Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

 

Example 1:

Input: s = "Hello"
Output: "hello"
Example 2:

Input: s = "here"
Output: "here"
Example 3:

Input: s = "LOVELY"
Output: "lovely"
 */

public class ToLowerCase {
    public String toLowerCase(String s) {
        char[] lowercase_char_array = new char[s.length()];
        int total_iteration = lowercase_char_array.length-1;

        for (int index = 0; index <= total_iteration; index++) {
            char character = s.charAt(index);
            if (character >= 65 && character <= 90) {
                // this character is upper case...
                lowercase_char_array[index] = (char) (character + 32);
            } else {
                lowercase_char_array[index] = character;
            }
        }

        return new String(lowercase_char_array);
    }

    public static void main(String[] args) {
        ToLowerCase to_lower_Case = new ToLowerCase();
        String input_sting = "LOVELY";

        String output_string = to_lower_Case.toLowerCase(input_sting);
        System.out.println(output_string);
    }
}
