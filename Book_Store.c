#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure to represent a book
struct Book {
    char title[100];
    char author[100];
    float price;
    int stock;
};

// Global array to store books
struct Book inventory[MAX_BOOKS];

// Function prototypes
void addBook();
void updateStock();
void updatePrice();
void searchBook();
void displayInventory();
void removeBook();

int main() {
    int choice;

    do {
        printf("\n========= Bookstore Inventory Management System =========\n");
        printf("1. Add a new book\n");
        printf("2. Update stock of a book\n");
        printf("3. Update price of a book\n");
        printf("4. Search for a book\n");
        printf("5. Display all books in inventory\n");
        printf("6. Remove a book from inventory\n");
        printf("0. Exit\n");
        printf("=========================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addBook();
                break;
            case 2:
                updateStock();
                break;
            case 3:
                updatePrice();
                break;
            case 4:
                searchBook();
                break;
            case 5:
                displayInventory();
                break;
            case 6:
                removeBook();
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while(choice != 0);

    return 0;
}

void addBook() {
    if (MAX_BOOKS <= 0) {
        printf("Sorry, the inventory is full. Cannot add more books.\n");
        return;
    }

    struct Book newBook;
    printf("Enter the title of the book: ");
    getchar(); // Clearing the newline character left in the buffer
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove newline character

    printf("Enter the author of the book: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove newline character

    printf("Enter the price of the book: ");
    scanf("%f", &newBook.price);

    printf("Enter the number of copies available: ");
    scanf("%d", &newBook.stock);

    // Add the new book to the inventory
    inventory[MAX_BOOKS - 1] = newBook;
    MAX_BOOKS--;

    printf("Book added successfully to inventory.\n");
}

void updateStock() {
    char title[100];
    printf("Enter the title of the book to update stock: ");
    getchar(); // Clearing the newline character left in the buffer
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline character

    int found = 0;
    for (int i = 0; i < MAX_BOOKS; ++i) {
        if (strcmp(inventory[i].title, title) == 0) {
            printf("Enter the new stock for %s: ", inventory[i].title);
            scanf("%d", &inventory[i].stock);
            printf("Stock updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found in inventory.\n");
    }
}

void updatePrice() {
    char title[100];
    printf("Enter the title of the book to update price: ");
    getchar(); // Clearing the newline character left in the buffer
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline character

    int found = 0;
    for (int i = 0; i < MAX_BOOKS; ++i) {
        if (strcmp(inventory[i].title, title) == 0) {
            printf("Enter the new price for %s: ", inventory[i].title);
            scanf("%f", &inventory[i].price);
            printf("Price updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found in inventory.\n");
    }
}

void searchBook() {
    char keyword[100];
    printf("Enter the title or author to search for: ");
    getchar(); // Clearing the newline character left in the buffer
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0'; // Remove newline character

    int found = 0;
    for (int i = 0; i < MAX_BOOKS; ++i) {
        if (strstr(inventory[i].title, keyword) != NULL || strstr(inventory[i].author, keyword) != NULL) {
            printf("Book found:\n");
            printf("Title: %s\n", inventory[i].title);
            printf("Author: %s\n", inventory[i].author);
            printf("Price: %.2f\n", inventory[i].price);
            printf("Stock: %d\n", inventory[i].stock);
            found = 1;
        }
    }

    if (!found) {
        printf("Book not found in inventory.\n");
    }
}

void displayInventory() {
    if (MAX_BOOKS == 100) {
        printf("Inventory is empty.\n");
    }
    else {
        printf("========= Inventory =========\n");
        for (int i = 0; i < 100 - MAX_BOOKS; ++i) {
            printf("Book %d:\n", i + 1);
            printf("Title: %s\n", inventory[i].title);
            printf("Author: %s\n", inventory[i].author);
            printf("Price: %.2f\n", inventory[i].price);
            printf("Stock: %d\n", inventory[i].stock);
        }
        printf("==============================\n");
    }
}

void removeBook() {
    char title[100];
    printf("Enter the title of the book to remove from inventory: ");
    getchar(); // Clearing the newline character left in the buffer
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline character

    int found = 0;
    for (int i = 0; i < MAX_BOOKS; ++i) {
        if (strcmp(inventory[i].title, title) == 0) {
            // Shift books to the left to fill the removed book's place
            for (int j = i; j < 100 - MAX_BOOKS - 1; ++j) {
                inventory[j] = inventory[j + 1];
            }
            MAX_BOOKS++;
            printf("Book removed successfully from inventory.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found in inventory.\n");
    }
}
