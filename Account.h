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
#include <memory>

class Account {
private:
    std::string name;
    std::list<List*> myLists;
public:
    explicit Account(std::string &n):name(n){}

    void AddList(List *newList){
        myLists.push_back(newList);

    }
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

                Item* newItem = new Item(NameProduct, qty, Category::CerealsAndDerivatives);
                (*itr)->addItem(*newItem);
                delete newItem;
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

    void CreateNewList(PrintList *& p) {  // Passaggio per riferimento
        std::cout << "    Inserire nome della lista: ";
        std::string nameList;
        std::getline(std::cin >> std::ws, nameList);  // Per leggere spazi

        List* list = new List(nameList);  // Allocazione dinamica
        p = new PrintList(list);  // Evita di perdere il vecchio puntatore

        myLists.push_back(list);  // Memorizza la lista nel vettore
    }

    const std::string &getName() const {
        return name;
    }

    const std::list<List *> &getMyLists() const {
        return myLists;
    }
};


#endif //SHOPPINGLISTAPP_ACCOUNT_H
