#include "../include/task_info.h"

int main() {
    propose_action();
    pointer_task_lists task_lists;
    create_task_lists(task_lists);

    delete_task_lists(task_lists);
    return 0;
}