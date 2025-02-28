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

TEST(Account, createNewListTest) {
    std::string accountName = "lucas";
    Account account(accountName);

    std::string listName0 = "spesa0";
    auto list0 = new List(listName0);
    auto listView0 = new ListView(list0);

    std::string listName1 = "spesa1";
    auto list1 = new List(listName1);
    auto listView1 = new ListView(list1);

    account.createNewList(listView0,listName0);
    account.createNewList(listView1,listName1);

    ASSERT_EQ(account.getMyLists().size(), 2);
}

TEST(Account, ImportListTest) {
    std::string accountName = "lucas";
    Account account(accountName);

    std::string listName = "spesa";
    List* workList = new List(listName);
    account.ImportList(workList);

    ASSERT_EQ(account.getMyLists().size(), 1);

}

TEST(Account, ImportAndCreateListTest) {
    std::string accountName = "lucas";
    Account account(accountName);

    std::string listName = "spesa";
    List* workList = new List(listName);

    std::string listName0 = "spesa0";
    auto list0 = new List(listName0);
    auto listView0 = new ListView(list0);

    account.ImportList(workList);
    account.createNewList(listView0,listName);

    ASSERT_EQ(account.getMyLists().size(), 2);
}


TEST(Account, SelectListTest) {
    std::string accountName = "lucas";
    Account account(accountName);

    std::string listName0 = "spesaNatale";
    List* list0 = new List(listName0);

    std::string listName1 = "spesa";
    List* list1 = new List(listName1);

    std::string listName2 = "spesaPaste";
    List* list2 = new List(listName2);

    account.ImportList(list0);
    account.ImportList(list1);
    account.ImportList(list2);

    ASSERT_EQ(account.selectList(0), list0);
    ASSERT_EQ(account.selectList(1), list1);
    ASSERT_EQ(account.selectList(2), list2);

}

