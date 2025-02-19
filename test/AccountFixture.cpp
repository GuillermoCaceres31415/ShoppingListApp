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
        std::string accountName = "lucas";
        account = new Account(accountName);

        std::string listName = "spesaNatale";
        shoppingList = new List(listName);
        account->AddList(shoppingList);
    }

    void TearDown() override {
        delete account;
    }
};

TEST_F(AccountSuite, ShowMyListsTest) {
    std::string output = account->ShowMyLists();
    ASSERT_FALSE(output.empty());  // Verifica che l'output non sia vuoto
}


TEST_F(AccountSuite, GetNameTest) {
    ASSERT_EQ(account->getName(), "lucas");
}

TEST_F(AccountSuite, GetListsTest) {
    ASSERT_EQ(account->getMyLists().size(), 1);
}
