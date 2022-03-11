#ifndef PROJECT_INCLUDE_TASK_LIST_H_
#define PROJECT_INCLUDE_TASK_LIST_H_

#include "task_info.h"

#define DEFAULT_SIZE 5
#define INCREMENT 1
#define INIT_INS_POS 0

typedef struct {
    ptr_task* data; // динамический массив из указателей на задачи
    size_t size;
    size_t capasity;
    size_t insert_pos;
} list;

list* create_list(const size_t str_len); // готово к тесту
int create_list_data(list* cur_list); // готово к тесту
int put_elem(list* cur_list, const task_info* task); // готово к тесту
int increase_list(list* tasks, const size_t str_len); // готово к тесту
int copy_list(list* left, const list* right, size_t num, size_t begin_copy); // готово к тесту
int print_list(const list* tasks); // готово к тесту
int delete_tasks(ptr_task* tasks); // готово к тесту
int free_list(list* tasks); // готово к тесту

#endif //  PROJECT_INCLUDE_TASK_LIST_H_
