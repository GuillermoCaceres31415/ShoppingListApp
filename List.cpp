//
// Created by Guillermo on 02/02/25.
//

#include "List.h"

void  List::addItem (Item &newItem) {
    items.push_back(newItem);
    TotalItems++;
    notify();
}

void List::setPurchasedLastItem(){
    for (auto& item : items) {
        if (!item.isPurchased()) {
            item.setPurchased(true);
            TotalItems--;
            notify();
            return;
        }
    }
}

std::string List::getStringList ()const {
    std::string stringList;
    if (!items.empty()) {
        for (auto const &i: items)
            stringList+=(i.showItem()+"\n");
        return stringList;
    }else {
        return "[la lista è vuota]\n";
    }
}

void List::notify(){
    for (auto itr=std::begin(observers);itr!=std::end(observers);itr++)
    (*itr)->update();
}