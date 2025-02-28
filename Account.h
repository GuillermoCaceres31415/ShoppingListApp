//
// Created by Guillermo on 02/02/25.
//

#ifndef SHOPPINGLISTAPP_ACCOUNT_H
#define SHOPPINGLISTAPP_ACCOUNT_H
#include <iostream>
#include <memory>
#include <utility>
#include "List.h"
#include "ListView.h"
#include "Item.h"
#include "Category.h"


class Account {
private:
    std::string name;
    std::vector<List*> myLists;
public:
    explicit Account(std::string n):name(std::move(n)){}

    ~Account();

    void createNewList(ListView *& listView, const std::string &nameList);

    void ImportList(List *newList);

    std::string showMyListsToString()const;

    List* selectList(int numSelect)const;

    const std::string &getName() const {
        return name;
    }

    const std::vector<List *> &getMyLists() const {
        return myLists;
    }
};


#endif //SHOPPINGLISTAPP_ACCOUNT_H
