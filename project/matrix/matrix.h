#ifndef PROJECT_MATRIX_MATRIX_H_
#define PROJECT_MATRIX_MATRIX_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MEDIUM_ROWS 1000
#define MEDIUM_COLS 500

#define BIG_ROWS 10000
#define BIG_COLS 5000

#define MEDIUM_ROWS_SIZE 4
#define MEDIUM_COLS_SIZE 3
#define BIG_ROWS_SIZE 5
#define BIG_COLS_SIZE 4
#define DOUBLE_SIZE 8

#define ERROR -1
#define SUCCESS 0


typedef struct Matrix {
    size_t rows;
    size_t columns;
    double* matrix;
} Matrix;

// Matrix initialization/creation and memory deallocation operations
Matrix* create_matrix_from_file(const char* path_file);
Matrix* create_matrix(size_t rows, size_t cols);
void free_matrix(Matrix* matrix);

// Basic operations
int set_elem(Matrix* matrix, size_t row, size_t col, double val);

// Calculation
double* calculate_sum_cols(Matrix* user_matrix);

// Input/output
int print_result(double* result);

#endif  // PROJECT_MATRIX_MATRIX_H_