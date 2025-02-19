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
    std::list<Item> items;
    unsigned int TotalItems;
    std::list <Observer*>observers;
public:
    explicit List(std::string& n): name(n), TotalItems(0){}

    void  addItem (Item &newItem);

    void setPurchasedLastItem();

    std::string getStringList ()const ;

    void subscribe(Observer*o)override{
        observers.push_back(o);
    }

    void unsubscribe(Observer*o)override{
        observers.remove(o);
    }

    void notify()override;

    const std::list<Item> &getItems() const {
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
