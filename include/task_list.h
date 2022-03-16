#ifndef PROJECT_INCLUDE_TASK_LIST_H_
#define PROJECT_INCLUDE_TASK_LIST_H_

#include "task_info.h"

#define INIT_INS_POS 0
#define INCREMENT 1
#define DEFAULT_SIZE 5

typedef struct {
    ptr_task* data;
    size_t size;
    size_t capasity;
    size_t insert_pos;
} list;


list* create_list(const size_t str_len);
int create_list_data(list* cur_list);

int business_logic(list* task_list, const char* input_stream);

int increase_list(list* tasks, const size_t str_len);

int put_elem(list* cur_list, const ptr_task task);
int print_list(const list* tasks);
list* sort_list(list* cur_list);

int delete_tasks(list* tasks);
int free_list(list* tasks);

#endif //  PROJECT_INCLUDE_TASK_LIST_H_
