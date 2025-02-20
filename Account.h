//
// Created by Guillermo on 02/02/25.
//

#ifndef SHOPPINGLISTAPP_ACCOUNT_H
#define SHOPPINGLISTAPP_ACCOUNT_H
#include <iostream>
#include <memory>
#include "List.h"
#include "PrintListQty.h"
#include "Item.h"
#include "Category.h"


class Account {
private:
    std::string name;
    std::list<List*> myLists;
public:
    explicit Account(std::string &n):name(n){}

    ~Account(){
        for (auto list : myLists) {
            delete list;
        }
    }

    bool isMyListsEmpty() const {
        return myLists.empty();
    }

    void AddList(List *newList){
        myLists.push_back(newList);
    }

    std::string ShowMyLists();

    List* SelectList(int numSelect);

    void CreateNewList(PrintListQty *& p,std::string nameList);

    const std::string &getName() const {
        return name;
    }

    const std::list<List *> &getMyLists() const {
        return myLists;
    }
};


#endif //SHOPPINGLISTAPP_ACCOUNT_H
