
char* invalid_triangle = "none";
char* equilateral = "equilateral";
char* isosceles = "isosceles";
char* scalene = "scalene";

char* triangleType(int* nums, int numsSize) {
    int first_max = nums[0];
    int second_max = nums[1];
    int thrid_max = nums[2];

    char* result = invalid_triangle;

    if (first_max+second_max > thrid_max && first_max+thrid_max > second_max && second_max+thrid_max > first_max) {
        if (first_max == second_max && first_max == thrid_max) {
            result = equilateral;
        } else if (first_max == second_max || first_max == thrid_max) {
            result = isosceles;
        } else if (second_max == thrid_max) {
            result = isosceles;
        } else {
            result = scalene;
        }
    }

    return result;
}