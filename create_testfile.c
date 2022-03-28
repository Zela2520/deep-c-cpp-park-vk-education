#include "project/matrix/matrix.h"

#define INT_SIZE 2
#define DOUBLE_SIZE 8

static int fill_file(FILE* file_input, Matrix* cur_matrix) {
    int arg_count = 0;
    bool error_flag = 0;

    for (size_t current_row = 0; current_row < cur_matrix->rows; ++current_row) {
        for (size_t current_col = 0; current_col < cur_matrix->columns; ++current_col) {
            arg_count = fprintf(file_input, "%lf ",
                                cur_matrix->matrix[current_row * cur_matrix->columns + current_col]);
            if (arg_count != 1 * DOUBLE_SIZE) {
                printf("%d\n", arg_count);
                error_flag = 1;
                break;
            }
        }

        arg_count = fprintf(file_input, "%c", '\n');
        if (arg_count != 1) {
            error_flag = 1;
            break;
        }
    }

    fclose(file_input);

    if (error_flag) {
        free_matrix(cur_matrix);
        return -1;
    }

    return 0;
}


int main(void) {
     Matrix *cur_matrix = create_matrix(MEDIUM_ROWS, MEDIUM_COLS);
     if (cur_matrix == NULL) {
         perror("filling testfiles error");
         return -1;
     }

     FILE *file_input = fopen("tests/test_files/medium.txt", "wt");
     if (file_input == NULL) {
         free_matrix(cur_matrix);
         return -1;
     }

     int ret_val = fprintf(file_input, "%d ", MEDIUM_ROWS);
     if (ret_val != 2 * INT_SIZE) {
         printf("%d\n", ret_val);
         perror("writing error");
         free_matrix(cur_matrix);
         fclose(file_input);
         return -1;
     }

     ret_val = fprintf(file_input, "%d%c", MEDIUM_COLS, '\n');
     if (ret_val != 2 * INT_SIZE) {
         printf("%d\n", ret_val);
         perror("writing error");
         free_matrix(cur_matrix);
         fclose(file_input);
         return -1;
     }

     if (fill_file(file_input, cur_matrix)) {
         perror("file_file error");
         return -1;
     }


     free_matrix(cur_matrix);

     return 0;
}