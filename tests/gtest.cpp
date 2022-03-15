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

//TEST(TASK_LIST_TEST, business_logic) {
//    list* new_list = create_list(DEFAULT_SIZE);
//    EXPECT_EQ(business_logic(NULL, "./start_server"), ERROR);
//    EXPECT_EQ(business_logic(new_list, NULL), ERROR);
//    EXPECT_EQ(propose_action(NULL), ERROR);
//    EXPECT_EQ(get_string(NULL), NULL);
//    EXPECT_EQ(get_symbol(NULL), '\0');
//    EXPECT_EQ(make_choice(NULL), ERROR);
//
//    ptr_task new_task = NULL;
//    EXPECT_TRUE(new_task == NULL);
//
//}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}