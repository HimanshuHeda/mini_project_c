// a program to check whether the given number is a Prime number.

#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num) {
    // Corner cases
    if (num <= 1) {
        return 0; // 0 and 1 are not prime numbers
    }

    // Check from 2 to sqrt(num)
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Not a prime number
        }
    }
    return 1; // Prime number
}

int main() {
    int number;
    
    // Input number from user
    printf("Enter a number: ");
    scanf("%d", &number);
    
    // Check if the number is prime
    if (isPrime(number)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }
    
    return 0;
}
