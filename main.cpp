#include <iostream>
#include <map>
#include "Item.h"
#include "Category.h"
#include "List.h"
#include "PrintList.h"
#include "Account.h"

void HandleNewListCreation(Account &account){
    std::cout << "    [+] per creare una nuova lista"<<std::endl;
    std::cout<<"    inserire un comando: ";

    std::string command;
    std::cin>> command;
    if (command=="+") {
        account.CreateNewList();
    }
}

void UserListsManager(Account &account){
    bool loop= true;

    while(loop) {



        std::cout << R"(
    ╔════════════════════════════════════╗
    ║  LISTE DI   )"<<account.getName()<< R"(               ║
    ╚════════════════════════════════════╝
)" ;
        if (account.ShowMyLists()) {
            std::cout << "    [+] per creare una nuova lista"<<std::endl;
            std::cout << "    [s] per selezionare una lista"<<std::endl;
            std::cout<<"    inserire un comando: ";

            std::string com;
            std::cin>> com;
            if (com=="+") {
                account.CreateNewList();
            } else if (com=="s"){
                account.SelectList();
            }


        } else {
            HandleNewListCreation(account);

        }
    }
}

int main() {

    std::map<std::string,Account*> database;

    std::cout << R"(
    ╔════════════════════════════════╗
    ║         MENU PRINCIPALE        ║
    ╠════════════════════════════════╣
    ║ [1]  Crea un nuovo account     ║
    ║ [2]  Mostra tutti gli account  ║
    ║ [3]  Esci                      ║
    ╚════════════════════════════════╝
)" << std::endl;
    int command;
    std::cout<<"    inserire un comando: ";
    std::cin >> command;

    switch (command) {
        //add new account
        case 1: {
            std::cout<<"    scegliere un nome: ";
            std::string name;
            std::cin >> name;
            Account Name(name);
            database.insert(std::pair<std::string,Account*>(name,&Name));
            UserListsManager(Name);
            break;
        }

        case 2: {
            for (auto &itr :database){
                std::cout<<itr.first<<" "<<itr.second<<std::endl;
            }
            break;
        }
        default:
            std::cout << "uscita in corso..." << std::endl;
            break;
    }




    /*

    std::string luca="luca";
    Account Luca(luca);

    std::string marco="marco";
    Account Marco(marco);

    std::map<std::string,Account*> database;

    database.insert(std::pair<std::string,Account*>(luca,&Luca));
    database.insert(std::pair<std::string,Account*>(marco,&Marco));

    for (auto itr:database){
        std::cout<<itr.first<<" "<<itr.second<<std::endl;
    }
*/

    /*
    std::string pane="pane";
    Item obj1(pane,3,Category::CerealsAndDerivatives);

    std::string pollo="pollo";
    Item obj2(pollo,2,Category::MeatAndDerivatives);

    List list;
    PrintList printList(&list);

    list.addItem(obj1);
    list.addItem(obj2);
*/
    return 0;
}
