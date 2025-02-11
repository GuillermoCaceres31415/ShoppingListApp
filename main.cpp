#include <iostream>
#include <map>
#include "PrintList.h"
#include "Account.h"


void UserListsManager(Account &account,std::map<std::string, Account*>& database){
    bool loop= true;
    while(loop) {
        std::cout << R"(
    ╔════════════════════════════════════╗
    ║      LISTE DI )"<<account.getName()<< R"(                 ║
    ╚════════════════════════════════════╝
)" ;        std::cout<<"    **************************************"<<std::endl;
            bool Empty = account.ShowMyLists();
            std::cout<<"    **************************************"<<std::endl;
            std::cout<<std::endl;
            std::cout << "    [+] per creare una nuova lista" << std::endl;
            std::cout << "    [s] per selezionare una lista" << std::endl;
            std::cout << "    [i] per importare una lista altrui" << std::endl;
            std::cout << "    [x] per tornare alla home" << std::endl;
            std::cout << "    Inserire un comando: ";
            std::string com;
            std::cin >> com;


            switch (com[0]) {
                case '+':
                    PrintList *printList;
                    account.CreateNewList(printList);
                    break;
                case 's':
                {
                    if (!Empty)
                        std::cout << "    prima aggiungi una lista!" << std::endl;
                    else
                        account.SelectList();
                    break;
                }
                case 'i':
                 {
                    std::vector<std::pair<std::string, List *>> availableLists;
                    for (const auto &itr1: database) {
                        for (auto itr2: itr1.second->getMyLists()) {
                            availableLists.emplace_back(itr1.second->getName(), itr2);
                            std::cout << "    " << itr2->getName() << " [da account di " << itr1.second->getName()
                                      << "]" << std::endl;
                        }
                    }

                    if (availableLists.empty()) {
                        std::cout << "    Errore: non ci sono liste da importare!" << std::endl;
                        break;
                    }

                    std::string importList;
                    std::cout << "    inserire nome lista da importare: ";
                    std::cin >> importList;

                    for (const auto &pair: availableLists) {
                        if (pair.second->getName() == importList) {
                            account.AddList(pair.second);
                            break;
                        }
                    }
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
    ║ [2]  Accedi al to account      ║
    ║ [3]  Esci                      ║
    ╚════════════════════════════════╝
)" << std::endl;
        try {
            int command;
            std::cout << "    inserire un comando: ";
            std::cin >> command;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::runtime_error("    Errore: Inserire un valore valido!");
            }

            if (1 > command || command > 3) {
                throw std::out_of_range("    comando non valido");
            }

            switch (command) {
                //add new account
                case 1: {
                    std::cout << "    scegliere un nome: ";
                    std::string name;
                    std::getline(std::cin >> std::ws, name);
                    auto *account = new Account(name);
                    database[name] = account;
                    UserListsManager(*account, database);
                    break;
                }
                    //
                case 2: {
                    if (!database.empty()) {
                        std::cout << "    Account disponibili:\n";
                        for (auto &itr: database)
                            std::cout << "    - " << itr.first << std::endl;

                        std::string setName;
                        std::cout << "    Inserire nome di account: ";
                        std::cin >> setName;

                        auto itr = database.find(setName);
                        if (itr != database.end())
                            UserListsManager(*((*itr).second), database);
                        else
                            std::cout << "    Errore: Nessun account trovato con il nome \"" << setName << "\"."
                                      << std::endl;
                    } else
                        throw std::runtime_error("    Errore: Non sono stati trovati account");
                    break;
                }
                case 3: {
                    std::cout << "    uscita in corso..." << std::endl;
                    loop = false;
                    break;
                }
                default:
                    std::cout << "Comando non riconosciuto!" << std::endl;
                    break;
            }
        }catch (std::out_of_range &e){
            std::cout<<e.what()<<std::endl;
        }catch (std::runtime_error &e){
            std::cout<<e.what()<<std::endl;
        }
    }
    return 0;
}


