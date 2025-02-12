//
// Created by Guillermo on 02/02/25.
//

#include "List.h"

void  List::addItem (Item &newItem) {
    items.push_back(newItem);
    TotalQty= TotalQty + newItem.getQty();
    notify();
}

void List::showList ()const {
    if (!items.empty()) {
        for (auto const &i: items)
            i.showItem();
    }else
        std::cout<<"    [la lista è vuota]"<<std::endl;

}

void List::notify(){
    for (auto itr=std::begin(observers);itr!=std::end(observers);itr++)
    (*itr)->update();
}