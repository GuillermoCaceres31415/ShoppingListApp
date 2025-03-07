#include "gtest/gtest.h"
#include "../Item.h"

class ItemSuite : public ::testing::Test {
protected:
    Item* c;

    void SetUp() override {
        std::string name = "latte";
        int qty = 2;
        c = new Item(name,qty, Category::Dairy);
    }

    void TearDown() override {
        delete c;
    }
};

TEST_F(ItemSuite, ShowItemTest) {
    std::string expectedOutput = "latte 2 Latticini [ ]";
    std::string actualOutput = c->showItemToString();
    ASSERT_EQ(actualOutput, expectedOutput);
}

TEST_F(ItemSuite, GetQtyTest) {
    ASSERT_EQ(c->getQty(), 2);
}


