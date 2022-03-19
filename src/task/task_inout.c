#include "../../include/task_info.h"

int print_task(const ptr_task task) {
    if (task == NULL) {
        perror("Print_task() error");
        return ERROR;
    }

    if (task->number != NULL) {
        printf("%s\n", task->number);
    }

    if (task->description != NULL) {
        print_description(task->description);
    }

    if (task->priority != NULL) {
        printf("%s\n", task->priority);
    }

    if (task->when != NULL) {
        printf("%d.", task->when->number);
        printf("%d.", task->when->month);
        printf("%d\n", task->when->year);
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

        if (strlen(string[i])) {
            printf("\n");
        }
    }

    return SUCCESS;
}


int set_task(ptr_task task, FILE* stream_input) {
    if (task == NULL || stream_input == NULL) {
        perror("task = NULL");
        return ERROR;
    }

    size_t field = FIELDS_NAMES;

    while (field) {

        if (field == NUMBER) {
            printf("Enter the task number: ");
            if (get_number(stream_input, task->number)) {
                perror("get value error");
                return ERROR;
            }
        }

        if (field == DESCRIPTION) {
            printf("Enter the task description: ");
            if (get_description(stream_input, task->description)) {
                perror("get value error");
                return ERROR;
            }
        }

        if (field == PRIORITY) {
            printf("Enter the task priority ");
            if (get_priority(stream_input, task->priority)) {
                perror("get value error");
                return ERROR;
            }
        }

        if (field == WHEN) {
            printf("Enter the task data: ");
            if (get_data(stream_input,task->when)) {
                perror("get value error");
                return ERROR;
            }
        }
        --field;
    }

    return SUCCESS;
}
