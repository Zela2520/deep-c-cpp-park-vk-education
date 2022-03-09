#include "../include/task_info.h"

ptr_task create_task() {
    ptr_task task = (task_info*)calloc(1, sizeof(task_info));
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

    if (set_task(task)) {
        perror("Set_task() error");
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

    printf("%s", "Enter task description: ");
    if (!(scanf("%1024s", task->description))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        delete_task(task);
        perror("Input Error");
        return -1;
    }
    scanf( "%*[^\n]" ); // buffer was cleared

    printf("%s", "Enter task priority: ");
    if (!(scanf("%zu", task->priority))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        delete_task(task);
        perror("Input Error");
        return -1;
    }
    scanf( "%*[^\n]" ); // buffer was cleared

    printf("%s", "Enter task data: ");
    if (!(scanf("%lf", task->when))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        delete_task(task);
        perror("Input Error");
        return -1;
    }
    scanf( "%*[^\n]" ); // buffer was cleared
    return 0;
}

int add_task(ptr_task task_list, const ptr_task task, size_t size) {
    if (task_list == NULL || task == NULL) {
        perror("Add_task() error");
        return ERROR;
    }
    task_list[size] = *task;
    return SUCCESS;
}

void print_task(const ptr_task task) {
    if (task != NULL) {
        if (task->number != NULL) {
            printf("%zu\n", *task->number);
        }
        if (task->description != NULL) {
            printf("%s\n", task->description);
        }
        if (task->priority != NULL) {
            printf("%zu\n", *task->priority);
        }
        if (task->when != NULL) {
            printf("%lf\n", *task->when);
        }
    } else {
        perror("Print_task() error");
    }
}

void delete_task(ptr_task task) {
    if (task != NULL && task->number != NULL) {
        free(task->number);
        task->number = NULL;
    }
    if (task != NULL && task->description != NULL) {
        free(task->description);
        task->description = NULL;
    }
    if (task != NULL && task->priority != NULL) {
        free(task->priority);
        task->priority = NULL;
    }
    if (task != NULL && task->when != NULL) {
        free(task->when);
        task->when = NULL;
    }
    if (task != NULL) {
        free(task);
        task = NULL;
    }
}

int propose_action() {
    char *choice = (char *) calloc(10, sizeof(char));

    do {
        if (printf("%-42s", "Would you like to add a new task? Yes/No:") < 0) {
            perror("Data entry error");
            return ERROR;
        }

        if (!(scanf("%5s", choice))) {
            perror("Data entry error");
            scanf( "%*[^\n]" ); // buffer was cleared
            free(choice);
            return ERROR;
        }
        scanf( "%*[^\n]" ); // buffer was cleared
    } while (make_choice(choice) == ERROR);

    if (make_choice(choice) == INCORRECT) {
        puts("Task entry has been stopped");
        free(choice);
        return INCORRECT;
    }

    free(choice);
    return SUCCESS;
}

int make_choice(char *choice) {
    if ((strlen(choice) == (strlen("No")) && strncmp(choice, "No", 2) == 0)) {
        return INCORRECT;
    }
    if ((strlen(choice) == (strlen("Yes")) && strncmp(choice, "Yes", 3) == 0)) {
        return SUCCESS;
    }
    puts("Invalid data entered, please check again!");
    return ERROR;
}
