//
// Created by Guillermo on 11/02/25.
//
#include "gtest/gtest.h"
#include "../List.h"

TEST(List, ConstructorTest) {
    std::string listName = "spesaNatale";
    List list(listName);

    ASSERT_EQ(list.getName(), "spesaNatale");
    ASSERT_TRUE(list.getItems().empty());
}

TEST(List, AddListTest) {
    std::string listName = "spesaNatale";
    List list(listName);

    std::string itemName = "pasta";
    Item* item = new Item(itemName,20,Category::Beverages);
    list.addItem(*item);

    ASSERT_EQ(list.getItems().size(), 1);

}