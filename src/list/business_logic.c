#include "../../include/task_list.h"

int business_logic(list* task_list, const char* path_file) {
    if (path_file == NULL && task_list == NULL) {
        perror("path to the file doesn't exist or list doesn't exist");
        return ERROR;
    }

    if (path_file == NULL) {
        free_list(task_list);
        perror("path to the file doesn't exist or list doesn't exist");
        return ERROR;
    }

    FILE* input_stream = fopen(path_file, "r");

    if (input_stream == NULL) {
        perror("file open error");
        free_list(task_list);
        return ERROR;
    }

    while (propose_action(input_stream) == SUCCESS) {

        ptr_task new_task = create_task();

        if (new_task == NULL) {
            free_list(task_list);

            fclose(input_stream);
            input_stream = NULL;
            return ERROR;
        }

        if ((set_task(new_task, input_stream))) {
            perror("Set_task() error");
            delete_task(new_task);

            free_list(task_list);
            task_list = NULL;

            fclose(input_stream);
            input_stream = NULL;
            return ERROR;
        }

        puts("task has been created");

        if (put_elem(task_list, new_task)) {
            perror("put elem error()");
            delete_task(new_task);

            free_list(task_list);
            task_list = NULL;

            fclose(input_stream);
            input_stream = NULL;

            return ERROR;
        }
    }

    fclose(input_stream);
    return SUCCESS;
}

int print_list(list* tasks) {
    if (tasks == NULL) {
        perror("print_task_list() error");
        return ERROR;
    }

    if (tasks->data == NULL) {
        free_list(tasks);
        tasks = NULL;
        perror("print_task_list() error");
        return ERROR;
    }

    for (size_t i = 0; i < tasks->insert_pos; ++i) {
        if (print_task(tasks->data[i])) {
            free_list(tasks);
            tasks = NULL;
            perror("print_list() error");
            return ERROR;
        }
        printf("%c", '\n');
    }
    return SUCCESS;
}
