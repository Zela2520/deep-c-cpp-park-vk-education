#include "../../include/task_info.h"

ptr_task create_task() {
    ptr_task task = (task_info*)calloc(1, sizeof(task_info));
    if (task == NULL) {
        perror("Memory allocation error");
        return NULL;
    }

    if (!(task->number = (size_t*)calloc(1, sizeof(size_t)))) {
        perror("Memory allocation error");
        free(task);
        memset(task, 0, sizeof(*task));
        return NULL;
    }
    if (!(task->description = (char*)calloc(MAX_STR_SIZE + 1, sizeof(char)))) {
        perror("Memory allocation error");
        free(task->number);
        free(task);
        memset(task, 0, sizeof(*task));
        return NULL;
    }
    if (!(task->priority = (size_t*)calloc(1, sizeof(size_t)))) {
        perror("Memory allocation error");
        free(task->number);
        free(task->description);
        free(task);
        memset(task, 0, sizeof(*task));
        return NULL;
    }
    if (!(task->when = (double *)calloc(1, sizeof(double)))) {
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
    if (task != NULL && task->number != NULL) {
        free(task->number);
        task->number = NULL;
        return SUCCESS;
    }
    if (task != NULL && task->description != NULL) {
        free(task->description);
        task->description = NULL;
        return SUCCESS;
    }
    if (task != NULL && task->priority != NULL) {
        free(task->priority);
        task->priority = NULL;
        return SUCCESS;
    }
    if (task != NULL && task->when != NULL) {
        free(task->when);
        task->when = NULL;
        return SUCCESS;
    }
    if (task != NULL) {
        free(task);
        task = NULL;
        return SUCCESS;
    }
    return ERROR;
}
