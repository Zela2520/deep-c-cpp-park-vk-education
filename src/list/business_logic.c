#include "../../include/task_list.h"

int business_logic(list* task_list, const char* path_file) {
    if (path_file == NULL) {
        perror("path to the file doesn't exist");
        return ERROR;
    }

//    FILE* input_stream = fopen(path_file, "r");
    FILE* input_stream = stdin;
    if (input_stream == NULL) {
        perror("file open error");
        return ERROR;
    }

    while (propose_action(input_stream) == SUCCESS) {

        ptr_task new_task = create_task(input_stream);
        if (new_task == NULL) {
            fclose(input_stream);
            return ERROR;
        }
        puts("task has been created");

        if (put_elem(task_list, new_task)) {
            if (delete_task(new_task)) {
                perror("memory free error");
                fclose(input_stream);
                return ERROR;
            }

            fclose(input_stream);
            return ERROR;
        }

    }

    fclose(input_stream);
    return SUCCESS;
}

int print_list(const list* tasks) {
    if (tasks == NULL || tasks->data == NULL) {
        perror("print_task_list() error");
        return ERROR;
    }

    for (size_t i = 0; i < tasks->size; ++i) {
        if (print_task(tasks->data[i])) {
            perror("print_list() error");
            return ERROR;
        }
        printf("%c", '\n');
    }
    return SUCCESS;
}
