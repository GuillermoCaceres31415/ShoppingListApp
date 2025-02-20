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
    } else
        lists = "[Non ci sono liste nel tuo account]\n";

    return lists;
}


void Account::CreateNewList(PrintListQty *& p,std::string nameList) {
    List* list = new List(nameList);
    p = new PrintListQty(list);
    myLists.push_back(list);
}

List* Account::SelectList(int NumSelectLs) {
    if (NumSelectLs < 0 || NumSelectLs >= myLists.size())
        throw std::out_of_range("Indice lista non valido.");
    auto list = myLists.begin();
    std::advance(list, NumSelectLs);
    std::cout << std::endl;
    return *list;
}




