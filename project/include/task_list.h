#ifndef PROJECT_INCLUDE_TASK_LIST_H_
#define PROJECT_INCLUDE_TASK_LIST_H_

#include "task_info.h"

typedef struct {
    task_info* task;
    size_t size;
    size_t capasity;
} list;

list* create_list(const size_t str_len);
int increase_list(list* obj, const size_t str_len);
int copy_list(list* left, const list* right, size_t num, size_t begin_copy);
int free_list(list* obj);

#endif //  PROJECT_INCLUDE_TASK_LIST_H_
