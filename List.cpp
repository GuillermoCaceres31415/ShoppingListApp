//
// Created by Guillermo on 02/02/25.
//

#include "List.h"

bool List::isItemInList(const std::string &itemName) const {
    return items.find(itemName) != items.end();
}

void List::addItem(const Item &newItem) {
    const std::string &itemName = newItem.getName();

    if (!isItemInList(itemName)) {
        Item* newItemCopy = new Item(newItem);
        items[itemName] = newItemCopy;
        remainingItems++;
        notify();
    } else
        throw std::runtime_error("Errore: l'elemento '" + itemName + "' è già presente nella lista.");
}

Item* List::findItemByName(const std::string &itemName) const {
    auto it = items.find(itemName);
    return (it != items.end()) ? it->second : nullptr;
}


void List::setPurchasedAnItem(const std::string &itemName) {
    auto it = items.find(itemName);
    if (it == items.end())
        throw std::out_of_range("L'elemento '" + itemName + "' non è presente nella lista.");
    else {
        it->second->setPurchased(true);
        remainingItems--;
        notify();
    }
}


std::string List::showListToString() const {
    std::string stringList;
    if (!items.empty()) {
        for (const auto &pair: items)
            stringList += pair.second->showItemToString() + "\n";
    }
    return stringList;
}


std::vector<Item *> List::showItemsByCategory(const std::string &category) const {
    std::vector<Item *> filteredItems;
    for (const auto &pair: items) {
        if (pair.second->getStringCategory() == category)
                filteredItems.push_back(pair.second);
    }
        return filteredItems;
}

void List::notify() {
    for (auto itr = std::begin(observers); itr != std::end(observers); itr++)
        (*itr)->update();
}

void List::subscribe(Observer *o) {
    observers.push_back(o);
}

void List::unsubscribe(Observer *o) {
    observers.remove(o);
}

