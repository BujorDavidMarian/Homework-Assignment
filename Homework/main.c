#include <stdio.h>
#include <stdlib.h>
#include "book_division.h"

void testDataGeneration();
void randomtestDataGeneration();

int main() {
    int nr_empl, nr_books;

    FILE *input_file = fopen("input_data.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    fscanf(input_file, "%d", &nr_empl);
    fscanf(input_file, "%d", &nr_books);

    int *books = (int *)malloc(nr_books * sizeof(int));
    for (int i = 0; i < nr_books; i++) {
        fscanf(input_file, "%d", &books[i]);
    }
    fclose(input_file);

    divideBooksAmongEmployees(books, nr_books, nr_empl);

    free(books);

    return 0;
}
