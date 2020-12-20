#include "runtime.h"

#include <iostream>

Runtime::Runtime(){

}

void Runtime::log(const std::string& msg){
    std::cout << msg << std::endl;
}

Var& Runtime::findVar(const std::string& name){
    for(SymbolTable::reverse_iterator i = symbol_table.rbegin(); i != symbol_table.rend(); i++){
        Scope& scope = *i;
        auto search_result = scope.find(name);
        if(search_result != scope.end()) return search_result->second;
    }

    throw VarNotFoundException(name);
}
