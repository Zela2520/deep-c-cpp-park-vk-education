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
    EXPECT_EQ(free_list(new_list), SUCCESS);
}

TEST(TASK_LIST_TEST, creat_list_data) {
    list* new_list = NULL;
    EXPECT_TRUE(new_list == NULL);
    new_list = (list*) calloc(INCREMENT, sizeof(list));
    EXPECT_FALSE(new_list == NULL);
    new_list->data = NULL;
    EXPECT_TRUE(new_list->data == NULL);
    EXPECT_EQ(create_list_data(new_list), SUCCESS);
    EXPECT_FALSE(new_list->data == NULL);
    EXPECT_EQ(free_list(new_list), SUCCESS);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}