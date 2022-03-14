#include "../../include/task_list.h"

int put_elem(list* cur_list, const ptr_task task) {
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

    if (!(cur_list->size - cur_list->insert_pos)) {
        if (increase_list(cur_list, INCREMENT)) {
            puts("put_elem function error");
            return ERROR;
        }
    }
    cur_list->data[cur_list->insert_pos++] = task;
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
        ptr_task* new_data = (ptr_task*)realloc(tasks->data, tasks->capasity*sizeof(ptr_task)); // create_list_data
        if (new_data == NULL) {
            perror("Memory allocation error");
            return ERROR;
        }

        for (size_t i = tasks->size - str_len; i < tasks->capasity; ++i) {
            memset(&tasks->data[i], 0, sizeof(tasks->data[i]));
        }
        tasks->data = new_data;
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

    for (size_t i = 0; i < num; ++i) {
        if (left->data[begin_copy + i] == NULL || right->data[i] == NULL) {
            return ERROR;
        }

        if (delete_task(left->data[begin_copy + i])) {
            perror("copy list error");
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

static void swap_task(ptr_task left, ptr_task right) {
    ptr_task temp = left;
    left = right;
    right = temp;
}

list* sort_list(list* cur_list) {
    for (size_t i = 0; i  + 1 < cur_list->size; ++i) {
        for (size_t j = 0; j + 1 < cur_list->size - i; ++i) {
            if (atoi(cur_list->data[j + 1]->priority) > atoi(cur_list->data[j]->priority)) {
                swap_task(cur_list->data[j + 1], cur_list->data[j]);
            }

            if (atoi(cur_list->data[j + 1]->priority) == atoi(cur_list->data[j]->priority)) {
                if (cur_list->data[j + 1]->when->year < cur_list->data[j]->when->year) {
                    swap_task(cur_list->data[j + 1], cur_list->data[j]);
                }

                if (cur_list->data[j + 1]->when->year == cur_list->data[j]->when->year &&
                    cur_list->data[j + 1]->when->month < cur_list->data[j]->when->month) {
                    swap_task(cur_list->data[j + 1], cur_list->data[j]);
                }

                if (cur_list->data[j + 1]->when->year == cur_list->data[j]->when->year &&
                    cur_list->data[j + 1]->when->month == cur_list->data[j]->when->month &&
                    cur_list->data[j + 1]->when->number < cur_list->data[j]->when->number) {
                    swap_task(cur_list->data[j + 1], cur_list->data[j]);
                }
            }
        }
    }
    return cur_list;
}
