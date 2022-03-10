#include "../include/task_list.h"

#define DEFAULT_SIZE 5

list* create_list(const size_t str_len) {
    list* tasks = (list*) calloc(1, sizeof(list));
    if (tasks == NULL) {
        perror("Memory allocation error");
        return NULL;
    }
    tasks->size = str_len;
    tasks->capasity = 2 * str_len;
    tasks->data = (ptr_task)calloc(tasks->capasity, sizeof(task_info));
    if (tasks->data == NULL) {
        perror("Memory allocation error");
        return NULL;
    }
    return tasks;
}

int increase_list(list* tasks, const size_t str_len) {
    if (tasks == NULL) {
        tasks = create_list(DEFAULT_SIZE);
        return SUCCESS;
    }
    tasks->size += str_len;
    if (tasks->capasity < tasks->size) {
        tasks->capasity = 2 * tasks->size;
        ptr_task new_tasks = (ptr_task)realloc(tasks->data, tasks->capasity);
        if (new_tasks == NULL) {
            perror("Memory allocation error");
            return ERROR;
        }
        for (size_t i = tasks->size - str_len; i < tasks->capasity; ++i) {
            new_tasks[i] = {0};
        }
        tasks->data = new_tasks;
    }
    return SUCCESS;
}

int copy_list(list* left, const list* right, size_t num, size_t begin_copy) {
    if (left == NULL || right == NULL) {
        return ERROR;
    }
    if (right->size < num) {
        return ERROR;
    }
    if (left->size <= num + begin_copy) {
        if (increase_list(left, begin_copy + num)) {
            return ERROR;
        }
    }
    for (size_t i = 0, j = 0; i < num; ++i) {
        if (right->data[i] != NULL) {
            left->data[j + begin_copy] = right->data[i];
            ++j;
        }
    }
    return SUCCESS;
}

int free_list(list* tasks) {
    if (tasks == NULL || tasks->data == NULL) {
        perror("attempt to free unallocated memory");
        return ERROR;
    }
    free(tasks->data);
    tasks->data = NULL;
    free(tasks);
    tasks = NULL;
    return SUCCESS;
}