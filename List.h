//
// Created by Guillermo on 02/02/25.
//

#ifndef SHOPPINGLISTAPP_LIST_H
#define SHOPPINGLISTAPP_LIST_H
#include <list>
#include "Item.h"
#include "Subject.h"
#include "Observer.h"

class List: public Subject{
private:
    std::string name;
    std::vector<Item> items;
    unsigned int TotalItems;
    std::list <Observer*>observers;
public:
    explicit List(std::string n) : name(std::move(n)), TotalItems(0){}

    void addItem (const Item &newItem);

    bool isItemInList(const std::string &itemName) const;

    void setPurchasedAnItem(int index);

    std::string showListToString()const;

    std::string findItemByNameToString(const std::string &itemName);

    std::string showItemsByCategory(const std::string &category) const;

    void subscribe(Observer*o)override;

    void unsubscribe(Observer*o)override;

    void notify()override;

    const std::vector<Item> &getItems() const {
        return items;
    }

    const std::string &getName() const {
        return name;
    }

    unsigned int getTotalItems() const {
        return TotalItems;
    }

};

#endif //SHOPPINGLISTAPP_LIST_H
