//
// Created by Guillermo on 02/02/25.
//

#include "Account.h"

bool Account::ShowMyLists(){
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

void Account::addProductPrompt(const std::__list_iterator<List *, void *> &itr) {
    std::cout << "    [+] per aggiungere un prodotto" << std::endl;
    std::cout << "    [n] per non modificare la lista" << std::endl;
    std::cout << "    Inserire un comando: ";
    std::string command;
    std::cin >> command;
    switch (command[0]) {
        case '+': {
            std::string NameProduct;
            unsigned int qty;
            std::cout << "    inserisci nome prodotto: ";
            std::cin >> NameProduct;

            std::cout << "    inserire quantità: ";
            std::cin >> qty;

            std::vector<std::string> categoryNames = {
                    "CerealsAndDerivatives",
                    "Dairy",
                    "FruitsAndVegetables",
                    "MeatAndFish",
                    "Beverages"
            };
            std::cout << "    Seleziona la categoria:" << std::endl;
            for (size_t i = 0; i < categoryNames.size(); ++i)
                std::cout << "        " << (i + 1) << ") " << categoryNames[i] << std::endl;
            std::cout << "    Inserisci il numero corrispondente alla categoria: ";
            int categoryChoice;
            std::cin >> categoryChoice;
            while (categoryChoice < 1 || categoryChoice > static_cast<int>(categoryNames.size())) {
                std::cout << "    Scelta non valida. Riprova: ";
                std::cin >> categoryChoice;
            }
            auto chosenCategory = static_cast<Category>(categoryChoice - 1);
            Item* newItem = new Item(NameProduct, qty, chosenCategory);
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

void Account::SelectList(){
    unsigned int NumSelectLs;
    std::cout<<"    seleziona una lista in base all'indice: ";
    std::cin >> NumSelectLs;
    if (NumSelectLs >= myLists.size()) {
        throw std::out_of_range("    Indice lista non valido.");
    }
    auto itr=myLists.begin();
    std::advance(itr, NumSelectLs);
    std::cout<<std::endl;
    std::cout<<"    LISTA: "<<(*itr)->getName()<<std::endl;
    (*itr)->showList();
    addProductPrompt(itr);
}

void Account::CreateNewList(PrintList *& p) {
    std::cout << "    Inserire nome della lista: ";
    std::string nameList;
    std::getline(std::cin >> std::ws, nameList);
    List* list = new List(nameList);
    p = new PrintList(list);
    myLists.push_back(list);
}
