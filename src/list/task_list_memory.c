#include "../../include/task_list.h"

list* create_list(const size_t str_len) {
    list* tasks = (list*) calloc(INCREMENT, sizeof(list)); // создаём спсиок задач

    if (tasks == NULL) {
        perror("Memory allocation error");
        return NULL;
    }
    puts("Allocate list"); // отладка

    tasks->size = str_len; // заполняем поле size
    tasks->insert_pos = INIT_INS_POS; // заполняем поле insert_pos
    tasks->capasity = 2 * tasks->size; // заполняем поле capasity

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

    cur_list->data = (ptr_task*)calloc(cur_list->capasity, sizeof(task_info*)); // выделяем память массив указателей задач

    if (cur_list->data == NULL) {
        perror("Memory allocation error");
        return ERROR;
    }
    puts("allocate list data"); // отладка

    return SUCCESS;
}

int delete_tasks(list* tasks) {
    if (tasks == NULL || tasks->data == NULL) {
        perror("delete_task_list() error");
        return ERROR;
    }

    for (size_t i = 0; i < tasks->capasity && tasks->data[i]; ++i) {
        if (delete_task(tasks->data[i])) {
            perror("attempt to free unallocated memory in delete tasks function");
        }
        printf("%zu %s\n", i, "delete data list element");
    }

    free(tasks->data);
    tasks->data = NULL;
    puts("delete list data"); // отладка
    return SUCCESS;
}

int free_list(list* tasks) {
    if (tasks == NULL) {
        perror("attempt to free unallocated memory");
        return ERROR;
    }

    if (tasks->data != NULL) {
        if (delete_tasks(tasks)) {
            free(tasks);
            tasks = NULL;
            return ERROR;
        }
    }

    free(tasks);
    tasks = NULL;
    puts("Delete list"); // отладка
    return SUCCESS;
}
