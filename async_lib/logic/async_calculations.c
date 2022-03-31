#include "../processes/processes.h"

double* async_calculate_sum_cols(Matrix* user_matrix) {
    if (user_matrix == NULL) {
        perror("calculate_sum_cols error");
        return NULL;
    }

    double* result = calloc(user_matrix->columns, sizeof(double));
    if (result == NULL) {
        perror("memory allocation error");
        return NULL;
    }

    for (size_t current_col = 0; current_col < user_matrix->columns; ++current_col) {
        for (size_t step = 0; step < (user_matrix->rows * user_matrix->columns); step += user_matrix->columns) {
            result[current_col] += user_matrix->matrix[current_col + step];
        }
    }

    return result;
}
