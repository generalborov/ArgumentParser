#include <iostream>
#include "ArgumentParser.hpp"
 
int main(int argc, char* argv[]) {

    ArgumentParser Parser(argc, argv);
    
    if (Parser.hasErrors()) {
        std::cout << "Ошибки: " << "\n";
        std::cout << Parser.getAllErrorsInfo();
    } std::cout << "\n";

    if (Parser.hasKey("key")) {
        std::cout << "key: " << Parser.getValue("key") << "\n";
    }
    
    
    if (Parser.hasKey("flag")) {
        std::cout << "Вызван флаг!" << "\n";
    }
}