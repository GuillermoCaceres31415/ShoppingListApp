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

        std::cout<<"    LISTA: "<<(*itr)->getName()<<std::endl;
        (*itr)->showList();
        std::cout << "    [+] per aggiungere un prodotto" << std::endl;
        std::cout << "    [n] per non modificare la lista" << std::endl;
        std::cout << "    Inserire un comando: ";

        std::string com;
        std::cin >> com;

        switch (com[0]) {
            case '+': {
                std::string NameProduct;
                unsigned int qty;
                std::cout << "    inserisci nome prodotto: " ;
                std::cin>>NameProduct;

                std::cout << "    inserire quantità: " ;
                std::cin>>qty;

                Item NewItem(NameProduct,qty,Category::CerealsAndDerivatives);
                (*itr)->addItem(NewItem);
                break;
            }
            case 'n':
            case 'N':
                break;
            default:
                std::cout << "Comando non riconosciuto!" << std::endl;
                break;
        }

    }

    void CreateNewList(PrintList * p){

        std::cout<<"    inserire nome della lista: ";
        std::string nameList;
        std::cin>>nameList;
        List *list=new List(nameList);
        p=new PrintList(list);
        myLists.push_back(list);
    }

    const std::string &getName() const {
        return name;
    }

};


#endif //SHOPPINGLISTAPP_ACCOUNT_H
