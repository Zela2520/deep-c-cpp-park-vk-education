#ifndef PROJECT_INCLUDE_TASK_DATA_H_
#define PROJECT_INCLUDE_TASK_DATA_H_

#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef struct {
    size_t number;
    size_t month;
    size_t year;
} data;

typedef data* ptr_data;

ptr_data creat_data(ptr_data when);
ptr_data modify_data(ptr_data when);
char* convert_to_str(ptr_data when);
int delete_data(ptr_data when);

#endif //  PROJECT_INCLUDE_TASK_DATA_H_
