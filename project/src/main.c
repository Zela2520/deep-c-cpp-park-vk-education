#include "../include/task_info.h"

int main(int argc, char *argv[]) {
    ptr_task task_list;
    if (!(create_task_list(task_list))) {
        perror("Failed to create task list");
    }
//    sort_task_list();
//    print_task_list();
    delete_task_list(task_list);
    return 0;
}