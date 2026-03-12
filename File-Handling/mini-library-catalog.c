#include <stdio.h>
#include <stdlib.h>

struct Book {
    int id;
    char title[50];
    char author[50];
};

void addBook() {
    FILE *fp;
    struct Book b;

    fp = fopen("library.txt", "a");

    printf("Enter Book ID: ");
    scanf("%d", &b.id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", b.title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", b.author);

    fprintf(fp, "%d %s %s\n", b.id, b.title, b.author);

    fclose(fp);
    printf("Book added successfully!\n");
}

void displayBooks() {
    FILE *fp;
    struct Book b;

    fp = fopen("library.txt", "r");

    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\nLibrary Catalog:\n");

    while (fscanf(fp, "%d %s %s", &b.id, b.title, b.author) != EOF) {
        printf("ID: %d | Title: %s | Author: %s\n", b.id, b.title, b.author);
    }

    fclose(fp);
}

int main() {
    int choice;

    do {
        printf("\n--- Mini Library Catalog ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while(choice != 3);

    return 0;
}
