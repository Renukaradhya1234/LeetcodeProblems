/**
 * Given a string s, return the number of segments in the string.

A segment is defined to be a contiguous sequence of non-space characters.

 

Example 1:

Input: s = "Hello, my name is John"
Output: 5
Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
Example 2:

Input: s = "Hello"
Output: 1
 */

class SegmentString {
    public int countSegments(String s) {
        int segment_count = 0;
        int total_iteration = s.length()-1;
        boolean word_counting = false;

        for (int index = 0; index <= total_iteration; index++) {
            if (s.charAt(index) == ' ') {
                if (word_counting) {
                    segment_count++;
                    word_counting = false;
                }
            } else if (word_counting == false) {
                word_counting = true;
            }
        }

        if (word_counting) {
            segment_count++;
        }
        return segment_count;
    }

    public static void main(String[] args) {
        SegmentString solution = new SegmentString();
        String inputString = "                         ";
        int segment_count = solution.countSegments(inputString);
        System.out.println("Total Segment:- " + segment_count);
    }
}