#include "runtime.h"

#include <iostream>
#include "expr.h"

Runtime::Runtime(){}

Runtime::~Runtime(){
    removeScope();
    assert(symbol_table.empty());

    #ifndef ENT_DISABLE_SERIAL_ASSERTIONS
    assert(Expr::all_exprs.empty());
    #endif
}

void Runtime::log(const std::string& msg){
    std::cout << msg << std::endl;
}

void Runtime::addScope(){
    symbol_table.push_back(Scope());
}

void Runtime::removeScope(){
    assert(symbol_table.size());
    Scope& scope = symbol_table.back();
    for(Scope::iterator it = scope.begin(); it != scope.end(); it++)
        it->second.expr->deleteRecursive();
    symbol_table.pop_back();
}

Var& Runtime::findVar(const std::string& name){
    for(SymbolTable::reverse_iterator i = symbol_table.rbegin(); i != symbol_table.rend(); i++){
        Scope& scope = *i;
        auto search_result = scope.find(name);
        if(search_result != scope.end()) return search_result->second;
    }

    throw VarNotFoundException(name);
}

void Runtime::assignVar(bool is_const, const std::string& name, Expr* rhs){
    Scope& scope = symbol_table.back();
    if(scope.find(name) != scope.end()) throw RedeclareVarException(name);
    scope.insert({name, Var(is_const, name, rhs)});
}
