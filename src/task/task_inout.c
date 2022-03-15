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
            printf("%c", string[i][j]); // maybe there will be a memory leak
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
            puts("start get number function"); // отладка
            if (get_number(stream_input, task->number)) {
                perror("get value error");
                return ERROR;
            }
        }

        if (field == DESCRIPTION) {
            puts("start get description function"); // отладка
            if (get_description(stream_input, task->description)) { // непонятно когда description заканчивает свою работу
                perror("get value error");
                return ERROR;
            }
        }

        if (field == PRIORITY) {
            puts("start get priority function"); // отладка
            if (get_priority(stream_input, task->priority)) {
                perror("get value error");
                return ERROR;
            }
        }

        if (field == WHEN) {
            puts("start get data function"); // отладка
            if (get_data(stream_input,task->when)) {
                perror("get value error");
                return ERROR;
            }
        }
        --field;
    }

    return SUCCESS;
}
