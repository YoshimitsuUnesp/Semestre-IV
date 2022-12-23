#include "trie.h"
#include <iostream>

int main()
{
    int op;
    std::string word, prefix;

    Trie t(256);

    do
    {
        std::cout << "| ------------------------------------------ |" << std::endl;
        std::cout << "|                 MAIN MENU                  |" << std::endl;
        std::cout << "| ------------------------------------------ |" << std::endl;
        std::cout << "| 1 - Insert a word                          |" << std::endl;
        std::cout << "| 2 - Search words from a prefix             |" << std::endl;
        std::cout << "| 3 - Exit                                   |" << std::endl;
        std::cout << "| ------------------------------------------ |" << std::endl << std::endl;
        std::cout << "Choose an option:" << std::endl;
        std::cin >> op;
        std::cout << std::endl;
        switch (op)
        {
        case 1:
            std::cout << "Type a word:" << std::endl;
            std::cin >> word;
            t.insert(word);
            std::cout << "The word was inserted!" << std::endl;
            break;
        case 2:
            std::cout << "Type a prefix:" << std::endl;
            std::cin >> prefix;
            t.searchPrefix(prefix);
            break;
        case 3:
            std::cout << "Closing program..." << std::endl;
            return 0;
        default:
            std::cout << "ERROR: invalid option!" << std::endl << std::endl;
            break;
        }
    }while(op != 3);
    return 0;
}
