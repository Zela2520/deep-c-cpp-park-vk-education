#ifndef PROJECT_MATRIX_H_
#define PROJECT_MATRIX_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MEDIUM_ROWS 1000
#define MEDIUM_COLS 500

#define BIG_ROWS 10000
#define BIG_COLS 5000


typedef struct Matrix {
    size_t rows;
    size_t columns;
    double* matrix;
} Matrix;

// Matrix initialization/creation and memory deallocation operations
Matrix* create_matrix_from_file(const char* path_file);
Matrix* create_matrix(size_t rows, size_t cols);
void free_matrix(Matrix* matrix);

double* calculate_sum_cols(Matrix* user_matrix);
int print_result(double* result);

#endif  // PROJECT_MATRIX_H_