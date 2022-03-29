#include "matrix.h"

int print_result(double* result, size_t len) {
    if (result == NULL) {
        perror("print result error");
        return ERROR;
    }

    for (size_t i = 0; i < len; ++i) {
        printf("%lf ", result[i]);
    }
    return SUCCESS;
}
