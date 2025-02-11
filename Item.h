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

    Item (std::string & n, unsigned int q,Category c):name(n),qty(q),category(c){
    }

    Item(){}

    std::string categoryToString(Category c)const {
        switch (c) {
            case Category::CerealsAndDerivatives: return "Cereali e derivati";
            case Category::Dairy: return "Latticini";
            case Category::FruitsAndVegetables: return "Frutta e verdura";
            case Category::MeatAndFish: return "Carne e pesce";
            case Category::Beverages: return "Bevande";
            default: return "Sconosciuto";
        }
    }



    void showItem() const{
        std::cout<<"    "<<name<<" "<<qty<<" "<<categoryToString(category)<<std::endl;
    }



    const std::string &getName() const {
        return name;
    }

    unsigned int getQty() const {
        return qty;
    }

    Category getCategory() const {
        return category;
    }

};


#endif //SHOPPINGLISTAPP_ITEM_H
