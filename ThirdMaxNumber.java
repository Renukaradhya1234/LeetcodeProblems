/**
 * 
 * Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

 

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.
 */

import java.util.ArrayList;

public class ThirdMaxNumber {
    // private int partionTheArray(int[] nums, int start_index, int end_index) {
    //     int iter_start = start_index-1;
    //     int pivot = nums[end_index];
    //     for (int index = start_index; index <= end_index-1; index++) {
    //         if (nums[index] > pivot) {
    //             iter_start++;
    //             this.swap(nums, iter_start, index);
    //         }
    //     }
    //     this.swap(nums, ++iter_start, end_index);
    //     return iter_start;
    // }

    // private void swap(int[] nums, int first_index, int second_index) {
    //     int temp = nums[first_index];
    //     nums[first_index] = nums[second_index];
    //     nums[second_index] = temp;
    // }
    
    // private void sortTheArray(int[] nums, int start_index, int end_index) {
    //     if (start_index < end_index) {
    //         int pivot_index = this.partionTheArray(nums, start_index, end_index);
    //         this.sortTheArray(nums, start_index, pivot_index-1);
    //         this.sortTheArray(nums, pivot_index+1, end_index);
    //     }
    // }

    public int thirdMax(int[] nums) {
        ArrayList<Integer> higgest_three_numbers = new ArrayList<Integer>();
        int total_iteraion = nums.length-1;
        for(int index = 0; index <= total_iteraion; index++) {
            int max_number_index = index;
            for (int sub_index = index+1; sub_index <= total_iteraion; sub_index++) {
                if (nums[sub_index] > nums[max_number_index]) {
                    max_number_index = sub_index;
                }
            }
            int temp = nums[max_number_index];
            nums[max_number_index] = nums[index];
            nums[index] = temp;
            if (higgest_three_numbers.contains(temp) == false) {
                higgest_three_numbers.add(temp);
                if (higgest_three_numbers.size() == 3) {
                    break;
                }
            }
        }
        System.out.println(higgest_three_numbers.size());
        if (higgest_three_numbers.size() == 3) {
            return higgest_three_numbers.get(higgest_three_numbers.size()-1);
        }
        return higgest_three_numbers.get(0);
    }

    private void printArray(int[] array) {
        int total_iteraion = array.length-1;
        for (int index = 0; index <= total_iteraion; index++) {
            System.out.print(array[index]);
        }
        System.out.println("");
    }

    public static void main(String[] args) {
        ThirdMaxNumber third_max_number = new ThirdMaxNumber();
        int[] input_array = { 2,2,3,1 };
        int output_number = third_max_number.thirdMax(input_array);
        // System.out.println("sorted array:- " + input_array);
        third_max_number.printArray(input_array);
        System.out.println("Output:- " + output_number);
    }
}
