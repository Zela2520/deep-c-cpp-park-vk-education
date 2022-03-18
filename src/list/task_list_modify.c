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

    if ((cur_list->size - cur_list->insert_pos == 1)) {
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
        ptr_task* new_data = (ptr_task*)realloc(tasks->data, tasks->capasity * sizeof(ptr_task));
        if (new_data == NULL) {
            if (tasks->data) {
                perror("Memory allocation error");
                return ERROR;
            }
            perror("Memory allocation error");
            return ERROR;
        }

        for (size_t i = tasks->size; i < tasks->capasity; ++i) {
            memset(&tasks->data[i], 0, sizeof(tasks->data[i]));
        }

        if (delete_tasks(tasks)) {
            perror("increase list error");
            return ERROR;
        }

        tasks->data = new_data;
    }

    return SUCCESS;
}

int swap_task(ptr_task* left, ptr_task* right) {
    if (right == NULL || left == NULL) {
        perror("swap error");
        return ERROR;
    }
    ptr_task temp = *left;
    *left = *right;
    *right = temp;
    return SUCCESS;
}

list* sort_list(list* cur_list) {
    if (cur_list == NULL || cur_list->data == NULL) {
        perror("sort list error cur_list = NULL");
        return NULL;
    }

    for (size_t i = 0; i + 1< cur_list->insert_pos; ++i) {
        for (size_t j = 0; j + 1 < cur_list->insert_pos - i; ++j) {

            if (cur_list->data[j + 1] == NULL || cur_list->data[j] == NULL) {
                perror("sort list error. null pointer");
                return NULL;
            }

            if (atoi(cur_list->data[j + 1]->priority) > atoi(cur_list->data[j]->priority)) {
                if (swap_task(&cur_list->data[j + 1], &cur_list->data[j])) {
                    perror("swap error");
                    return NULL;
                }
            }

            else if (atoi(cur_list->data[j + 1]->priority) == atoi(cur_list->data[j]->priority)) {
                if (cur_list->data[j + 1]->when->year < cur_list->data[j]->when->year) {

                    if (swap_task(&cur_list->data[j + 1], &cur_list->data[j])) {
                        perror("swap error");
                        return NULL;
                    }
                }

                else if (cur_list->data[j + 1]->when->year == cur_list->data[j]->when->year &&
                    cur_list->data[j + 1]->when->month < cur_list->data[j]->when->month) {

                    if (swap_task(&cur_list->data[j + 1], &cur_list->data[j])) {
                        perror("swap error");
                        return NULL;
                    }
                }

                else if (cur_list->data[j + 1]->when->year == cur_list->data[j]->when->year &&
                    cur_list->data[j + 1]->when->month == cur_list->data[j]->when->month &&
                    cur_list->data[j + 1]->when->number < cur_list->data[j]->when->number) {

                    if (swap_task(&cur_list->data[j + 1], &cur_list->data[j])) {
                        perror("swap error");
                        return NULL;
                    }
                }
            }
        }
    }
    return cur_list;
}
