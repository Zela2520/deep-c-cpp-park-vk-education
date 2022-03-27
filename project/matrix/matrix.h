#ifndef PROJECT_MATRIX_H_
#define PROJECT_MATRIX_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
    size_t rows;
    size_t columns;
    double* matrix;
} Matrix;

// Matrix initialization/creation and memory deallocation operations
Matrix* create_matrix_from_file(const char* path_file);
Matrix* create_matrix(size_t rows, size_t cols);
void free_matrix(Matrix* matrix);

double* print_result(double* result) {
    if (result == NULL) {
        perror("print result error");
        return NULL;
    }
}

#endif  // PROJECT_MATRIX_H_