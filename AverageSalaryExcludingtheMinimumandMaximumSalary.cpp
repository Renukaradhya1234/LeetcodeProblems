double average(int* salary, int salarySize) {
    int max_salary = 999;
    int min_salary = 10000000;
    int total_sum = 0;
    for (int index = 0; index < salarySize; index++) {
        if (salary[index] > max_salary) {
            max_salary = salary[index];
        }

        if (salary[index] < min_salary) {
            min_salary = salary[index];
        }

        total_sum += salary[index];
    }
    total_sum -= (max_salary + min_salary);
    return (double)total_sum/(salarySize-2);
}