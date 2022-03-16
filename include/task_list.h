#ifndef PROJECT_INCLUDE_TASK_LIST_H_
#define PROJECT_INCLUDE_TASK_LIST_H_

#include "task_info.h"

#define INIT_INS_POS 0
#define INCREMENT 1
#define DEFAULT_SIZE 5

typedef struct {
    ptr_task* data; // динамический массив из указателей на задачи
    size_t size;
    size_t capasity;
    size_t insert_pos;
} list;


list* create_list(const size_t str_len); // протестировано
int create_list_data(list* cur_list); // протестировано

int business_logic(list* task_list, const char* input_stream); // нельзя протестировать, так как вызываются функции использующие стандартный поток ввода

int increase_list(list* tasks, const size_t str_len); // протестировано

int put_elem(list* cur_list, const ptr_task task); // протестировано
int print_list(const list* tasks); // протестировано
list* sort_list(list* cur_list); // протестировано

int delete_tasks(list* tasks); // протестировано
int free_list(list* tasks); // протестировано

#endif //  PROJECT_INCLUDE_TASK_LIST_H_
