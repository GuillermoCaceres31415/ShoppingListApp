#include <iostream>
#include <map>
#include "PrintList.h"
#include "Account.h"

void UserListsManager(Account &account){
    bool loop= true;
    while(loop) {
        std::cout << R"(
    ╔════════════════════════════════════╗
    ║  LISTE DI   )"<<account.getName()<< R"(                 ║
    ╚════════════════════════════════════╝
)" ;
            bool Empty = account.ShowMyLists();
            std::cout << "    [+] per creare una nuova lista" << std::endl;
            std::cout << "    [s] per selezionare una lista" << std::endl;
            std::cout << "    [x] per tornare alla home" << std::endl;
            std::cout << "    Inserire un comando: ";

            std::string com;
            std::cin >> com;


            switch (com[0]) {
                case '+':
                    PrintList* printList;
                    account.CreateNewList(printList);
                    break;
                case 's':
                case 'S':
                    {
                        if (!Empty){
                            std::cout<<"    prima aggiungi una lista!"<<std::endl;
                        } else
                            account.SelectList();
                    break;
                    }

                case 'x':
                case 'X':
                    loop= false;
                    break;
                default:
                    std::cout << "Comando non riconosciuto!" << std::endl;
                    break;
            }


    }
}

int main() {

    std::map<std::string,Account*> database;

    bool loop= true;
    while(loop) {

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
        std::cout << "    inserire un comando: ";
        std::cin >> command;

        switch (command) {
            //add new account
            case 1: {
                std::cout << "    scegliere un nome: ";
                std::string name;
                std::cin >> name;
                auto * account=new Account(name);
                database[name] = account;
                UserListsManager(*account);
                break;
            }
            //
            case 2: {
                for (auto &itr: database) {
                    std::cout <<"    "<<itr.first <<" "<< itr.second << std::endl;
                }
                std::string setName;
                std::cout<<"    Inserire nome di account: ";
                std::cin>>setName;
                auto itr =database.find(setName);
                UserListsManager(*((*itr).second));

                break;
            }
            case 3: {
                std::cout << "    uscita in corso..." << std::endl;
                loop= false;
                break;
            }
            default:
                std::cout << "    errore" << std::endl;
                break;
        }
    }




    return 0;
}
