#include "../../include/task_info.h"

ptr_task create_task(FILE* stream_input) {

    if (stream_input == NULL) {
        perror("create task error");
        return NULL;
    }

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

    if (create_string(task->description)) {
        perror("Memory allocation error");
        free(task->number);
        task = {};
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
        task = {};
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
        task = {};
        free(task);
        task = NULL;
        return NULL;
    }

    if (set_task(task, stream_input)) {
        perror("Set_task() error");

        if (delete_string(task->description)) {
            perror("delete string error. Create task function");
        }

        free(task->number);
        free(task->priority);
        free(task->when);
        task = {};
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
    task = NULL;
    return SUCCESS;
}


int create_string(char** string) {
    if (string != NULL) {
        if (delete_string(string)) {
            return ERROR;
        }
    }

    string = (char**)calloc(MAX_STR_SIZE, sizeof(char*));
    if (string == NULL) {
        perror("Memory allocation error in create_string function");
        return ERROR;
    }

    for (size_t i = 0; i < MAX_STR_SIZE; ++i) {
        if (string[i] != NULL) {
            free(string[i]);
        }

        string[i] = (char*)calloc(MAX_STR_SIZE, sizeof (char));
        if (string[i] == NULL) {
            perror("Memory allocation error in creating_string function");
            return ERROR;
        }
    }

    return SUCCESS;
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
    string = NULL;
    return SUCCESS;
}
