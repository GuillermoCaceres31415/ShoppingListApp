//
// Created by Guillermo on 03/02/25.
//

#ifndef SHOPPINGLISTAPP_PRINTLIST_H
#define SHOPPINGLISTAPP_PRINTLIST_H
#include "Observer.h"
#include "List.h"
#include <list>
#include "Item.h"


class PrintList :public Observer{
private:
    std::list<Item> items;
    unsigned int Totalqty;
    List *subject;
public:
    explicit PrintList(List *l):subject(l),Totalqty(0){
        subject->subscribe(this);
    }
    ~PrintList() override{
        subject->unsubscribe(this);
    }

    void showList ()const{
        for (auto const & i :items){
            i.showItem();
        }
    }
    virtual void update()override{
        items=subject->getItems();
        Totalqty=subject->getTotalqty();
        showList();
    }






};


#endif //SHOPPINGLISTAPP_PRINTLIST_H
