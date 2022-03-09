#include "../include/task_info.h"

int main(void) {
//    ptr_task task_list = NULL;
//    ptr_task user_task_list = create_task_list(task_list);
//    // sort_task_list();
//    if (user_task_list != NULL) {
//        print_task_list(user_task_list);
//    }
//    if (user_task_list != NULL) {
//        delete_task_list(user_task_list);
//        user_task_list = NULL;
//    }
   // ptr_task task_list = NULL;
    ptr_task user_task_list = (ptr_task)calloc(1, sizeof(task_info));

    if (add_task(user_task_list, create_task(), sizeof(*user_task_list) / sizeof(task_info))) {
        perror("add_task() error");
    }
    if (add_task(user_task_list, create_task(), sizeof(*user_task_list) / sizeof(task_info))) {
        perror("add_task() error");
    }

    if (user_task_list != NULL) {
        print_task_list(user_task_list);
    }

    if (user_task_list != NULL) {
        delete_task_list(user_task_list);
        user_task_list = NULL;
    }

    return 0;
}
