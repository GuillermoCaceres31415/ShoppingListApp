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

    list.setPurchasedAnItem("salame");

    ASSERT_FALSE(list.findItemByName("pasta")->isPurchased());
    ASSERT_TRUE(list.findItemByName("salame")->isPurchased());
    ASSERT_FALSE(list.findItemByName("pollo")->isPurchased());
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

    list.setPurchasedAnItem("pasta");
    list.setPurchasedAnItem("salame");

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

    ASSERT_EQ(list.showListToString(),"pasta 2 Bevande [ ]\npollo 22 Bevande [ ]\n");
}

TEST(List, ShowItemsByCategoryTest) {
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

    std::vector<Item*> beverages = list.showItemsByCategory("Bevande");

    ASSERT_EQ(beverages.size(), 1);
    ASSERT_EQ(beverages[0]->getStringCategory(), "Bevande");
}
