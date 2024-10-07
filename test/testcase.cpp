#include "testcase.h"
#include <gtest/gtest.h>


TEST(Test, getsidebyarea)
{
    ASSERT_TRUE(GetSideByArea() > 0);
}

TEST(Sort, heapsortbymaxheap)
{
    int len = 8;
    int arry[9] = {0,53,17,78,9,45,65,87,32};
    HeapSortUp(arry, len);
    for(int i = 1; i < len; i++)
    {
        ASSERT_TRUE(arry[i] <= arry[i+1]);
    }
}

TEST(Sort, heapsortbyminheap)
{
    int len = 8;
    int arry[9] = {0,53,17,78,9,45,65,87,32};
    HeapSortDown(arry, len);
    for(int i = 1; i < len; i++)
    {
        ASSERT_TRUE(arry[i] >= arry[i+1]);
    }
}

TEST(Sort, insertsort)
{
    int len = 9;
    int arry[9] = {0,53,17,78,9,45,65,87,32};
    HalfInsertSortUp(arry, len);
    for(int i = 1; i < len; i++)
    {
        ASSERT_TRUE(arry[i] <= arry[i+1]);
    }
}

TEST(Sort, quicktsort)
{
    int len = 8;
    int arry[8] = {49,38,65,96,76,13,27,49};
    QuickSort(arry, 0, len-1);
    for(int i = 0; i < len; i++)
    {
        ASSERT_TRUE(arry[i] <= arry[i+1]);
    }
}

TEST(Sort, mergesort)
{
    int len = 8;
    int arry[8] = {49,38,65,96,76,13,27,49};
    MergeSort(arry, 0, len-1);
    for(int i = 0; i < len; i++)
    {
        ASSERT_TRUE(arry[i] <= arry[i+1]);
    }
}
