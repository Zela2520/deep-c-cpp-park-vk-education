#include "../include/task_info.h"

pointer_task_lists create_task_lists(pointer_task_lists current_task_lists) {
    current_task_lists = NULL;
    pointer_task_lists res_task_lists;
    size_t counter = 0;
    while (current_task_lists[counter] = create_task() != NULL) {
        res_task_lists = realloc(current_task_lists, sizeof(task_info));
        if (!(res_task_lists)) {
            perror("Memory allocation error");
            return NULL;
        }
        current_task_lists = res_task_lists;
        ++counter;
    }
    return current_task_lists;
}

void delete_task_lists(pointer_task_lists current_task_lists) {
    free(current_task_lists);
}

void propose_action() {
    printf("%s\n,%s\n,%s\n,%s\n",
           "Enter task number: ", "Enter a description of the task: ",
           "Enter task priority: ", "Enter task date: ");
}

// сделать проверку на размер вводимых данных
int set_task(pointer_task_lists current_task) {
    if (current_task == NULL) {
        return 1;
    }
    if (!(scanf("%zu", &task->number))) {
        perror("Input Error");
        return 1
    }
    if (!(scanf("%MAX_STR_SIZE", task->description))) {
        perror("Input Error")
        return 1;
    }
    if (!(scanf("%zu", &task->priority))) {
        perror("Input Error");
        return 1;
    }
    if (!(scanf("%lf", &task->when))) {
        perror("Input Error");
        return 1;
    }
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
        memset(task, 0, sizeof(*task));
        return NULL;
    }
    if (!(task->description = (char*)calloc(MAX_STR_SIZE + 1, sizeof(char)))) {
        perror("Memory allocation error");
        free(task->number);
        free(task);
        memset(task, 0, sizeof(*task));
        return NULL;
    }
    if (!(task->priority = (size_t*)calloc(1, sizeof(size_t)))) {
        perror("Memory allocation error");
        free(task->number);
        free(task->description);
        free(task);
        memset(task, 0, sizeof(*task));
        return NULL;
    }
    if (!(task->when = (double *)calloc(1, sizeof(double)))) {
        perror("Memory allocation error");
        free(task->number);
        free(task->description);
        free(task->priority);
        free(task);
        memset(task, 0, sizeof(*task));
        return NULL;
    }

    if (set_task(task) != 0) {
        perror("Task hasn't been set");
        free(task->number);
        free(task->description);
        free(task->priority);
        free(task->when);
        free(task);
        memset(task, 0, sizeof(*task));
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

void print_task_lists(const pointer_task_lists current_task_lists) {
    if (current_task_lists != NULL) {
        for (size_t i = 0; i < sizeof(*current_task_lists) / sizeof(task_info); ++i) {
            print_task(&current_task_lists[i]);
        }
    }
    perror("No such tasklist or tasklist hasn't been created");
}

//void delete_task(pointer_task_lists task) {
//    free(task);
//}

//void add_task(pointer_task_lists current_task) {
//
//}