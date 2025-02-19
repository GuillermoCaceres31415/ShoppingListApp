//
// Created by Guillermo on 02/02/25.
//

#include "Item.h"


std::string Item::getStringCategory()const {
    switch (category) {
        case Category::CerealsAndDerivatives: return "Cereali e derivati";
        case Category::Dairy: return "Latticini";
        case Category::FruitsAndVegetables: return "Frutta e verdura";
        case Category::MeatAndFish: return "Carne e pesce";
        case Category::Beverages: return "Bevande";
        default: return "Sconosciuto";
    }
}

