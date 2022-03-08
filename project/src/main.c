#include "../include/task_info.h"

int main(int argc, char *argv[]) {
    propose_action();
    pointer_task_lists task_lists;
    if (create_task_lists(task_lists) == NULL) {
        perror("Failed to create task list");
    }

    delete_task_lists(task_lists);
    return 0;
}