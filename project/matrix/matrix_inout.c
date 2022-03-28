#include "matrix.h"

int print_result(double* result) {
    if (result == NULL) {
        perror("print result error");
        return -1;
    }

    for (size_t i = 0; &result[i] != NULL; ++i) {
        printf("%lf ", result[i]);
    }
    return 0;
}
