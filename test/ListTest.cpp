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

    ASSERT_FALSE((list.getItems()[0])->isPurchased());
    ASSERT_TRUE((list.getItems()[1])->isPurchased());
    ASSERT_FALSE((list.getItems()[2])->isPurchased());
}

TEST(List, RemainingItemsTest) {
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
    list.setPurchasedAnItem(2);

    ASSERT_EQ(list.getRemainingNum(),1);
}


TEST(List, FindItemTest) {
    std::string listName = "spesa";
    List list(listName);

    std::string itemName0 = "pasta";
    Item* item0 = new Item(itemName0,2,Category::Beverages);
    list.addItem(*item0);

    std::string fakeItem="verdure";

    ASSERT_EQ(*list.findItemByName(itemName0),*item0);
    ASSERT_EQ(list.findItemByName(fakeItem), nullptr);
}

TEST(List, ShowListToStringTest) {
    std::string listName = "spesa";
    List list(listName);

    std::string itemName0 = "pasta";
    Item* item0 = new Item(itemName0,2,Category::Beverages);
    list.addItem(*item0);

    std::string itemName2 = "pollo";
    Item* item2 = new Item(itemName2,22,Category::Beverages);
    list.addItem(*item2);

    ASSERT_EQ(list.showListToString(),"[0] pasta 2 Bevande [ ]\n[1] pollo 22 Bevande [ ]\n");
}

TEST(List, ShowItemsByCategoryToStringTest) {
    std::string listName = "spesa";
    List list(listName);

    std::string itemName0 = "limonata";
    Item* item0 = new Item(itemName0,2,Category::Beverages);
    list.addItem(*item0);

    std::string itemName2 = "pollo";
    Item* item2 = new Item(itemName2,22,Category::MeatAndFish);
    list.addItem(*item2);

    std::string itemName3 = "pesce";
    Item* item3 = new Item(itemName3,23,Category::MeatAndFish);
    list.addItem(*item3);

    ASSERT_EQ(list.showItemsByCategoryToString("Bevande"),"limonata 2 Bevande [ ]\n");
}
