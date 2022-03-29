#include "business_logic.h"

int business_logic() {
    Matrix* user_matrix = create_matrix_from_file("tests/test_files/normal.txt");
    if (user_matrix == NULL) {
        perror("create matrix error");
        return ERROR;
    }

    double* result = calculate_sum_cols(user_matrix);
    if (result == NULL) {
        perror("Failed to calculate the sum of the matrix elements");
        return ERROR;
    }

    if (print_result(result, user_matrix->columns)) {
        perror("matrix printing error");
        return ERROR;
    }

    free(result);

    return SUCCESS;
}