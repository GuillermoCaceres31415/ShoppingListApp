//
// Created by Guillermo on 02/02/25.
//

#ifndef SHOPPINGLISTAPP_ACCOUNT_H
#define SHOPPINGLISTAPP_ACCOUNT_H
#include <iostream>
#include <memory>
#include "List.h"
#include "PrintList.h"
#include "Item.h"
#include "Category.h"


class Account {
private:
    std::string name;
    std::list<List*> myLists;
public:
    explicit Account(std::string &n):name(n){}

    ~Account() {
        for (auto list : myLists) {
            delete list;
        }
    }

    void AddList(List *newList){
        myLists.push_back(newList);
    }

    bool ShowMyLists();

    static void addProductPrompt(const std::__list_iterator<List *, void *> &itr);

    void SelectList();

    void CreateNewList(PrintList *& p);

    const std::string &getName() const {
        return name;
    }

    const std::list<List *> &getMyLists() const {
        return myLists;
    }
};


#endif //SHOPPINGLISTAPP_ACCOUNT_H
