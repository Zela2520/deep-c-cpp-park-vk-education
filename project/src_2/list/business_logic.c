#include "../../include/task_list.h"

int business_logic(list* task_list) {
    while (propose_action() == SUCCESS) {
        ptr_task new_task = create_task();
        if (new_task == NULL) {
            return ERROR;
        }
        if (put_elem(task_list, new_task)) {
            if (delete_task(new_task)) {
                perror("memory free error");
                return ERROR;
            }
            return ERROR;
        }
    }
    return SUCCESS;
}

int print_list(const list* tasks) {
    if (tasks == NULL || tasks->data == NULL) {
        perror("print_task_list() error");
        return ERROR;
    }
    puts("print_task_list() out for"); // отладка
    for (size_t i = 0; i < tasks->size; ++i) {
        puts("print_task_list() in for"); // отладка
        if (print_task(tasks->data[i])) {
            perror("print_list() error");
            return ERROR;
        }
    }
    return SUCCESS;
}
