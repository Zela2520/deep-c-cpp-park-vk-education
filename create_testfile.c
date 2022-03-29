#include "project/matrix/matrix.h"

static int fill_file(FILE* file_input, Matrix* cur_matrix) {

    int arg_count = 0;
    bool error_flag = 0;

    if (!(set_random_values(cur_matrix))) {
        return ERROR;
    }

    for (size_t current_row = 0; current_row < cur_matrix->rows; ++current_row) {
        for (size_t current_col = 0; current_col < cur_matrix->columns; ++current_col) {

            arg_count = fprintf(file_input, "%lf",
                                cur_matrix->matrix[current_row * cur_matrix->columns + current_col]);

            if (current_col + 1 != cur_matrix->columns) {
                fprintf(file_input, "%c", ' ');
            }

//            if (arg_count != DOUBLE_SIZE) {
//                printf("%d\n", arg_count);
//                perror("third writting error");
//                error_flag = 1;
//                break;
//            }
        }

        if (current_row + 1 != cur_matrix->rows) {

            arg_count = fprintf(file_input, "%c", '\n');
            if (arg_count != 1) {
                error_flag = 1;
                break;
            }
        }
    }

    fclose(file_input);

    if (error_flag) {
        free_matrix(cur_matrix);
        return ERROR;
    }

    return SUCCESS;
}


int main(int argc, char *argv[]) {

    if (argc != 2) {
        perror("not enough arguments for main");
        return -1;
    }

    Matrix *cur_matrix = create_matrix(3, 6); // создали матрицу с нулями
    if (cur_matrix == NULL) {
        perror("filling testfiles error");
        return ERROR;
    }

    FILE *file_input = fopen(argv[1], "wt"); // открыли файл
    if (file_input == NULL) {
        free_matrix(cur_matrix);
        return ERROR;
    }

    // заполнили стркоу отвечающую за поля rows и cols в файле
    int ret_val = fprintf(file_input, "%d ", 3); // так удобнее отлаживать
    if (ret_val != 1 + 1) {
        printf("%d\n", ret_val);
        perror("first writing error");
        free_matrix(cur_matrix);
        fclose(file_input);
        return ERROR;
    }

    ret_val = fprintf(file_input, "%d\n", 6);
    if (ret_val != (1 + 1)) {
        printf("%d\n", ret_val);
        perror("second writing error");
        free_matrix(cur_matrix);
        fclose(file_input);
        return ERROR;
    }

    // заполнили файл нулями содержащимися в матрице
    if (fill_file(file_input, cur_matrix)) {
        perror("file_file error");
        return ERROR;
    }

    free_matrix(cur_matrix);

    return SUCCESS;
}
