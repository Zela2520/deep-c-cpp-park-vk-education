#include "../include/task_info.h"

ptr_task create_task_list(ptr_task task_list) {
    if (task_list != NULL) {
        free(task_list);
        task_list = NULL;
    }
    ptr_task temp_task_list;
    while (propose_action() == SUCCESS) {
        if (!(add_task(task_list, create_task(), sizeof(*task_list) / sizeof(task_info)))) {
            perror("task hasn't been created");
            return NULL;
        }
        temp_task_list = (ptr_task)realloc(task_list, sizeof(task_info));
        if (!(temp_task_list)) {
            perror("Memory allocation error");
            return NULL;
        }
        task_list = temp_task_list;
    }
    return task_list;
}

ptr_task sort_task_list() {
    return NULL;
}

void print_task_list(const ptr_task task_list) {
    if (task_list != NULL) {
        for (size_t i = 0; i < sizeof(*task_list) / sizeof(task_info); ++i) {
            print_task(&task_list[i]);
        }
    }
    perror("No such tasklist or tasklist hasn't been created");
}

void delete_task_list(ptr_task task_list) {
    if (task_list == NULL) {
        perror("No such tasklist or tasklist hasn't been created");
        return;
    }
    for (size_t i = 0; i < sizeof(*task_list) / sizeof(task_info); ++i) {
        delete_task(&task_list[i]);
    }
    task_list = NULL;
}
