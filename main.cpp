#include <iostream>
#include "Item.h"
#include "Category.h"
#include "List.h"


int main() {
    std::string pane="pane";
    Item obj1(pane,3,Category::CerealsAndDerivatives);

    std::string pollo="pollo";
    Item obj2(pollo,2,Category::MeatAndDerivatives);

    List list;
    list.addItem(obj1);
    list.addItem(obj2);

    list.showList();

    return 0;
}
