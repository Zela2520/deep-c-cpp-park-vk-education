#include "../../include/task_list.h"

int business_logic(list* task_list, const char* path_file) {
    FILE* input_stream = fopen(path_file, "r");
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

        if (put_elem(task_list, new_task)) {
            if (delete_task(new_task)) {
                perror("memory free error");
                fclose(input_stream);
                return ERROR;
            }

            fclose(fptr);
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

//    puts("print_task_list() out for"); // отладка
    for (size_t i = 0; i < tasks->size; ++i) {
        printf("%s %zu\n", "Task priority:", i);
        if (print_task(tasks->data[i])) {
            perror("print_list() error");
            return ERROR;
        }
    }
    return SUCCESS;
}
