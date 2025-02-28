//
// Created by Guillermo on 02/02/25.
//

#include "List.h"

bool List::isItemInList(const std::string &itemName) const {
    return std::any_of(items.begin(), items.end(),
                       [&itemName](const Item &item) { return item.getName() == itemName; });
}

void List::addItem(const Item &newItem) {
    if (!isItemInList(newItem.getName())) {
        items.push_back(newItem);
        TotalItems++;
        notify();
    }
}

std::string List::findItemByNameToString(const std::string &itemName) {
    for (auto &item : items) {
        if (item.getName() == itemName) {
            return item.showItemToString();
        }
    }
    return "elemento non trovato\n";
}

void List::setPurchasedAnItem(const int index){
    if (index >= items.size())
        throw std::out_of_range("Indice fuori dal range della lista.");
    auto it = std::next(items.begin(), index);
    it->setPurchased(true);
    TotalItems--;
    notify();
}

std::string List::showListToString ()const {
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

std::string List::showItemsByCategory(const std::string &category) const {
    std::string stringList;
    bool found = false;
    for (const auto &item : items) {
        if (item.getStringCategory() == category) {
            stringList += item.showItemToString() + "\n";
            found = true;
        }
    }
    if (!found)
        return "[Nessun elemento trovato nella categoria '" + category + "']\n";
    return stringList;
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