// a program to accept three numbers and find the largest and second largest among
// them. 
#include <stdio.h>

int main() {
    int num1, num2, num3;
    int largest, second_largest;

    // Input three numbers from user
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Determine the largest and second largest numbers
    if (num1 >= num2 && num1 >= num3) {
        largest = num1;
        second_largest = (num2 >= num3) ? num2 : num3;
    } else if (num2 >= num1 && num2 >= num3) {
        largest = num2;
        second_largest = (num1 >= num3) ? num1 : num3;
    } else {
        largest = num3;
        second_largest = (num1 >= num2) ? num1 : num2;
    }

    // Print the largest and second largest numbers
    printf("Largest number: %d\n", largest);
    printf("Second largest number: %d\n", second_largest);

    return 0;
}
