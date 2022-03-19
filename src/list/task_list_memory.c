#include "../../include/task_list.h"

list* create_list(const size_t str_len) {
    list* tasks = (list*) calloc(INCREMENT, sizeof(list));
    if (tasks == NULL) {
        perror("Memory allocation error");
        return NULL;
    }
    tasks->size = str_len;
    tasks->insert_pos = INIT_INS_POS;
    tasks->capasity = 2 * tasks->size;

    if (create_list_data(tasks)) {
        puts("create_list function error");
        free(tasks);
        tasks = NULL;
        return NULL;
    }
    return tasks;
}

int create_list_data(list* cur_list) {
    if (cur_list == NULL) {
        perror("create list data error");
        return ERROR;
    }

    cur_list->data = (ptr_task*)calloc(cur_list->capasity, sizeof(task_info*));
    if (cur_list->data == NULL) {
        perror("Memory allocation error");
        free(cur_list);
        return ERROR;
    }

    for (size_t i = 0; i < cur_list->capasity; ++i) {
        cur_list->data[i] = (task_info*)calloc(INCREMENT, sizeof (task_info));

        if (cur_list->data[i] == NULL) {
            if (i == 0) {
                free(cur_list->data);
                cur_list->data = NULL;
                return ERROR;
            }
            while(i) {
                --i;
                free(cur_list->data[i]);
                cur_list->data[i] = NULL;
            }
            free(cur_list->data);
            cur_list->data = NULL;
            return ERROR;
        }
    }
    return SUCCESS;
}

int delete_tasks(list* tasks) {
    if (tasks == NULL || tasks->data == NULL) {
        perror("delete_task_list() error");
        return ERROR;
    }

    for (size_t i = 0; i < tasks->capasity; ++i) {
        if (delete_task(tasks->data[i])) {
            return ERROR;
        }
    }

    free(tasks->data);
    tasks->data = NULL;
    return SUCCESS;
}

int free_list(list* tasks) {
    if (tasks == NULL) {
        perror("attempt to free unallocated memory");
        return ERROR;
    }

    if (tasks->data != NULL) {
        if (delete_tasks(tasks)) {
            return ERROR;
        }
    }

    free(tasks);
    return SUCCESS;
}
