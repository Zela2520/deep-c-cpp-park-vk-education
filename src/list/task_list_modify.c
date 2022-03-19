#include "../../include/task_list.h"

static int increase_list(list* tasks, const size_t str_len) {
    if (tasks == NULL) {
        tasks = create_list(str_len);
        if (!(tasks)) {
            return ERROR;
        }
        return SUCCESS;
    }

    if (tasks->data == NULL) {
        if (create_list_data(tasks)) {
            perror("increase_list function error");
            return ERROR;
        }
    }

    tasks->size += str_len;

    if (tasks->capasity < tasks->size) {

        size_t prev_capasity = tasks->capasity;
        tasks->capasity = 2 * tasks->size;
        printf("%zu\n", tasks->capasity);
        ptr_task* new_data = (ptr_task*)realloc(tasks->data, tasks->capasity * sizeof(ptr_task));
        if (new_data == NULL) {
            perror("Memory allocation error");
            return ERROR;
        }

        for (size_t i = prev_capasity + 1; i < tasks->capasity; ++i) {
            new_data[i] = NULL;
        }

        tasks->data = new_data;
    }

    return SUCCESS;
}

int put_elem(list* cur_list, ptr_task task) {

    if (cur_list == NULL && task == NULL) {
        perror("put_elem method error");
        return ERROR;
    }

    if (cur_list == NULL && task != NULL) {
        delete_task(task);
        perror("put_elem method error");
        return ERROR;
    }

    if (cur_list != NULL && task == NULL) {
        free_list(cur_list);
        perror("put_elem method error");
        return ERROR;
    }

    if (cur_list->data == NULL) {
        if (create_list_data(cur_list)) {
            free_list(cur_list);
            cur_list = NULL;
            delete_task(task);
            task = NULL;
            perror("put_elem function error");
            return ERROR;
        }
    }

    if ((cur_list->size - cur_list->insert_pos == 1)) {
        if (increase_list(cur_list, INCREMENT)) {
            free_list(cur_list);
            cur_list = NULL;
            delete_task(task);
            task = NULL;
            puts("put_elem function error");
            return ERROR;
        }
    }
    cur_list->data[cur_list->insert_pos++] = task;
    return SUCCESS;
}

static int swap_task(ptr_task* left, ptr_task* right) {
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
    if (cur_list == NULL) {
        perror("sort list error cur_list = NULL");
        return NULL;
    }

    if (cur_list->data == NULL) {
        free(cur_list);
        cur_list = NULL;
        perror("sort list error cur_list = NULL");
        return NULL;
    }

    for (size_t i = 0; i + 1< cur_list->insert_pos; ++i) {
        for (size_t j = 0; j + 1 < cur_list->insert_pos - i; ++j) {

            if (cur_list->data[j + 1] == NULL || cur_list->data[j] == NULL) {
                free(cur_list);
                cur_list = NULL;
                perror("sort list error. null pointer");
                return NULL;
            }

            if (atoi(cur_list->data[j + 1]->priority) > atoi(cur_list->data[j]->priority)) {
                if (swap_task(&cur_list->data[j + 1], &cur_list->data[j])) {
                    free(cur_list);
                    cur_list = NULL;
                    perror("swap error");
                    return NULL;
                }
            }

            else if (atoi(cur_list->data[j + 1]->priority) == atoi(cur_list->data[j]->priority)) {
                if (cur_list->data[j + 1]->when->year < cur_list->data[j]->when->year) {

                    if (swap_task(&cur_list->data[j + 1], &cur_list->data[j])) {
                        free(cur_list);
                        cur_list = NULL;
                        perror("swap error");
                        return NULL;
                    }
                }

                else if (cur_list->data[j + 1]->when->year == cur_list->data[j]->when->year &&
                    cur_list->data[j + 1]->when->month < cur_list->data[j]->when->month) {

                    if (swap_task(&cur_list->data[j + 1], &cur_list->data[j])) {
                        free(cur_list);
                        cur_list = NULL;
                        perror("swap error");
                        return NULL;
                    }
                }

                else if (cur_list->data[j + 1]->when->year == cur_list->data[j]->when->year &&
                    cur_list->data[j + 1]->when->month == cur_list->data[j]->when->month &&
                    cur_list->data[j + 1]->when->number < cur_list->data[j]->when->number) {

                    if (swap_task(&cur_list->data[j + 1], &cur_list->data[j])) {
                        free(cur_list);
                        cur_list = NULL;
                        perror("swap error");
                        return NULL;
                    }
                }
            }
        }
    }
    return cur_list;
}
