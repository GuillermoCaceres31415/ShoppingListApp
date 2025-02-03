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
    unsigned int Totalqty;

    std::list <Observer*>observers;
public:
    List():Totalqty(0){}

    void  addItem (Item &newItem) {
        items.push_back(newItem);
        Totalqty=Totalqty+ newItem.getQty();
        notify();
    }

    void subscribe(Observer*o)override{
        observers.push_back(o);
    }

    void unsubscribe(Observer*o)override{
        observers.remove(o);
    }

    void notify()override{
        for (auto itr=std::begin(observers);itr!=std::end(observers);itr++){
            (*itr)->update();
        }
    }

    const std::list<Item> &getItems() const {
        return items;
    }

    unsigned int getTotalqty() const {
        return Totalqty;
    }

};

#endif //SHOPPINGLISTAPP_LIST_H
