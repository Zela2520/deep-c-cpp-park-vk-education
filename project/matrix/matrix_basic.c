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
