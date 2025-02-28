//
// Created by Guillermo on 02/02/25.
//

#include "Item.h"


std::string Item::getStringCategory()const {
    switch (category) {
        case Category::CerealsAndDerivatives: return "Cereali";
        case Category::Dairy: return "Latticini";
        case Category::FruitsAndVegetables: return "FruttaEverdura";
        case Category::MeatAndFish: return "Carne";
        case Category::Beverages: return "Bevande";
        default: return "Sconosciuto";
    }
}

std::string Item::showItemToString() const {
    std::string selectedCheck;
    if (purchased)
        selectedCheck = "[x]";
    else
        selectedCheck= "[ ]";
    return name+" "+std::to_string(qty)+" "+getStringCategory()+" "+selectedCheck;
}


