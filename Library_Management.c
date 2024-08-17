#include <stdio.h>

int main() {
    char membershipType;
    int booksRequested;

    // Take user input for membership type
    printf("Enter your membership type (R for Regular, P for Premium, G for Guest): ");
    scanf(" %c", &membershipType);

    // Take user input for the number of books they want to borrow
    printf("Enter the number of books you want to borrow: ");
    scanf("%d", &booksRequested);

    // Determine whether the user can borrow the requested number of books
    if (membershipType == 'R') {
        if (booksRequested <= 5) {
            printf("You can borrow %d books.\n", booksRequested);
        } else {
            printf("You cannot borrow more than 5 books as a Regular member.\n");
        }
    } else if (membershipType == 'P') {
        if (booksRequested <= 10) {
            printf("You can borrow %d books.\n", booksRequested);
        } else {
            printf("You cannot borrow more than 10 books as a Premium member.\n");
        }
    } else if (membershipType == 'G') {
        if (booksRequested <= 2) {
            printf("You can borrow %d books.\n", booksRequested);
        } else {
            printf("You cannot borrow more than 2 books as a Guest member.\n");
        }
    } else {
        printf("Invalid membership type entered.\n");
    }

    return 0;
}
