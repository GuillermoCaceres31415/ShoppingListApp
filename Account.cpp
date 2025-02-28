//
// Created by Guillermo on 02/02/25.
//

#include "Account.h"
#include "iostream"

Account::~Account(){
    for (auto list : myLists) {
        delete list;
    }
}

std::string Account::showMyListsToString() const{
    std::string lists;
    if (!myLists.empty()) {
        int num = 0;
        for (const auto itr : myLists) {
            lists += "       ➤ [" + std::to_string(num) + "] " + itr->getName() + "\n";
            num++;
        }
    } else
        lists = "[Non ci sono liste nel tuo account]\n";
    return lists;
}


void Account::createNewList(ListView *& listView,const std::string &nameList) {
    auto list = new List( nameList);
    listView = new ListView(list);
    myLists.push_back(list);
}

void Account::ImportList(List *newList){
    myLists.push_back(newList);
}

List* Account::selectList(const int numSelect)const {
    if (numSelect < 0 || numSelect >= myLists.size())
        throw std::out_of_range("Indice lista non valido.");
    auto list = myLists.begin();
    std::advance(list, numSelect);
    return *list;
}




