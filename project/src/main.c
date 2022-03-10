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

    ptr_task user_task_list = (ptr_task)calloc(1, sizeof (task_info));
    if (user_task_list == NULL) {
        perror("Memory allocation error");
    }
    ptr_task temp_task_list = NULL;
    size_t list_size = 1;

    /////////////////////////// добавляем первую задачу ///////////////////////////////////
    if (add_task(user_task_list, create_task(), list_size)) {
        perror("add_task() error");
    }
    ++list_size;
    // увеличиваем емкость списка на единицу
    printf("%s%zu\n", "size of new memory ", list_size * sizeof(task_info));
    temp_task_list = (ptr_task)realloc(user_task_list, list_size * sizeof(task_info));
    if (!(temp_task_list)) {
        perror("Memory allocation error");
        return ERROR;
    }
    user_task_list = temp_task_list;
    temp_task_list = NULL;
    printf("%s %zu\n", "size of list ", sizeof(*user_task_list) / sizeof (task_info)); // отладка
    printf("%s %zu\n", "size of list in bytes", sizeof(*user_task_list)); // отладка

    /////////////////////////// добавили первую задачу////////////////////////////////

    /////////////////////////// добавляем вторую задачу ///////////////////////////////////
    if (add_task(user_task_list, create_task(), list_size)) {
        perror("add_task() error");
    }
    ++list_size;
    // увеличиваем емкость списка на единицу
    printf("%s%zu\n", "size of new memory ", list_size * sizeof(task_info));
    temp_task_list = (ptr_task)realloc(user_task_list, list_size * sizeof(task_info));
    if (!(temp_task_list)) {
        perror("Memory allocation error");
        return ERROR;
    }
    user_task_list = temp_task_list;
    temp_task_list = NULL;
    printf("%s %zu\n", "size of list ", sizeof(*user_task_list) / sizeof (task_info)); // отладка
    printf("%s %zu\n", "size of list in bytes", sizeof(*user_task_list)); // отладка
    /////////////////////////// добавили вторую задачу////////////////////////////////

    ptr_task temp_task = create_task();
    if (temp_task != NULL) {
        print_task(temp_task);
    }

    if (temp_task != NULL) {
        delete_task(temp_task);
        temp_task = NULL;
    }

    if (user_task_list != NULL) {
        print_task_list(user_task_list);
    }

    if (user_task_list != NULL) {
        puts("delete task list was called"); // отладка
        delete_task_list(user_task_list);
        user_task_list = NULL;
    }

    return 0;
}
