#include "matrix.h"

int set_elem(Matrix* matrix, size_t row, size_t col, double val) {
    if (matrix == NULL || matrix->matrix == NULL) {
        return 1;
    }

    if (row >= matrix->rows || col >= matrix->columns) {
        return 1;
    }

    matrix->matrix[row * matrix->columns + col] = val;
    return 0;
}

double* set_random_values(Matrix* user_matrix) {
    if (user_matrix == NULL || user_matrix->matrix == NULL) {
        perror("set_random_values");
        return NULL;
    }

    srand(time(NULL));

    bool error_flag = 0;
    for (size_t current_row = 0; current_row < user_matrix->rows; ++current_row) {
        for (size_t current_col = 0; current_col < user_matrix->columns; ++current_col) {
            if (set_elem(user_matrix, current_row, current_col, rand() % 10 + 1)) {
                perror("set_random_values set elem");
                error_flag = 1;
            };
        }
    }

    if (error_flag) {
        return NULL;
    }

    return user_matrix->matrix;
}
