/**
 * Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 */


public class BinarySearch {
    public int search(int[] nums, int target) {
        int target_index = -1;
        int start_index = 0;
        int end_index = nums.length-1;

        while (start_index <= end_index) {
            int mid_index = start_index + ( (end_index-start_index) / 2 );
            int mid_value = nums[mid_index];

            if (mid_value == target) {
                target_index = mid_index;
                break;
            } else if (mid_value > target) {
                end_index = mid_index - 1;
            } else {
                start_index = mid_index + 1;
            }
        }

        return target_index;
    }

    public static void main(String[] args) {
        BinarySearch binary_search = new BinarySearch();
        int[] input_array = { -1,0,3,5,9,12 };
        int target = 2;

        int target_index = binary_search.search(input_array, target);
        System.out.println("target_index:- " + target_index);
    }
}
