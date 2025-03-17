//
// Created by Guillermo on 02/02/25.
//

#ifndef SHOPPINGLISTAPP_LIST_H
#define SHOPPINGLISTAPP_LIST_H
#include <list>
#include <map>
#include "Item.h"
#include "Subject.h"
#include "Observer.h"

class List: public Subject{
private:
    std::string name;
    std::map<std::string,Item*> items;
    unsigned int remainingItems;
    std::list <Observer*>observers;
    bool isItemInList(const std::string &itemName) const;
public:
    explicit List(std::string n) : name(std::move(n)), remainingItems(0){}

    void addItem (const Item &newItem);

    void setPurchasedAnItem(const std::string &itemName);

    std::string showListToString()const;

    Item* findItemByName(const std::string &itemName)const;

    std::vector<Item*> showItemsByCategory(const std::string &category) const ;

    void subscribe(Observer*o)override;

    void unsubscribe(Observer*o)override;

    void notify()override;

    const std::map<std::string, Item *> &getItems() const {
        return items;
    }

    const std::string &getName() const {
        return name;
    }

    unsigned int getRemainingNum() const {
        return remainingItems;
    }

};

#endif //SHOPPINGLISTAPP_LIST_H
