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
        task = NULL;
        return NULL;
    }

    if (!(task->description = create_string())) {
        perror("Memory allocation error");
        free(task->number);
        memset(task, 0, sizeof(task_info));
        free(task);
        task = NULL;
        return NULL;
    }

    if (!(task->priority = (char*)calloc(MAX_STR_SIZE + 1, sizeof(char)))) {
        perror("Memory allocation error");

        if (delete_string(task->description)) {
            perror("create task error. delete string error");
        }

        free(task->number);
        memset(task, 0, sizeof(task_info));
        free(task);
        task = NULL;
        return NULL;
    }

    if (!(task->when = (Data*)calloc(1, sizeof(Data)))) {
        perror("Memory allocation error");

        if (delete_string(task->description)) {
            perror("create task error. delete string error");
        }

        free(task->number);
        free(task->priority);
        memset(task, 0, sizeof(task_info));
        free(task);
        task = NULL;
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
        if (delete_string(task->description)) {
            perror("delete task error. delete string error");
        }
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
    return SUCCESS;
}


char** create_string() {

    char** string = (char**)calloc(MAX_STR_SIZE, sizeof(char*));
    if (string == NULL) {
        perror("Memory allocation error in create_string function");
        return NULL;
    }

    for (size_t i = 0; i < MAX_STR_SIZE; ++i) {
        if (string[i] != NULL) {
            free(string[i]);
            string[i] = NULL;
        }

        string[i] = (char*)calloc(MAX_STR_SIZE, sizeof (char));
        if (string[i] == NULL) {
            free(string);
            string = NULL;
            perror("Memory allocation error in creating_string function");
            return NULL;
        }
    }

    return string;
}

int delete_string(char** string) {
    if (string == NULL) {
        perror("deleted string error");
        return ERROR;
    }

    for (size_t i = 0; i < MAX_STR_SIZE; ++i) {
        if (string[i] != NULL) {
            free(string[i]);
            string[i] = NULL;
        }
    }

    free(string);
    return SUCCESS;
}
