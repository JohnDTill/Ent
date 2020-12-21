#ifndef FUNCTION_H
#define FUNCTION_H

#include <stmt.h>

class Function : public Expr{
public:
    std::vector<std::string> parameter_names;
    Stmt* stmt;

public:
    Function(const std::vector<std::string>& parameter_names, Stmt* stmt);
    virtual Expr* clone() const{ return new Function(parameter_names, stmt->clone<Stmt>()); }
    virtual void deleteRecursive(){
        stmt->deleteRecursive();
        delete this;
    }
    virtual std::string toString() const{ return "FUNCTION"; }
};

#endif // FUNCTION_H
