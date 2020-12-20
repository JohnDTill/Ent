#ifndef RUNTIME_H
#define RUNTIME_H

#include <string>
#include <unordered_map>
#include <vector>

class Expr;

struct Var{
    bool is_const;
    const std::string name;
    Expr* expr;
    //Something about type

    Var(bool is_const, const std::string& name, Expr* expr)
        : is_const(is_const), name(name), expr(expr){}
};

typedef std::unordered_map<std::string, Var> Scope;
typedef std::vector<Scope> SymbolTable;

struct RedeclareVarException : public std::exception{
public:
    const std::string name;
    RedeclareVarException(const std::string& name)
        : name(name){}
};

struct VarNotFoundException : public std::exception{
public:
    const std::string name;
    VarNotFoundException(const std::string& name)
        : name(name){}
};

struct WriteToConstException : public std::exception{
public:
    const std::string name;
    WriteToConstException(const std::string& name)
        : name(name){}
};

class Runtime{
public:
    SymbolTable symbol_table = std::vector<Scope>(1);

public:
    Runtime();
    void log(const std::string& msg);
    Var& findVar(const std::string& name);
};

#endif // RUNTIME_H
