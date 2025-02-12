//
// Created by Guillermo on 02/02/25.
//

#ifndef SHOPPINGLISTAPP_ITEM_H
#define SHOPPINGLISTAPP_ITEM_H
#include <iostream>
#include "Category.h"


class Item {
private:
    std::string name;
    unsigned int qty;
    Category category;
public:

    Item (std::string & n, unsigned int q,Category c):name(n),qty(q),category(c){}

    std::string getStringCategory()const ;

    void showItem() const{
        std::cout<<"    "<<name<<" "<<qty<<" "<<getStringCategory()<<std::endl;
    }

    unsigned int getQty() const {
        return qty;
    }

};


#endif //SHOPPINGLISTAPP_ITEM_H
