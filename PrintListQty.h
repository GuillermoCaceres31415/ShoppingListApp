//
// Created by Guillermo on 03/02/25.
//

#ifndef SHOPPINGLISTAPP_PRINTLISTQTY_H
#define SHOPPINGLISTAPP_PRINTLISTQTY_H
#include "Observer.h"
#include "List.h"
#include <list>
#include "Item.h"


class PrintListQty : public Observer{
private:
    unsigned int TotalQty;
    List *subject;
public:
    explicit PrintListQty(List *l): subject(l), TotalQty(0){
        subject->subscribe(this);
    }
    ~PrintListQty() override{
        subject->unsubscribe(this);
    }

    void showTotalQty ()const{
        std::cout<<std::endl;
        std::cout << "    " << subject->getName() << "[prodotti tot:" << TotalQty << "]";
        std::cout<<std::endl;

    }

    void update()override{
        TotalQty=subject->getTotalqty();
        showTotalQty();
    }
};


#endif //SHOPPINGLISTAPP_PRINTLISTQTY_H
