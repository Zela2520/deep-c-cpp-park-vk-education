#include "../include/task_info.h"

ptr_task* create_task_list(ptr_task* task_list) {
    if (task_list != NULL) {
        free(task_list);
        task_list = NULL;
    }
    ptr_task* temp_task_list;
    while (propose_action() == SUCCESS) {
        temp_task_list = (ptr_task*)realloc(task_list, sizeof(task_info));
        if (!(temp_task_list)) {
            perror("Memory allocation error");
            return NULL;
        }
        printf("%s %zu\n", "size of list in bytes ", sizeof(**task_list));
        task_list = temp_task_list;
        if ((add_task(task_list, create_task(), sizeof(**task_list) / sizeof(task_info)))) {
            perror("creat_task_list() error");
            return NULL;
        }
    }
    return task_list;
}

int add_task(ptr_task* task_list, const ptr_task task, size_t tail) {
    if (task_list == NULL || task == NULL) {
        perror("Add_task() error");
        return ERROR;
    }
    printf("%zu index for insert\n", tail - 1);
    task_list[tail - 1] = task;
    return SUCCESS;
}

ptr_task* sort_task_list() {
    return NULL;
}

void print_task_list(const ptr_task* task_list) {
    if (task_list != NULL) {
        puts("print_task_list() out for"); // отладка
        for (size_t i = 0; i < sizeof(**task_list) / sizeof(task_info); ++i) {
            puts("print_task_list() in for"); // отладка
            print_task(task_list[i]);
        }
    } else {
        perror("print_task_list() error");
    }
}

void delete_task_list(ptr_task* task_list) {
    if (task_list == NULL) {
        perror("delete_task_list() error");
        return;
    }
    for (size_t i = 0; i < sizeof(**task_list) / sizeof(task_info); ++i) {
        printf("%s %zu %s", "element number ", i, "was deleted"); // отладка
        delete_task(task_list[i]);
    }
    free(task_list);
    task_list = NULL;
}
