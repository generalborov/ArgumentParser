/*

    Copyright (C) <2023> <Argo>
    
    This program is free software: 
    you can redistribute it and/or modify it under the terms of the GNU General Public License 
    as published by the Free Software Foundation, either version 3 of the License, 
    or (at your option) any later version.
    This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
    without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
    See the GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along with this program. 
    If not, see <https://www.gnu.org/licenses/>. 

*/

#pragma once

#include <string>
#include <map>

class ArgumentParser {
public:
    ArgumentParser(int argc, char* argv[]) {
        
        for (int i = 1; i < argc; i++) {
            std::string token = argv[i];
            
            // Аргументы/флаги с "-"
            if (token.substr(0, 1) == "-") {                
                auto pos = token.find("=");
                
                // Если аргумент
                if (pos != std::string::npos) {
                    // название ключа - это между "-" и "="
                    std::string key = token.substr(1, pos - 1);
                    
                    // Если нету value для аргумента
                    if (pos + 1 == token.size()) {
                       errors += "Отсутствует значения у опции \"";
                       errors += "-" + key;
                       errors += "\"\n";
                    }
                    
                    else {
                        // значение ключа - это от "=" и до конца.
                        std::string value = token.substr(pos + 1, token.size() - pos);
                        
                        // Считывает только самый первый аргумент, повторы не переписываем
                        if (tokens.count(key) == 0) {
                            tokens[key] = value;
                        }
                    }
                    
                }
                
                // Если флаг
                if (pos == std::string::npos) {
                    
                    // Название флага - это от "-"
                    std::string name_of_flag = token.substr(1);
                    
                    if (name_of_flag.empty()) {
                        errors += "Неправильный флаг \"";
                        errors += token;
                        errors += "\"\n";
                    }
                    
                    else {
                        if (tokens.count(name_of_flag) == 0) {
                            tokens[name_of_flag] = "TRUE";
                        }
                    }
                }
            }
        }
        
        if (!errors.empty()) {
            has_errors = true;
        }
        
    };
    
    std::string getAllErrorsInfo() const {
        return this->errors;
    }
    
    std::string getValue(const std::string& key) const {
        if (tokens.count(key)) {
            return tokens.at(key);
        }
        return "";
    }
    
    bool hasErrors() const {
        return has_errors;
    }
    
    bool hasKey(const std::string& key) const {
        return tokens.count(key) > 0;
    }

private:
    std::map<std::string, std::string> tokens;
    std::string errors;
    bool has_errors;
};