#include "../../include/task_info.h"

ptr_task create_task() {
    ptr_task task = (task_info*)calloc(1, sizeof(task_info));
    if (task == NULL) {
        perror("Memory allocation error");
        return NULL;
    }

    if (!(task->number = (char*)calloc(MAX_STR_SIZE + 1, sizeof(char)))) {
        perror("Memory allocation error");
        free(task);
        memset(task, 0, sizeof(*task));
        return NULL;
    }
    if (!(task->description = (char**)calloc(MAX_STR_SIZE + 1, sizeof(char*)))) {
        perror("Memory allocation error");
        free(task->number);
        free(task);
        memset(task, 0, sizeof(*task));
        return NULL;
    }
    if (!(task->priority = (char*)calloc(MAX_STR_SIZE + 1, sizeof(char)))) {
        perror("Memory allocation error");
        free(task->number);
        free(task->description);
        free(task);
        memset(task, 0, sizeof(*task));
        return NULL;
    }
    if (!(task->when = (char*)calloc(MAX_STR_SIZE + 1, sizeof(char)))) {
        perror("Memory allocation error");
        free(task->number);
        free(task->description);
        free(task->priority);
        free(task);
        memset(task, 0, sizeof(*task));
        return NULL;
    }

    if (set_task(task)) {
        perror("Set_task() error");
        free(task->number);
        free(task->description);
        free(task->priority);
        free(task->when);
        free(task);
        memset(task, 0, sizeof(*task));
        return NULL;
    }

    return task;
}

int delete_task(ptr_task task) {
    if (task == NULL) {
        return ERROR;
    }
    if (task->number != NULL) {
        free(task->number);
        task->number = NULL;
    }
    if (task->description != NULL) {
        free(task->description);
        task->description = NULL;
    }
    if (task->priority != NULL) {
        free(task->priority);
        task->priority = NULL;
    }
    if (task->when != NULL) {
        free(task->when);
        task->when = NULL;
    }
    free(task);
    task = NULL;
    return SUCCESS;
}
