//
// Created by Guillermo on 02/02/25.
//

#include "List.h"

void  List::addItem (const Item &newItem) {
    items.push_back(newItem);
    TotalItems++;
    notify();
}

void List::setPurchasedAnItem(const int index){
    if (index >= items.size())
        throw std::out_of_range("Indice fuori dal range della lista.");
    auto it = std::next(items.begin(), index);
    it->setPurchased(true);
    TotalItems--;
    notify();
}

const std::string List::showListToString ()const {
    std::string stringList;
    if (!items.empty()) {
        int index=0;
        for (auto const &i: items) {
            stringList += "[" + std::to_string(index) + "] " + (i.showItemToString() + "\n");
            index++;
        }
        return stringList;
    }else {
        return "[la lista è vuota]\n";
    }
}

void List::notify(){
    for (auto itr=std::begin(observers);itr!=std::end(observers);itr++)
    (*itr)->update();
}

void List::subscribe(Observer*o){
    observers.push_back(o);
}

void List::unsubscribe(Observer*o){
observers.remove(o);
}