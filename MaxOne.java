public class MaxOne {
    public int findMaxConsecutiveOnes(int[] nums) {
        int max_one = 0;
        int counting_one = 0;
        int total_iteration = nums.length-1;

        for (int index = 0; index <= total_iteration; index++) {
            if (nums[index] == 1) {
                counting_one++;
            } else {
                if (max_one < counting_one) {
                    max_one = counting_one;
                }
                counting_one = 0;
            }
        }

        if (max_one < counting_one) {
            max_one = counting_one;
        }

        return max_one;
    }

    public static void main(String[] args) {
        MaxOne max_one = new MaxOne();
        int[] input_array = { 1,0,1,1,0,1 };

        int output = max_one.findMaxConsecutiveOnes(input_array);
        System.out.println("output:- " + output);
    }
}
