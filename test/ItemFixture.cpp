#include "gtest/gtest.h"

#include "../Item.h"


class ItemSuite : public ::testing::Test {

protected:
    virtual void SetUp() {

    }

    Item c;
};


TEST_F(ItemSuite, TestMove) {

    c.showItem();
    ASSERT_EQ(22, 22);
    ASSERT_EQ(24, 24);
}

