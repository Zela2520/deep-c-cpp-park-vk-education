#include "../../include/task_info.h"

int print_task(const ptr_task task) {
    if (task == NULL) {
        perror("Print_task() error");
        return ERROR;
    }

    if (task->number != NULL) {
        printf("%-1024s\n", task->number);
    }

    if (task->description != NULL) {
        print_description(task->description);
    }

    if (task->priority != NULL) {
        printf("%-1024s\n", task->priority);
    }

    if (task->when != NULL) {
        printf("%-1024s\n", task->when);
    }
    return SUCCESS;
}

int print_description(char** string) {
    if (string == NULL) {
        perror("print_description error");
        return ERROR;
    }

    for (size_t i = 0; i < MAX_STR_SIZE && string[i] != NULL; ++i) {
        for (size_t j = 0; string[i][j] != '\0'; ++j) {
            printf("%c", string[i][j]);
        }
    }

    return SUCCESS;
}


int set_task(ptr_task task, FILE* stream_input) {
    if (task == NULL || stream_input) {
        return ERROR;
    }

    size_t field = FIELDS_NAMES;

    while (field) {
        if (field == NUMBER) {
            if (get_number(stream_input, task->number)) {
                perror("get value error");
                return ERROR;
            }
        }

        if (field == DESCRIPTION) {
            if (get_description(stream_input, task->description)) {
                perror("get value error");
                return ERROR;
            }
        }

        if (field == PRIORITY) {
            if (get_priority(stream_input, task->priority)) {
                perror("get value error");
                return ERROR;
            }
        }

        if (field == WHEN) {
            if (get_data(stream_input,task->when)) {
                perror("get value error");
                return ERROR;
            }
        }
        --fields;
    }

    return 0;
}
