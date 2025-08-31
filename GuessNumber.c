#include <stdio.h>
int guess(int num){ // this is declared in server...
    int result = -1;
    int picked_number = 2;
    if (num == picked_number) {
        result = 0;
    } else if (num < picked_number) {
        result = 1;
    }
    return result;
}
int guessNumber(int n){
	unsigned int start_number = 1;
    unsigned int mid_number = 0;
    unsigned int end_number = n;
    int guess_number = 0;
    while (start_number <= end_number) {
        mid_number = start_number + (end_number-start_number) / 2;
        guess_number = guess(mid_number);

        if (guess_number == 0) {
            break;
        } else if (guess_number == 1) {
            start_number = mid_number+1;
        } else {
            end_number = mid_number-1;
        }
    }

    return mid_number;
}


int main() {
    int max_number = 2;
    int guess_number = guessNumber(max_number);
    printf("picked number:- %d\n", guess_number);
    return 0;
}