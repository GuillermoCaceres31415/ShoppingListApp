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
    int qty;
    Category category;
    bool purchased;
public:

    Item (std::string & n,int q,Category c):name(n),qty(q),category(c),purchased(false){
        if (q < 0)
            throw std::invalid_argument("La quantità non può essere negativa");
    }

    std::string getStringCategory()const ;

    std::string showItem() const;

    int getQty() const {
        return qty;
    }

    void setPurchased(bool NewPurchased) {
        Item::purchased = NewPurchased;
    }

    bool isPurchased() const {
        return purchased;
    }



};


#endif //SHOPPINGLISTAPP_ITEM_H
