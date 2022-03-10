#include "../../include/task_list.h"

list* create_list(const size_t str_len) {
    list* tasks = (list*) calloc(INCREMENT, sizeof(list));
    if (tasks == NULL) {
        perror("Memory allocation error");
        return NULL;
    }
    tasks->size = str_len;
    tasks->insert_pos = INIT_INS_POS;
    tasks->capasity = 2 * str_len;
    if (create_list_data(tasks)) {
        puts("create_list function error");
        return NULL;
    }
    return tasks;
}

int create_list_data(list* cur_list) {
    cur_list->data = (ptr_task*)calloc(cur_list->capasity, sizeof(task_info*));
    if (cur_list->data == NULL) {
        perror("Memory allocation error");
        return ERROR;
    }
    for (size_t i = 0; i < cur_list->size; ++i) {
        cur_list->data[i] = (task_info*)calloc(INCREMENT, sizeof (task_info));
        if (cur_list->data[i] == NULL) {
            perror("Memory allocation error");
            return ERROR;
        }
    }
    for (size_t i = cur_list->size; i < cur_list->capasity; ++i) {
        memset(&cur_list->data[i], 0, sizeof(cur_list->data[i]));
    }
    return SUCCESS;
}

int put_elem(list* cur_list, task_info* task) {
    if (cur_list == NULL || task == NULL) {
        perror("put_elem method error");
        return ERROR;
    }
    if (cur_list->data == NULL) {
        if (create_list_data(cur_list)) {
            puts("put_elem function error");
            return ERROR;
        }
    }
    if (cur_list->size - cur_list->insert_pos == INCREMENT) {
        if (increase_list(cur_list, INCREMENT)) {
            puts("put_elem function error");
            return ERROR;
        }
    }
    cur_list->data[cur_list++] = task;
    return SUCCESS;
}

int increase_list(list* tasks, const size_t str_len) {
    if (tasks == NULL) {
        tasks = create_list(DEFAULT_SIZE);
        if (!(tasks)) {
            return ERROR;
        }
        return SUCCESS;
    }
    tasks->size += str_len;
    if (tasks->capasity < tasks->size) {
        tasks->capasity = 2 * tasks->size;
        list* new_tasks = create_list(tasks->capasity);
        if (new_tasks == NULL) {
            perror("Memory allocation error");
            return ERROR;
        }
        tasks->data = new_tasks->data;
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
