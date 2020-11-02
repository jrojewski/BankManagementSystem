#include <gtest/gtest.h>

// class BMock : public Tmenu
// {
// public:
//     MOCK_METHOD2(testSum, int(int, int));
// };


TEST(test, test_name){

    int x = 10;
    int y = 20;


    int c = x + y;

    // ASSERT_EQ(c, testSum(x, y));
    ASSERT_TRUE(false);

}

