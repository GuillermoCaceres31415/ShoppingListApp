//
// Created by Guillermo on 11/02/25.
//
#include "gtest/gtest.h"
#include "../List.h"

class ListSuite : public ::testing::Test {
protected:
    List*list;
    Item*item;


    void SetUp() override {
        std::string listName = "spesa";
        list = new List(listName);

        std::string ItemName = "pollo";
        item = new Item (ItemName,20,Category::Dairy);
        list->addItem(*item);
    }

    void TearDown() override {
        delete list;
        delete item;
    }
};



TEST_F(ListSuite, GetNameTest) {
ASSERT_EQ(list->getName(), "spesa");
}

TEST_F(ListSuite, GetListsTest) {
ASSERT_EQ(list->getItems().size(), 1);
}
