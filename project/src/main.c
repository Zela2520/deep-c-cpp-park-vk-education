#include "../include/task_info.h"

int main(void) {
    ptr_task task_list = NULL;
    ptr_task user_task_list = create_task_list(task_list);
    // sort_task_list();
    print_task_list(user_task_list); // сег фолт если че
    delete_task_list(user_task_list);
    return 0;
}
