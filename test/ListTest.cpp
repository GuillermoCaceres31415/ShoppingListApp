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
    std::string listName = "spesa";
    List list(listName);

    std::string itemName0 = "pasta";
    Item* item0 = new Item(itemName0,2,Category::Beverages);
    list.addItem(*item0);

    std::string itemName1 = "salame";
    Item* item1 = new Item(itemName1,20,Category::Beverages);
    list.addItem(*item1);

    std::string itemName2 = "pollo";
    Item* item2 = new Item(itemName2,22,Category::Beverages);
    list.addItem(*item2);

    ASSERT_EQ(list.getItems().size(), 3);
}


TEST(List, SetPurchasedAnItemTest) {
    std::string listName = "spesa";
    List list(listName);

    std::string itemName0 = "pasta";
    Item* item0 = new Item(itemName0,2,Category::Beverages);
    list.addItem(*item0);

    std::string itemName1 = "salame";
    Item* item1 = new Item(itemName1,20,Category::Beverages);
    list.addItem(*item1);

    std::string itemName2 = "pollo";
    Item* item2 = new Item(itemName2,22,Category::Beverages);
    list.addItem(*item2);

    list.setPurchasedAnItem(1);

    ASSERT_FALSE((list.getItems()[0]).isPurchased());
    ASSERT_TRUE((list.getItems()[1]).isPurchased());
    ASSERT_FALSE((list.getItems()[2]).isPurchased());
}
