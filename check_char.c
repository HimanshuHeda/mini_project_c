// Write a C program to input any character and check whether it is alphabet, digit or special character.
#include <stdio.h>

int main() {
    char ch;

    // Input a character from the user
    printf("Enter a character: ");
    scanf("%c", &ch);

    // Check if the character is an alphabet
    if (isalpha(ch)) {
        printf("The character '%c' is an alphabet.\n", ch);
    }
    // Check if the character is a digit
    else if (isdigit(ch)) {
        printf("The character '%c' is a digit.\n", ch);
    }
    // If it's neither an alphabet nor a digit, it is a special character
    else {
        printf("The character '%c' is a special character.\n", ch);
    }

    return 0;
}
