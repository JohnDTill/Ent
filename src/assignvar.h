#ifndef ASSIGNVAR_H
#define ASSIGNVAR_H

#include "stmt.h"

class AssignVar : public Stmt{
public:
    const bool is_const;
    const std::string name;
    Expr* rhs;

public:
    AssignVar(bool is_const, const std::string& name, Expr* rhs);
    virtual void exec(Runtime& runtime) override;
    virtual Expr* clone() const override { return new AssignVar(is_const, name, rhs->clone()); }
    virtual void deleteRecursive() override{
        rhs->deleteRecursive();
        delete this;
    }
    virtual std::string toString() const override { return "AssignVar(" + std::string(is_const ? "T" : "F") + ", " + name + ", " + rhs->toString() + ")"; }
};

#endif // ASSIGNVAR_H
