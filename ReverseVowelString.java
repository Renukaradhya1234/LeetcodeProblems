/**
 * Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "IceCreAm"

Output: "AceCreIm"

Explanation:

The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:

Input: s = "leetcode"

Output: "leotcede"
 */


public class ReverseVowelString {
    public String reverseVowels(String s) {
        char[] char_array = s.toCharArray();
        String vowels = "aeiouAEIOU";

        int start_index = 0;
        int end_index = char_array.length - 1;
    
        while (start_index <= end_index) {
            int first_vowel = vowels.indexOf(char_array[start_index]);
            int second_vowel = vowels.indexOf(char_array[end_index]);
            if (first_vowel == -1) {
                start_index++;
            } else if (second_vowel == -1) {
                end_index--;
            } else {
                char temp = char_array[start_index];
                char_array[start_index] = char_array[end_index];
                char_array[end_index] = temp;

                start_index++;
                end_index--;
            }
        }

        StringBuilder string_builder = new StringBuilder();
        int total_iteration = char_array.length-1;
        for (int index = 0; index <= total_iteration; index++) {
            string_builder.append(char_array[index]);
        }

        return new String(char_array);
    }

    public static void main(String[] args) {
        ReverseVowelString reverseVowelString = new ReverseVowelString();
        String input_string = "leetcode";
        String reversed_string = reverseVowelString.reverseVowels(input_string);

        String output_string = "leotcede";
        if (reversed_string.equals(output_string)) {
            System.out.println("Sucessfully reversed...");
        } else {
            System.out.println("failed :- " + reversed_string + " " + output_string);
            System.out.println("reversed-string-length:- " + reversed_string.length());
            System.out.println("output-string-length:- " + output_string.length());
        }
    }
}
