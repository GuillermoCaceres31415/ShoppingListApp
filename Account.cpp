//
// Created by Guillermo on 02/02/25.
//

#include "Account.h"

std::string Account::ShowMyLists() {
    std::string lists;
    if (!myLists.empty()) {
        int num = 0;
        for (auto itr : myLists) {
            lists += "       ➤ [" + std::to_string(num) + "] " + itr->getName() + "\n";
            num++;
        }
    } else {
        lists = "[Non ci sono liste nel tuo account]\n";
    }
    return lists;
}


void Account::CreateNewList(PrintListQty *& p,std::string nameList) {
    List* list = new List(nameList);
    p = new PrintListQty(list);
    myLists.push_back(list);
}

void Account::SelectList( int NumSelectLs){
    if (NumSelectLs < 0 || NumSelectLs >= myLists.size())
        throw std::out_of_range("Indice lista non valido.");
    auto list=myLists.begin();
    std::advance(list, NumSelectLs);
    std::cout<<std::endl;
    ShowAList(list);
}

void Account::ShowAList(const std::__list_iterator<List *, void *> &list){
    std::cout<<"*********************"<<std::endl;
    std::cout <<"LISTA: " << (*list)->getName() << std::endl;
    std::cout<<"ITEM ANCORA DA COMPRARE: "<<(*list)->getTotalItems()<<std::endl;
    std::cout<<std::endl;
    std::cout<< (*list)->getStringList();
    std::cout<<"*********************"<<std::endl;
    addProductPrompt(list);
}


void Account::addProductPrompt(const std::__list_iterator<List *, void *> &list) {
    std::cout << "[+] per aggiungere un prodotto" << std::endl;
    std::cout << "[e] per segnalare come comprato l'ultimo prodotto"<<std::endl;
    std::cout << "[n] per non modificare la lista" << std::endl;
    std::cout << "Inserire un comando: ";
    std::string command;
    std::cin >> command;
    switch (command[0]) {
        case '+': {
            std::string NameProduct;
            int qty;
            std::cout << "inserisci nome prodotto: ";
            std::cin >> NameProduct;

            std::cout << "inserire quantità: ";
            std::cin >> qty;

            std::vector<std::string> categoryNames = {
                    "CerealsAndDerivatives",
                    "Dairy",
                    "FruitsAndVegetables",
                    "MeatAndFish",
                    "Beverages"
            };
            std::cout << "Seleziona la categoria:" << std::endl;
            for (size_t i = 0; i < categoryNames.size(); ++i)
                std::cout << "   " << (i + 1) << ") " << categoryNames[i] << std::endl;
            std::cout << "Inserisci il numero corrispondente alla categoria: ";
            int categoryChoice;
            std::cin >> categoryChoice;
            while (categoryChoice < 1 || categoryChoice > static_cast<int>(categoryNames.size())) {
                std::cout << "Scelta non valida. Riprova: ";
                std::cin >> categoryChoice;
            }
            auto chosenCategory = static_cast<Category>(categoryChoice - 1);
            Item newItem (NameProduct, qty, chosenCategory);
            (*list)->addItem(newItem);

            break;
        }
        case 'e':
        {
            (*list)->setPurchasedLastItem();
            break;
        }
        case 'n':
            break;
        default:
            std::cout << "Comando non riconosciuto!" << std::endl;
            break;
    }
}


