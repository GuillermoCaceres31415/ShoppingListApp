#include <iostream>
#include <map>
#include "ListView.h"
#include "Account.h"


 void UserListsManager(Account &account,std::map<std::string, Account*>& database){
    bool loop= true;
        while (loop) {
            std::cout << R"(
╔════════════════════════════════════╗
║      LISTE DI )" << account.getName() << R"(                ║
╚════════════════════════════════════╝
)";
            std::cout << "**************************************" << std::endl;
            std::string lists = account.showMyListsToString();
            if (lists.empty())
                std::cout << "[non sono presenti liste]\n";
            else
                std::cout << lists;
            std::cout << "**************************************" << std::endl;
            std::cout << std::endl;
            std::cout << "[+] per creare una nuova lista" << std::endl;
            std::cout << "[s] per selezionare una lista" << std::endl;
            std::cout << "[i] per importare una lista altrui" << std::endl;
            std::cout << "[x] per tornare alla home" << std::endl;
            std::cout << "Inserire un comando: ";
            std::string com;
            std::cin >> com;

            switch (com[0]) {
                //add list
                case '+': {
                    ListView *listView;
                    std::cout << "Inserire nome della lista: ";
                    std::string nameList;
                    std::getline(std::cin >> std::ws, nameList);
                    account.createNewList(listView, nameList);
                    break;
                }
                //select a list
                case 's': {
                    if (account.getMyLists().empty())
                        std::cout << "prima aggiungi una lista!" << std::endl;
                    else {
                        int NumSelectLs;
                        std::cout<<"seleziona una lista in base all'indice: ";
                        std::cin >> NumSelectLs;

                        auto list= account.selectList(NumSelectLs);

                        std::cout<<"*********************"<<std::endl;
                        std::cout <<"LISTA: " << list->getName() << std::endl;
                        std::cout << "ITEM ANCORA DA COMPRARE: " << (*list).getRemainingNum() << std::endl;
                        std::cout<<std::endl;


                        std::string listString = list->showListToString();
                        if (listString.empty()) {
                            std::cout << "[la lista è vuota]\n";
                        } else {
                            std::cout << listString;
                        }


                        std::cout<<"*********************"<<std::endl;

                        std::cout << "[+] per aggiungere un prodotto" << std::endl;
                        std::cout << "[e] per segnalare come comprato un prodotto"<<std::endl;
                        std::cout << "[c] per cercare un prodotto"<<std::endl;
                        std::cout << "[s] per selezionare i prodotti di una categoria"<<std::endl;
                        std::cout << "[x] per non modificare la lista" << std::endl;
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
                                (*list).addItem(newItem);

                                break;
                            }
                            case 'e':
                            {
                                int index;
                                std::cout<<"inserire indice del prodotto comprato: ";
                                std::cin>>index;
                                (*list).setPurchasedAnItem(index);
                                break;
                            }
                            case 'c':
                            {
                                std::cout<<"inserire nome item da cercare: ";
                                std::string name;
                                std::cin>>name;
                                std::cout<<std::endl;

                                Item* foundItem=(*list).findItemByName(name);
                                if(!foundItem)
                                    std::cout<<"Item non trovato"<<std::endl;
                                else
                                    std::cout<<foundItem->showItemToString()<<std::endl;
                                break;

                            }
                            case 's':
                            {
                                std::cout<<"inserire categoria: "<<std::endl;
                                std::string category;
                                std::cin>>category;

                                std::string listStringByCategory = list->showItemsByCategoryToString(category);
                                if (listStringByCategory.empty())
                                    std::cout << "[la lista è vuota]\n";
                                else
                                    std::cout << listStringByCategory;
                                break;
                            }
                            case 'x':
                                break;
                            default:
                                std::cout << "Comando non riconosciuto!" << std::endl;
                                break;
                        }


                    }
                    break;
                }
                //import a external
                case 'i': {
                    std::vector<std::pair<std::string, List *>> availableLists;
                    for (const auto &itr1: database) {
                        if (itr1.second->getName() == account.getName())
                            continue;  // Salta l'utente corrente
                        for (auto itr2: itr1.second->getMyLists()) {
                            availableLists.emplace_back(itr1.second->getName(), itr2);
                            std::cout << itr2->getName() << " [da account di " << itr1.second->getName() << "]" << std::endl;
                        }
                    }
                    if (availableLists.empty()) {
                        std::cout << "Errore: non ci sono liste da importare!" << std::endl;
                        break;
                    }
                    std::string importList;
                    std::cout << "inserire nome lista da importare: ";
                    std::cin >> importList;
                    bool listImported = false;
                    for (const auto &pair: availableLists) {
                        if (pair.second->getName() == importList) {
                            account.ImportList(pair.second);
                            listImported = true;
                            std::cout << "Importazione avvenuta con successo!" << std::endl;
                            break;
                        }
                    }
                    if (!listImported)
                        std::cout << "Errore: Lista non trovata!" << std::endl;
                }
                //exit
                case 'x':
                case 'X':
                    loop = false;
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
            std::cout << "inserire un comando: ";
            std::cin >> command;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::runtime_error("Errore: Inserire un valore valido!");
            }

            if (1 > command || command > 3) {
                throw std::out_of_range("comando non valido");
            }

            switch (command) {
                //add new account
                case 1: {
                    std::cout << "scegliere un nome: ";
                    std::string name;
                    std::getline(std::cin >> std::ws, name);
                    auto *account = new Account(name);
                    database[name] = account;
                    UserListsManager(*account,database);
                    break;
                }
                //access to an account
                case 2: {
                    if (!database.empty()) {
                        std::cout << "Account disponibili:\n";
                        for (auto &itr: database)
                            std::cout << "    - " << itr.first << std::endl;

                        std::string setName;
                        std::cout << "Inserire nome di account: ";
                        std::cin >> setName;

                        auto itr = database.find(setName);
                        if (itr != database.end())
                            UserListsManager(*((*itr).second), database);
                        else
                            std::cout << "Errore: Nessun account trovato con il nome \"" << setName << "\"."
                                      << std::endl;
                    } else
                        throw std::runtime_error("Errore: Non sono stati trovati account");
                    break;
                }
                //exit
                case 3: {
                    std::cout << "uscita in corso..." << std::endl;
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
    for (auto &entry : database)
        delete entry.second;
    return 0;
}


