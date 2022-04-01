#include "../processes/processes.h"

double* async_calculate_sum_cols(Matrix* user_matrix) {
    if (user_matrix == NULL) {
        perror("calculate_sum_cols error");
        return NULL;
    }

    int max_num_workers = sysconf(_SC_NPROCESSORS_ONLN) - 1;

//    int numbers_processing_cols;
//    if (user_matrix->columns % max_num_workers) {
//        numbers_processing_cols = (user_matrix->columns + ) / max_num_workers;
//    }

    int numbers_processing_cols = user_matrix->columns / max_num_workers;

    double* result = mmap(NULL, max_num_workers * sizeof(double), PROT_READ | PROT_WRITE,
                          MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    if (result == NULL) {
        perror("memory allocation error");
        return NULL;
    }

    pid_t pid = -1;
    size_t workers_id = 1;

    for (size_t current_col = 0; current_col < user_matrix->columns; ++current_col) {

        if (numbers_processing_cols * workers_id == current_col) {
            pid = fork();
            ++workers_id;
        }

        if (pid == 0) {
            for (size_t step = 0; step < (user_matrix->rows * user_matrix->columns); step += user_matrix->columns) {
                result[current_col] += user_matrix->matrix[current_col + step];
                exit(3);
            }
        }

    }

    int status;
    bool error_flag = false;
    for (size_t i = 0; i < workers_id; ++i) {
        waitpid(0, &status, 0);
        if (!(WIFEXITED(status))) {
            perror("child is broken");
            error_flag = true;
        }
    }

    if (error_flag) {
        perror("async_calculate_sum_cols error");
        return NULL;
    }

    return result;
}
