//
// Created by Guillermo on 02/02/25.
//

#ifndef SHOPPINGLISTAPP_ACCOUNT_H
#define SHOPPINGLISTAPP_ACCOUNT_H
#include <iostream>
#include "list.h"
#include "PrintList.h"
#include "Item.h"
#include "Category.h"

class Account {
private:
    std::string name;
    std::list<List*> myLists;
public:
    explicit Account(std::string &n):name(n){}

    bool ShowMyLists(){
        if (!myLists.empty()) {
            int num = 0;
            for (auto itr: myLists) {
                std::cout <<"            ➤ "<<"["<<num<<"] "<< itr->getName() << std::endl;
                num++;
            }
            return true;
        }else {
            std::cout << "    [Non ci sono liste nel tuo account]"<<std::endl;
            return false;
        }

    }

    void SelectList(){
        unsigned int command;
        std::cout<<"    seleziona una lista in base all'indice: ";
        std::cin >>command;

        auto itr=myLists.begin();
        std::advance(itr,command);

        (*itr)->showList();




    }

    void CreateNewList(){
        std::string pane="pane";
        Item obj1(pane,3,Category::CerealsAndDerivatives);

        std::string pollo="pollo";
        Item obj2(pollo,2,Category::MeatAndDerivatives);


        std::cout<<"    inserire nome della lista: ";
        std::string nameList;
        std::cin>>nameList;
        List *list=new List(nameList);

        list->addItem(obj1);
        list->addItem(obj2);
        myLists.push_back(list);
    }

    const std::string &getName() const {
        return name;
    }

};


#endif //SHOPPINGLISTAPP_ACCOUNT_H
