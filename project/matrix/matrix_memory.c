#include "matrix.h"

// Matrix initialization/creation and memory deallocation operations
Matrix* create_matrix_from_file(const char* path_file) {
    FILE* matrix_input;
    matrix_input = fopen(path_file, "r");

    if (matrix_input == NULL) {
        return NULL;
    }
    size_t cols = 0;
    size_t rows = 0;
    int arg_count = fscanf(matrix_input, "%zu", &rows);

    if (arg_count != 1) {
        fclose(matrix_input);
        return NULL;
    }
    arg_count = fscanf(matrix_input, "%zu", &cols);

    if (arg_count != 1) {
        fclose(matrix_input);
        return NULL;
    }
    bool error_flag = 0;
    Matrix* ret = create_matrix(rows, cols);

    for (size_t current_row = 0; current_row < rows; ++current_row) {
        for (size_t current_col = 0; current_col < cols; ++current_col) {
            arg_count = fscanf(matrix_input, "%lf", &ret->matrix[current_row * cols + current_col]);
            if (arg_count != 1) {
                error_flag = 1;
                break;
            }
        }
    }
    fclose(matrix_input);

    if (error_flag) {
        free_matrix(ret);
        return NULL;
    }

    return ret;
}

Matrix* create_matrix(size_t rows, size_t cols) {
    Matrix* ret = (Matrix*) calloc(1, sizeof(Matrix));
    if (ret == NULL) {
        free_matrix(ret);
        return NULL;
    }
    ret->matrix = (double*) calloc(rows * cols, sizeof(double));

    if (ret->matrix == NULL) {
        free_matrix(ret);
        return NULL;
    }

    ret->rows = rows;
    ret->columns = cols;
    return ret;
}

void free_matrix(Matrix* matrix) {
    if (matrix == NULL) {
        return;
    }

    if (matrix->matrix != NULL) {
        free(matrix->matrix);
    }

    free(matrix);
}
