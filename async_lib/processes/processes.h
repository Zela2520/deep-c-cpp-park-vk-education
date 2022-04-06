#ifndef PROJECT_PROCESSES_PROCESSES_H_
#define PROJECT_PROCESSES_PROCESSES_H_

#include <sys/types.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

#include "../matrix/matrix.h"

double* async_calculate_sum_cols(Matrix* user_matrix);
int async_business_logic();

#endif // PROJECT_PROCESSES_PROCESSES_H_