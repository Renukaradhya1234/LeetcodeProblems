/**
 * Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 */
import java.util.ArrayList;

public class IntersectionOfTwoArray {
    private void swapTheIndicesValue(int[] array, int first_index, int second_index) {
        int temp = array[first_index];
        array[first_index] = array[second_index];
        array[second_index] = temp;
    }

    private int partionTheArray(int[] array, int start_index, int end_index) {
        int pivot = array[end_index];
        int pivot_index = start_index-1;
        for (int index = start_index; index <= end_index; index++) {
            if (array[index] < pivot) {
                pivot_index++;
                this.swapTheIndicesValue(array, pivot_index, index);
            }
        }
        pivot_index++;
        this.swapTheIndicesValue(array, pivot_index, end_index);

        return pivot_index;
    }
    
    private void quickSort(int[] array, int start_index, int end_index) {
        if (start_index < end_index) {
            int pivot_index = this.partionTheArray(array, start_index, end_index);
            this.quickSort(array, start_index, pivot_index-1);
            this.quickSort(array, pivot_index+1, end_index);
        }
    }

    private boolean isValuePresent(int[] array, int target_value, int start_index, int end_index) {
        boolean result = false;
        while (start_index <= end_index) {
            int mid_index = start_index + ( (end_index - start_index ) / 2 );
            int temp_target_value = array[mid_index];
            if (temp_target_value == target_value) {
                result = true;
                break;
            } else if (temp_target_value < target_value) {
                start_index = mid_index + 1;
            } else {
                end_index = mid_index - 1;
            }
        }
        return result;
    }

    private ArrayList<Integer> getIntersectionElements(int[] array_to_iterator, int iter_array_length, int[] array_to_value_find, int value_array_length) {
        ArrayList<Integer> array_list = new ArrayList<Integer>();   
        for (int index = 0; index <= iter_array_length; index++) {
            int value = array_to_iterator[index];
            if (array_list.contains(value) == false && this.isValuePresent(array_to_value_find, value, 0, value_array_length)) {
                array_list.add(value);
            }
        }
        return array_list;
    }

    public int[] intersection(int[] nums1, int[] nums2) {
        /**
         * steps:- 
         * 1. sort the array in ascending order. ( best algorithm sorting - quick sort )...
         * 2. pick the minimum length of the array. and find the value of min array in large array. ( best algorithm for searching - binary search )
         */
        int first_array_length = nums1.length-1;
        int second_array_length = nums2.length-1;
        this.quickSort(nums1, 0, first_array_length);
        this.quickSort(nums2, 0, second_array_length);

        ArrayList<Integer> array_list = null;
        if (first_array_length > second_array_length) {
            array_list = this.getIntersectionElements(nums2, second_array_length, nums1, first_array_length);
        } else {
            array_list = this.getIntersectionElements(nums1, first_array_length, nums2, second_array_length);
        }

        int total_elements = array_list.size()-1;
        int[] intersection_array = new int[total_elements+1];
        for (int index = 0; index <= total_elements; index++) {
            intersection_array[index] = array_list.get(index);
        }
        return intersection_array;
    }

    private void printArray(int[] array) {
        int total_iteraion = array.length-1;
        for (int index = 0; index <= total_iteraion; index++) {
            System.out.print(array[index] + ",");
        }
        System.out.println("");
    }

    public static void main(String[] args) {
        IntersectionOfTwoArray intersection_two_array = new IntersectionOfTwoArray();
        int[] first_input_array = { 4,9,5 };
        int[] second_input_array = { 9,4,9,8,4 };

        int[] intersection_array = intersection_two_array.intersection(first_input_array, second_input_array);
        intersection_two_array.printArray(intersection_array);
    }
}
