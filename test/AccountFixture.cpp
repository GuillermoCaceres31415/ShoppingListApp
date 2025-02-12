//
// Created by Guillermo on 11/02/25.
//
#include "gtest/gtest.h"
#include "../Account.h"

class AccountSuite : public ::testing::Test {
protected:
    Account* account;
    List* shoppingList;

    void SetUp() override {
        std::string accountName = "JohnDoe";
        account = new Account(accountName);

        std::string listName = "Groceries";
        shoppingList = new List(listName);
        account->AddList(shoppingList);
    }

    void TearDown() override {
        delete account;
    }
};

TEST_F(AccountSuite, ShowMyListsTest) {
    testing::internal::CaptureStdout();
    account->ShowMyLists();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_FALSE(output.empty());
}

TEST_F(AccountSuite, GetNameTest) {
    ASSERT_EQ(account->getName(), "JohnDoe");
}

TEST_F(AccountSuite, GetListsTest) {
    ASSERT_EQ(account->getMyLists().size(), 1);
}
