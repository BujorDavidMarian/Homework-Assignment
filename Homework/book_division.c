#include "book_division.h"
#include <stdio.h>
#include <limits.h>

int isFeasible(int books[], int n, int k, int mid) {
    int requiredEmployees = 1;
    int currentLoad = 0;

    for (int i = 0; i < n; i++) {
        if (books[i] > mid) {
            return 0;
        }
        if (currentLoad + books[i] > mid) {
            requiredEmployees++;
            currentLoad = books[i];
            if (requiredEmployees > k) {
                return 0;
            }
        } else {
            currentLoad += books[i];
        }
    }
    return 1;
}

int findOptimalWorkload(int books[], int n, int k) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += books[i];
    }

    int left = 0;
    int right = sum;
    int result = INT_MAX;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (isFeasible(books, n, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

void divideBooksAmongEmployees(int books[], int nr_books, int nr_empls) {
    int optimalWorkload = findOptimalWorkload(books, nr_books, nr_empls);
    FILE *output_file = fopen("output_data.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return;
    }
    fprintf(output_file, "The optimal division of books to minimize the maximum workload is:\n");

    int currentLoad = 0;
    int currentEmployee = 1;
    int startIdx = 0;

    for (int i = 0; i < nr_books; i++) {
        if (currentLoad + books[i] > optimalWorkload) {
            fprintf(output_file, "Employee %d: %d pages ( ", currentEmployee, currentLoad);
            for (int j = startIdx; j < i; j++) {
                fprintf(output_file, "%d ", books[j]);
            }
            fprintf(output_file, ")\n");

            currentLoad = books[i];
            currentEmployee++;
            startIdx = i;
        } else {
            currentLoad += books[i];
        }

        if (i == nr_books - 1) {
            fprintf(output_file, "Employee %d: %d pages ( ", currentEmployee, currentLoad);
            for (int j = startIdx; j <= i; j++) {
                fprintf(output_file, "%d ", books[j]);
            }
            fprintf(output_file, ")\n");
        }
    }

    fprintf(output_file, "The optimal division of books to minimize the maximum workload is: %d pages\n", optimalWorkload);
    fclose(output_file);
}
