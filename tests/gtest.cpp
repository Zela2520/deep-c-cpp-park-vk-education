#include <gtest/gtest.h>

extern "C" {
    #include "../include/task_info.h"
    #include "../include/task_list.h"
}

TEST(TASK_LIST_TEST, create_list) {
    list* new_list = NULL;
    EXPECT_TRUE(new_list == NULL);
    new_list = create_list(DEFAULT_SIZE);
    EXPECT_FALSE(new_list == NULL);
    free_list(new_list);
    EXPECT_TRUE(new_list == NULL);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}