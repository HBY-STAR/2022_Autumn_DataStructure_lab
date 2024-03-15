#include "gtest/gtest.h"
#include "Sort.cpp"

class SortTest : public ::testing::Test {

};

TEST_F(SortTest, case01) {
    Sort sort = Sort();
    vector<int> arr = {-5, 1, 4, -2, -1000, 7, 0, 99, 2384};
    sort.insertSort(arr);
    ASSERT_EQ(-1000, arr[0]);
    ASSERT_EQ(-5, arr[1]);
    ASSERT_EQ(-2, arr[2]);
    ASSERT_EQ(0, arr[3]);
    ASSERT_EQ(1, arr[4]);
    ASSERT_EQ(4, arr[5]);
    ASSERT_EQ(7, arr[6]);
    ASSERT_EQ(99, arr[7]);
    ASSERT_EQ(2384, arr[8]);
}

TEST_F(SortTest, case02) {
    Sort sort = Sort();
    vector<int> arr = {-5, 1, 4, -2, -1000, 7, 0, 99, 2384};
    sort.quickSort(arr, 0, arr.size() - 1);
    ASSERT_EQ(-1000, arr[0]);
    ASSERT_EQ(-5, arr[1]);
    ASSERT_EQ(-2, arr[2]);
    ASSERT_EQ(0, arr[3]);
    ASSERT_EQ(1, arr[4]);
    ASSERT_EQ(4, arr[5]);
    ASSERT_EQ(7, arr[6]);
    ASSERT_EQ(99, arr[7]);
    ASSERT_EQ(2384, arr[8]);
}
