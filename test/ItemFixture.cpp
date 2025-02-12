#include "gtest/gtest.h"
#include "../Item.h"

class ItemSuite : public ::testing::Test {
protected:
    Item* c;

    void SetUp() override {
        std::string name = "latte";
        unsigned int qty = 2;
        c = new Item(name, qty, Category::Dairy);
    }

    void TearDown() override {
        delete c;
    }
};

TEST_F(ItemSuite, ShowItemTest) {
    testing::internal::CaptureStdout();
    c->showItem();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_FALSE(output.empty());
}

TEST_F(ItemSuite, GetQtyTest) {
    ASSERT_EQ(c->getQty(), 2);
}


