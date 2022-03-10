#ifndef PROJECT_INCLUDE_TASK_LIST_H_
#define PROJECT_INCLUDE_TASK_LIST_H_

#include "task_info.h"

typedef ptr_task* ptr_list;

typedef struct {
    ptr_list* data;
    size_t size;
    size_t capasity;
} list;

list* create_list(const size_t str_len);
int increase_list(list* tasks, const size_t str_len);
int copy_list(list* left, const list* right, size_t num, size_t begin_copy);
int free_list(list* tasks);

#endif //  PROJECT_INCLUDE_TASK_LIST_H_
