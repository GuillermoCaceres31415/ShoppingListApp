//
// Created by Guillermo on 02/02/25.
//

#ifndef SHOPPINGLISTAPP_LIST_H
#define SHOPPINGLISTAPP_LIST_H
#include <list>
#include "Item.h"

class List {
private:
    std::list<Item> items;
    unsigned int Totalqty;
public:
    List():Totalqty(0){}


    void  addItem (Item &newItem) {
        items.push_back(newItem);
        Totalqty++;
    }

    void showList ()const{
        for (auto const & i :items){
            i.showItem();
        }
        std::cout << "total items: " <<Totalqty;
    }

};

#endif //SHOPPINGLISTAPP_LIST_H
