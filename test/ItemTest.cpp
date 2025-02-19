#include "gtest/gtest.h"
#include "../Item.h"

TEST(Item, ConstructorTest) {
    std::string name = "Pane";
    int qty = 3;
    Item c(name, qty, Category::CerealsAndDerivatives);

    ASSERT_EQ(c.getQty(), 3);
}

TEST(Item, GetStringCategoryTest) {
    std::string name = "Mela";
    int qty = 5;
    Item c(name, qty, Category::FruitsAndVegetables);

    ASSERT_EQ(c.getStringCategory(), "Frutta e verdura");
}

TEST(Item,NegativeQuantityTest){
    std::string name="latte";
    int qty=-1;
    ASSERT_THROW(Item c(name,qty,Category::Dairy),std::invalid_argument);
}







