#include "../include/task_info.h"

// сделать проверку на размер вводимых данных
int set_task(ptr_task task) {
    if (task == NULL) {
        return -1;
    }

    printf("%s", "Enter task number: ");
    if (!(scanf("%zu", task->number))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        delete_task(task);
        perror("Input Error");
        return -1;
    }
    scanf( "%*[^\n]" ); // buffer was cleared
    printf("%zu\n", *task->number);

    printf("%s", "Enter task description: ");
    if (!(scanf("%1024s", task->description))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        delete_task(task);
        perror("Input Error");
        return -1;
    }
    scanf( "%*[^\n]" ); // buffer was cleared
    printf("%s\n", task->description);

    printf("%s", "Enter task priority: ");
    if (!(scanf("%zu", task->priority))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        delete_task(task);
        perror("Input Error");
        return -1;
    }
    scanf( "%*[^\n]" ); // buffer was cleared
    printf("%zu\n", *task->priority);

    printf("%s", "Enter task data: ");
    if (!(scanf("%lf", task->when))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        delete_task(task);
        perror("Input Error");
        return -1;
    }
    printf("%lf\n", *task->when);
    scanf( "%*[^\n]" ); // buffer was cleared
    return 0;
}

void print_task(const ptr_task task) {
    if (task != NULL) {
        // puts("Task exist"); // отладка
        if (task->number != NULL) {
            puts("task field exist"); // отладка
            printf("%zu\n", *task->number);
        }
        if (task->description != NULL) {
            puts("task field exist"); // отладка
            printf("%s\n", task->description);
        }
        if (task->priority != NULL) {
            puts("task field exist"); // отладка
            printf("%zu\n", *task->priority);
        }
        if (task->when != NULL) {
            puts("task field exist"); // отладка
            printf("%lf\n", *task->when);
        }
    } else {
        perror("Print_task() error");
    }
}
