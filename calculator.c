// Make a C program of simple calculator using switch case.
#include <stdio.h>

int main() {
    char operator;
    double num1, num2, result;

    do {
        // Display calculator options
        printf("\nSimple Calculator:\n");
        printf("Enter + for addition\n");
        printf("Enter - for subtraction\n");
        printf("Enter * to exit\n");
        printf("Enter / for division\n");
        printf("Enter x for multiplication\n");
        printf("Choose an operator: ");
        scanf(" %c", &operator);  // Note the space before %c to consume any leftover newline characters

        // Check if user wants to exit
        if (operator == '*') {
            break;
        }

        // Input two numbers
        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);

        // Perform the chosen operation
        switch (operator) {
            case '+':
                result = num1 + num2;
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case '-':
                result = num1 - num2;
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;
            case 'x':
                result = num1 * num2;
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            default:
                printf("Invalid operator. Please try again.\n");
                break;
        }

    } while (1);  // Infinite loop, will break on entering '*'

    printf("Calculator exited.\n");
    return 0;
}

