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

TEST(TASK_LIST_TEST, increase_list) {
    list* new_list = create_list(DEFAULT_SIZE);

    EXPECT_EQ(new_list->size, DEFAULT_SIZE);
    EXPECT_EQ(increase_list(new_list, DEFAULT_SIZE), SUCCESS);
    EXPECT_EQ(new_list->size, DEFAULT_SIZE * 2);

    EXPECT_EQ(free_list(new_list), SUCCESS);
}

TEST(TASK_TEST, create_task) {
    ptr_task new_task = NULL;
    EXPECT_TRUE(new_task == NULL);

    new_task = create_task();
    EXPECT_FALSE(new_task == NULL);

    EXPECT_EQ(delete_task(new_task), SUCCESS);
}

TEST(TASK_TEST, create_string) {
    char** new_string = NULL;
    EXPECT_TRUE(new_string == NULL);

    new_string = create_string();
    EXPECT_FALSE(new_string == NULL);

    EXPECT_EQ(delete_string(new_string), SUCCESS);
}

TEST(TASK_LIST_TEST, put_elem) {
    ptr_task new_task = create_task();
    list* new_list = create_list(DEFAULT_SIZE);

    strcpy(new_task->number, "1");
    strcpy(new_task->description[0], "hello");
    strcpy(new_task->priority, "2");
    new_task->when->number = 28;
    new_task->when->month = 4;
    new_task->when->year = 2020;

    EXPECT_EQ(put_elem(new_list, new_task), SUCCESS);
    EXPECT_EQ(new_list->insert_pos, 1);
    EXPECT_EQ(atoi(new_list->data[0]->number), 1);
    EXPECT_FALSE(new_list->data[0]->description == NULL);
    EXPECT_EQ(atoi(new_list->data[0]->priority), 2);
    EXPECT_EQ(new_list->data[0]->when->number, 28);
    EXPECT_EQ(new_list->data[0]->when->month, 4);
    EXPECT_EQ(new_list->data[0]->when->year, 2020);

    EXPECT_EQ(free_list(new_list), SUCCESS);
}

TEST(TASK_LIST_TEST, sort_list) {
    list* new_list = create_list(DEFAULT_SIZE);
    ptr_task first_task = create_task();
    ptr_task second_task = create_task();
    ptr_task third_task = create_task();

    strcpy(first_task->number, "1");
    strcpy(first_task->description[0], "hello");
    strcpy(first_task->priority, "2");
    first_task->when->number = 28;
    first_task->when->month = 4;
    first_task->when->year = 2020;

    strcpy(second_task->number, "2");
    strcpy(second_task->description[0], "world");
    strcpy(second_task->priority, "5");
    second_task->when->number = 20;
    second_task->when->month = 4;
    second_task->when->year = 2020;

    strcpy(third_task->number, "3");
    strcpy(third_task->description[0], "!!!");
    strcpy(third_task->priority, "5");
    third_task->when->number = 18;
    third_task->when->month = 4;
    third_task->when->year = 2020;

    put_elem(new_list, first_task);
    put_elem(new_list, second_task);
    put_elem(new_list, third_task);

    EXPECT_FALSE(sort_list(new_list) == NULL);
    EXPECT_EQ(new_list->insert_pos, 3);

    EXPECT_EQ(atoi(new_list->data[0]->number), 3);
    EXPECT_FALSE(new_list->data[0]->description == NULL);
    EXPECT_EQ(atoi(new_list->data[0]->priority), 5);
    EXPECT_EQ(new_list->data[0]->when->number, 18);
    EXPECT_EQ(new_list->data[0]->when->month, 4);
    EXPECT_EQ(new_list->data[0]->when->year, 2020);

    EXPECT_EQ(atoi(new_list->data[1]->number), 2);
    EXPECT_FALSE(new_list->data[1]->description == NULL);
    EXPECT_EQ(atoi(new_list->data[1]->priority), 5);
    EXPECT_EQ(new_list->data[1]->when->number, 20);
    EXPECT_EQ(new_list->data[1]->when->month, 4);
    EXPECT_EQ(new_list->data[1]->when->year, 2020);

    EXPECT_EQ(atoi(new_list->data[2]->number), 1);
    EXPECT_FALSE(new_list->data[2]->description == NULL);
    EXPECT_EQ(atoi(new_list->data[2]->priority), 2);
    EXPECT_EQ(new_list->data[2]->when->number, 28);
    EXPECT_EQ(new_list->data[2]->when->month, 4);
    EXPECT_EQ(new_list->data[2]->when->year, 2020);

    EXPECT_EQ(free_list(new_list), SUCCESS);
}

TEST(TASK_LIST_TEST, print_list) {
    EXPECT_EQ(print_list(NULL), ERROR);

    ptr_task new_task = create_task();
    list* new_list = create_list(DEFAULT_SIZE);

    strcpy(new_task->number, "1");
    strcpy(new_task->description[0], "hello");
    strcpy(new_task->priority, "2");
    new_task->when->number = 28;
    new_task->when->month = 4;
    new_task->when->year = 2020;

    EXPECT_EQ(print_list(new_list), SUCCESS);
    EXPECT_EQ(free_list(new_list), SUCCESS);
}

TEST(TASK_LIST_TEST, business_logic) {
    list* new_list = create_list(DEFAULT_SIZE);
    char** stroka = create_string();
    EXPECT_EQ(business_logic(new_list, NULL), ERROR);
    EXPECT_EQ(business_logic(NULL, stroka), ERROR);
    EXPECT_EQ(delete_string(stroka), SUCCESS);
    EXPECT_EQ(free_list(new_list), SUCCESS);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}