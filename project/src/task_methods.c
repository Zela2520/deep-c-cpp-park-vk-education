#include "../include/task_info.h"

void create_task_lists(pointer_task_lists current_task_lists) {
    current_task_lists = calloc(1, sizeof(task_info));
    while (create_task() != NULL) {
        ;
    }
}

void delete_task_lists(pointer_task_lists current_task_lists) {
    free(current_task_lists);
}

void propose_action() {
    printf("%s\n,%s\n,%s\n,%s\n",
           "Enter task number: ", "Enter a description of the task: ",
           "Enter task priority: ", "Enter task date: ");
}

int set_task(pointer_task_lists current_task) {
    if (current_task == NULL) {
        return 1;
    }
    scanf("%" PR_SIZET "u", &task->number);
    scanf("%s", task->description);
    scanf("%" PR_SIZET "u", &task->priority);
    scanf("%lf", &task->when);
    return 0;
}

pointer_task_lists create_task() {
    pointer_task_lists task = (task_info*)calloc(1, sizeof(task_info));
    if (task == NULL) {
        perror("Memory allocation error");
        return NULL;
    }

    if (!(task->number = (size_t*)calloc(1, sizeof(size_t)))) {
        perror("Memory allocation error");
        free(task);
        return NULL;
    }
    if (!(task->description = (char*)calloc(MAX_STR_SIZE + 1, sizeof(char)))) {
        perror("Memory allocation error");
        free(task);
        task = NULL;
        return NULL;
    }
    if (!(task->priority = (size_t*)calloc(1, sizeof(size_t)))) {
        perror("Memory allocation error");
        free(task);
        return NULL;
    }
    if (!(task->when = (double *)calloc(1, sizeof(double)))) {
        perror("Memory allocation error");
        free(task);
        return NULL;
    }

    if (set_task(task) == 1) {
        free(task);
        return NULL;
    }

    return task;
}

void print_task(const pointer_task_lists current_task) {
    if (current_task != NULL) {
        printf("%" PR_SIZET "u", &task->number);
        printf("%s", task->description);
        printf("%" PR_SIZET "u", &task->priority);
        printf("%lf", &task->when);
    }
    perror("No such task or task hasn't been created");
}

void delete_task(pointer_task_lists task) {
    free(task);
}

//void add_task(pointer_task_lists current_task) {
//
//}