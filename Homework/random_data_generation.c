#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "book_division.h"

void generateAndSaveRandomBooks(int books[], int nr_books) {
    srand(time(NULL));
    for (int i = 0; i < nr_books; i++) {
        books[i] = rand() % 100000000 + 1;
    }

    FILE *file = fopen("random_book_data.txt", "w");
    for (int i = 0; i < nr_books; i++) {
        fprintf(file, "%d ", books[i]);
    }
    fclose(file);
}

void randomtestDataGeneration() {
    int nr_books;
    int books[MAX_BOOKS];

    printf("Enter the number of books for random data generation: ");
    scanf("%d", &nr_books);

    generateAndSaveRandomBooks(books, nr_books);

    printf("Random book data has been generated and saved to random_book_data.txt\n");
}
