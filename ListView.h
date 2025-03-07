//
// Created by Guillermo on 03/02/25.
//

#ifndef SHOPPINGLISTAPP_LISTVIEW_H
#define SHOPPINGLISTAPP_LISTVIEW_H
#include "Observer.h"
#include "List.h"
#include <list>
#include "Item.h"


class ListView : public Observer{
private:
    unsigned int TotalQty;
    List *subject;
public:
    explicit ListView(List *l): subject(l), TotalQty(0){
        subject->subscribe(this);
    }
    ~ListView() override{
        subject->unsubscribe(this);
    }

    void showTotalQty ()const{
        std::cout<<std::endl;
        std::cout << "    " << subject->getName() << "[prodotti tot:" << TotalQty << "]";
        std::cout<<std::endl;
    }

    void update()override{
        TotalQty= subject->getRemainingNum();
        showTotalQty();
    }
};


#endif //SHOPPINGLISTAPP_LISTVIEW_H
