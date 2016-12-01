#include "four_tasks_lib.h"
#include "gtest.h"

TEST(FourTasks, can_reverse_number)
{
    int num = -12132, revNum = -23121;
    EXPECT_EQ(revNum, revInt(num));
}

TEST(FourTasks, can_find_prefix)
{
    vector<string> v;
    v.push_back("abab");
    v.push_back("abasc");
    v.push_back("aacd");
    EXPECT_EQ(prefixOfDict(v), string("a"));
}

TEST(FourTasks, can_reverse_pairs_inside_list)
{
    list<int> simple, reversedSimple;
    for(int i = 1; i <= 4; i++)
        simple.push_back(i);
    reversedSimple.push_back(2);
    reversedSimple.push_back(1);
    reversedSimple.push_back(4);
    reversedSimple.push_back(3);
    EXPECT_EQ(reversePairs(simple), reversedSimple);
}
TEST(FourTasks, cant_reverse_pairs_inside_list_if_size_not_even)
{
    list<int> l;
    for(int i = 1; i <= 5; i++)
        l.push_back(i);
    ASSERT_ANY_THROW(reversePairs(l));
}

TEST(FourTasks, can_calculate_quantity_of_sums)
{
    const int arrSize = 7, sum = 3;
    int arr[] = {0, 2, 1, 3, 5, -2, 8};
    vector<int> v;
    for(int i = 0; i < arrSize; i++)
        v.push_back(arr[i]);
    EXPECT_EQ(quantityOfSums(v, sum), sum);
}
