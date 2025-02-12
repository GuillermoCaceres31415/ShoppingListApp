//
// Created by Guillermo on 11/02/25.
//
#include "gtest/gtest.h"
#include "../Account.h"

TEST(Account, ConstructorTest) {
    std::string accountName = "Alice";
    Account account(accountName);

    ASSERT_EQ(account.getName(), "Alice");
    ASSERT_TRUE(account.getMyLists().empty());
}

TEST(Account, AddListTest) {
    std::string accountName = "Bob";
    Account account(accountName);

    std::string listName = "Work Supplies";
    List* workList = new List(listName);
    account.AddList(workList);

    ASSERT_EQ(account.getMyLists().size(), 1);

}
