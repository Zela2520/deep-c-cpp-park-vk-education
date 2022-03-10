#include "../../include/task_info.h"

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