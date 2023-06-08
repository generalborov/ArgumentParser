# ArgumentParser

Это простой и легкий парсер аргументов командной строки на С++.

Поддерживаемые типы аргументов и флагов:
* -key=value
* -key=" value "
* -flag

Все невалидные аргументы не учитываются, однако логируются в методе `getAllErrorsInfo()`. 
Проверьте сначала метод `hasErrors()` перед использованием вышеупомянутой функции:

```cpp
ArgumentParser  Parser(argc,  argv);

if  (Parser.hasErrors())  {
	std::cout  <<  "Ошибки: "  <<  "\n";
	std::cout  <<  Parser.getAllErrorsInfo();
}  std::cout  <<  "\n";
```

## Пример использования:

```cpp
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
```
